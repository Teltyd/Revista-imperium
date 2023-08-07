#include <Pixy2.h>
#include <Servo.h>
#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3
#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5
#define SERVO_PIN 6

#define LEFT_TRIG_PIN 11
#define LEFT_ECHO_PIN 12

#define RIGHT_TRIG_PIN 8
#define RIGHT_ECHO_PIN 7

Pixy2 pixy;
Servo servoMotor;

const int obstacleThreshold = 20;  // Distancia en centímetros para detectar un obstáculo cercano
const int turnDuration = 500;      // Duración del giro en milisegundos

enum RobotState {
  FORWARD,
  AVOID_OBSTACLE,
};

RobotState robotState = FORWARD;
unsigned long lastStateChangeTime = 0;

void setup() {
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

  pinMode(LEFT_TRIG_PIN, OUTPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);

  pinMode(RIGHT_TRIG_PIN, OUTPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);

  Serial.begin(9600);

  servoMotor.attach(6);
  pixy.init();
  pixy.setLamp(1,0);
  
}

// Función para controlar los motores del robot
  void controlMotors(int pin1, int pin2, int speed) {
    digitalWrite(pin1, speed > 0 ? LOW : HIGH);
    digitalWrite(pin2, speed > 0 ? HIGH : LOW);
    analogWrite(abs(100), pin1);
  }

  // Función para medir la distancia con el sensor ultrasónico
  float measureDistance(int triggerPin, int echoPin) {
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    return pulseIn(echoPin, HIGH) / 58.2; // Distancia en centímetros
  }

void loop() {
  // Actualizar estado del robot
  switch (robotState) {
    case FORWARD:
      // Controlar los motores para que el robot avance
      controlMotors(MOTOR1_PIN1, MOTOR1_PIN2, -200);
      controlMotors(MOTOR2_PIN1, MOTOR2_PIN2, -200);

      // Medir distancia izquierda
      float distanceLeft = measureDistance(LEFT_TRIG_PIN, LEFT_ECHO_PIN);

      // Medir distancia derecha
      float distanceRight = measureDistance(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN);

      // Verificar si hay un obstáculo cercano en cualquier lado
      if (distanceLeft < obstacleThreshold || distanceRight < obstacleThreshold) {
        robotState = AVOID_OBSTACLE;
        lastStateChangeTime = millis();
      }
      break;

    case AVOID_OBSTACLE:
      // Girar hacia la izquierda para evitar el obstáculo
      controlMotors(MOTOR1_PIN1, MOTOR1_PIN2, -100);
      controlMotors(MOTOR2_PIN1, MOTOR2_PIN2, 100);

      // Esperar hasta que se cumpla el tiempo de giro
      if (millis() - lastStateChangeTime >= turnDuration) {
        robotState = FORWARD;
      }
      break;
  }

  // Detección de bloques con Pixy2
 int numBlocks = pixy.ccc.getBlocks();
 Serial.println(numBlocks);
  if (numBlocks > 0) {
    for (int i = 0; i < numBlocks; i++) {
      Block *block = &pixy.ccc.blocks[i];
      if (block->m_signature == 2) {
        Serial.println("Bloque Verde");
        // Si se detecta un bloque de firma 2, girar a la izquierda
      servoMotor.write(75);
      } else if (block->m_signature == 1) {
        Serial.println("Bloque Rojo");
      servoMotor.write(15); // Si se detecta un bloque de firma 1, girar a la derecha
      } else {
        // En otros casos, mantener el servo en posición media
        servoMotor.write(53);
        delay(500);
      }
    }
  } else {
    Serial.println("No hay bloque");
    // Si no se detectan bloques, mantener el servo en posición media
    servoMotor.write(53);
  }
}
