#include <Servo.h>
Servo servoMotor;



void setup() {
Serial.begin(9600);
servoMotor .attach(9);
servoMotor .write(0); 		
}
void loop(){
for (int i = 0; i <= 130; i++){
    servoMotor .write(i);
    delay(0);
}
for (int i = 129; i > 0; i--){
   servoMotor.write(i);
   delay (25);

}
}