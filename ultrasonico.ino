#include <Servo.h>
#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3
#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5
#define SERVO_PIN 6
int TRIG_Izq = 7;			// trigger en pin 10
int ECO_Izq = 8;			// echo en pin 9
int DURACION_I;
int D_I;
int D0_I;
int TRIG_DER = 9;			// trigger en pin 10
int ECO_DER = 10;			// echo en pin 9
int DURACION_D;
int D_D;
int D0_D;
Servo servoMotor;


void setup()
{

 pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

    pinMode(TRIG_Izq, OUTPUT); 	// trigger como salida
  pinMode(ECO_Izq, INPUT);		// echo como entrada 
    pinMode(TRIG_DER, OUTPUT); 	// trigger como salida
  pinMode(ECO_DER, INPUT);		// echo como entrada

  Serial.begin(9600);  		
 servoMotor.attach (6);
}

// Función para controlar los motores del robot
  void controlMotors(int pin1, int pin2, int speed) {
    digitalWrite(pin1, speed > 0 ? LOW : HIGH);
    digitalWrite(pin2, speed > 0 ? HIGH : LOW);
    analogWrite(abs(100), pin1);
  }

void loop(){
      controlMotors(MOTOR1_PIN1, MOTOR1_PIN2, -100);
      controlMotors(MOTOR2_PIN1, MOTOR2_PIN2, -100);
  
    digitalWrite(TRIG_Izq, HIGH); 		// generacion del pulso a enviar
  delay(1);				// al pin conectado al trigger
  digitalWrite(TRIG_Izq, LOW);		// del sensor
  
  DURACION_I = pulseIn(ECO_Izq, HIGH);	// con funcion pulseIn se espera un pulso
  					// alto en Echo
  D_I = DURACION_I / 58.9;		// distancia medida en centimetros
  Serial.print("DISTANCIA Izquierda: ");
  Serial.println(D_I);		// envio de valor de distancia por monitor serial
   Serial.print("cm");  
  delay(100);				// demora entre datos
  
  
    digitalWrite(TRIG_DER, HIGH); 		// generacion del pulso a enviar
  delay(1);				// al pin conectado al trigger
  digitalWrite(TRIG_DER, LOW);		// del sensor
  
  DURACION_D = pulseIn(ECO_DER, HIGH);	// con funcion pulseIn se espera un pulso
  					// alto en Echo
  D_D = DURACION_D / 58.9;	// envio de valor de distancia por monitor serial
  Serial.print("DISTANCIA DERECHA: ");
   Serial.println(D_D);	
   Serial.print("cm");
  delay(100);				// demora entre datos
  
  if (D_I > 65){
    servoMotor.write(70);
  }
   else if (D_D > 65){
  servoMotor.write(30);
}
  else if ( 50 < D_I < 55){
  servoMotor.write(53);
  }
   else if (D_D > 65){
  servoMotor.write(30);
}
 else if ( 60 < D_D < 65){
  servoMotor.write(53);
 }
}
