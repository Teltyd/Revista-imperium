#include <Servo.h>
Servo servoMotor;
int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int TRIG = 10;			// trigger en pin 10
int ECO = 9;			// echo en pin 9
int DURACION;
int DISTANCIA;

int TRIG_Izq = 11;			// trigger en pin 10
int ECO_Izq = 12;			// echo en pin 9
int DURACION_I;
int DISTANCIA_I;

int TRIG_DER = 8;			// trigger en pin 10
int ECO_DER = 7;			// echo en pin 9
int DURACION_D;
int DISTANCIA_D;


void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  {
    pinMode(TRIG, OUTPUT); 	// trigger como salida
  pinMode(ECO, INPUT);		// echo como entrada

  Serial.begin(9600);  		// inicializacion de comunicacion serial a 9600 bps
  }
  {
     pinMode(TRIG_Izq, OUTPUT); 	// trigger como salida
  pinMode(ECO_Izq, INPUT);		// echo como entrada

  Serial.begin(9600);  		// inicializacion de co
  }
  {
    pinMode(TRIG_DER, OUTPUT); 	// trigger como salida
  pinMode(ECO_DER, INPUT);		// echo como entrada

  Serial.begin(9600);  		// inicializacion de comunicacion serial a 9600 bps
  }
  {
Serial.begin(9600);
servoMotor .attach(6);
servoMotor .write(0); 		
  }
}

void loop() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(0);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(0);
{
    digitalWrite(TRIG, HIGH); 		// generacion del pulso a enviar
  delay(1);				// al pin conectado al trigger
  digitalWrite(TRIG, LOW);		// del sensor
  
  DURACION = pulseIn(ECO, HIGH);	// con funcion pulseIn se espera un pulso
  					// alto en Echo
  DISTANCIA = DURACION / 58.2;		// distancia medida en centimetros
  Serial.print("DISTANCIA Delante");
  Serial.println(DISTANCIA);	
  Serial.println("cm");// envio de valor de distancia por monitor serial
  delay(200);				// demora entre datos
}
{
  digitalWrite(TRIG_Izq, HIGH); 		// generacion del pulso a enviar
  delay(1);				// al pin conectado al trigger
  digitalWrite(TRIG_Izq, LOW);		// del sensor
  
  DURACION_I = pulseIn(ECO_Izq, HIGH);	// con funcion pulseIn se espera un pulso
  					// alto en Echo
  DISTANCIA_I = DURACION_I / 58.2;		// distancia medida en centimetros
  Serial.print("DISTANCIA Izquierda: ");
  Serial.println(DISTANCIA_I);		// envio de valor de distancia por monitor serial
   Serial.print("cm");  
  delay(200);				// demora entre datos
  }
  {
    digitalWrite(TRIG_DER, HIGH); 		// generacion del pulso a enviar
  delay(1);				// al pin conectado al trigger
  digitalWrite(TRIG_DER, LOW);		// del sensor
  
  DURACION_D = pulseIn(ECO_DER, HIGH);	// con funcion pulseIn se espera un pulso
  					// alto en Echo
  DISTANCIA_D = DURACION_D / 58.2;	// envio de valor de distancia por monitor serial
  Serial.print("DISTANCIA DERECHA: ");
   Serial.println(DISTANCIA_D);	
   Serial.print("cm");
  delay(200);				// demora entre datos
  }
{
    if (DURACION / 58.2 >  30);
   else (DURACION_I / 58.2 > 10);
  for (int i = 90; i <= 180; i++){
    servoMotor .write(i);
    delay(10);
}
      if (DURACION / 58.2 > 30);
    else (DURACION_I / 58.2 > 10);
  for (int i = 180; i <=90; i--){
   servoMotor.write(i);
   delay (10);
  }
if (DURACION / 58.2 > 30);
else (DURACION_D / 58.2 > 10); 
 for (int i = 0; i<=90; i++){
   servoMotor. write(i);
   delay(10);
 }
 if (DURACION / 58.2 < 30);
 else (DURACION_D / 58.2 < 10);
 for (int i = 90; i <= 0; i--){
   servoMotor. write(i);
   delay(10);


}
}
}
