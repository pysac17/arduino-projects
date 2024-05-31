#include <Servo.h>  

//L298N motor control pins
const int LeftMotorForward = 6;
const int LeftMotorBackward = 10;
const int RightMotorForward = 5;
const int RightMotorBackward = 3;

//Servo servo_motor;
void setup() {
  
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
//
//  servo_motor.attach(9); //our servo pin
//  servo_motor.write(115);
}
//
void loop() {

////left
//  
//    analogWrite(LeftMotorForward, 150);
//    analogWrite(RightMotorBackward, 150);
//    
//    analogWrite(LeftMotorBackward, 0);
//    analogWrite(RightMotorForward, 0);
//    
//    delay(300);
//    
//    analogWrite(LeftMotorForward, 150);
//    analogWrite(RightMotorForward, 150);
//    
//    analogWrite(LeftMotorBackward, 0);
//    analogWrite(RightMotorBackward, 0);  
//    delay(100);
//    analogWrite(LeftMotorBackward, 0);
//    analogWrite(RightMotorForward, 0);
//    
//    analogWrite(LeftMotorForward, 0);
//    analogWrite(RightMotorBackward, 0);
//    delay(5000);

      analogWrite(LeftMotorBackward, 50);
      analogWrite(RightMotorBackward,55);
      
      analogWrite(LeftMotorForward, 0);
      analogWrite(RightMotorForward, 0);
    
    
//
////  servo_motor.write(115);
//  
////right
//  digitalWrite(LeftForward, HIGH);
//  digitalWrite(RightBackward, HIGH);
//  digitalWrite(LeftBackward, LOW);
//  digitalWrite(RightForward, LOW);
//
////forward
////    digitalWrite(LeftForward, HIGH);
////    digitalWrite(RightForward, HIGH);
////    digitalWrite(LeftBackward, LOW);
////    digitalWrite(RightBackward, LOW); 
//
//  //backward
////  digitalWrite(LeftBackward, HIGH);
////  digitalWrite(RightBackward, HIGH);
////  digitalWrite(LeftForward, LOW);
////  digitalWrite(RightForward, LOW);
//  // put your main code here, to run repeatedly:
//
}

//#include<Servo.h>
//Servo Myservo;
//int pos;
//void setup()
//{
//Myservo.attach(9);
//}
//
//void loop()
//{
//  
//  
//for(pos=0;pos<=180;pos++){
//Myservo.write(pos);
//delay(15);
//}
//  delay(1000);
//  
//  for(pos=180;pos>=0;pos--){
//Myservo.write(pos);
//delay(15);
//}
//  delay(1000);
//  
//}
