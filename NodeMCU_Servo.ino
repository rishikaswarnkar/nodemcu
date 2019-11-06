#include<Servo.h> 
Servo myServo; 


void setup() {
myServo.attach(D4); 
myServo.write(0); 
delay(2000); 

}

void loop() {
  // put your main code here, to run repeatedly:
myServo.write(90); 
delay(1000); 
myServo.write(0); 
delay(1000); 
}
