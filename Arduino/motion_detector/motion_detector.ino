#include <Servo.h>          //standard library for the servo
#include <NewPing.h>        //for the Ultrasonic sensor function library.

//L298N motor control pins
const int LeftMotorForward = 6;
const int LeftMotorBackward = 10;
const int RightMotorForward = 5;
const int RightMotorBackward = 3;

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; 

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(9); //our servo pin

  servo_motor.write(70);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

  Serial.begin(9600);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(100);
    moveBackward();
    delay(80);
    moveStop();
    delay(100);
    distanceRight = lookRight();
    delay(40);
    distanceLeft = lookLeft();
    delay(40);
  
      if(distanceLeft <= distanceRight){
        turnRight();
        moveStop();
      }
      else if(distanceLeft <= distanceRight){
        turnLeft();
        moveStop();
      }
      else{
      analogWrite(LeftMotorBackward, 255);
      analogWrite(RightMotorBackward, 255);
      
      analogWrite(LeftMotorForward, 0);
      analogWrite(RightMotorForward, 0);
      delay(100);
      moveStop();
      }
    }
    else{
      moveForward(); 
    }
    distance = readPing();
  }
  
  int lookRight(){  
    servo_motor.write(0);
    delay(500);
    int distance = readPing();
    delay(100);
    servo_motor.write(70);
    return distance;
  }
  
  int lookLeft(){
    servo_motor.write(180);
    delay(500);
    int distance = readPing();
    delay(100);
    servo_motor.write(70);
    return distance;
  }
  
  int readPing(){
    delay(70);
    int cm = sonar.ping_cm();
    if (cm==0){
      cm=250;
    }
    return cm;
    Serial.println(cm);
  }
  
  void moveStop(){
    
    analogWrite(RightMotorForward, 0);
    analogWrite(LeftMotorForward, 0);
    analogWrite(RightMotorBackward, 0);
    analogWrite(LeftMotorBackward, 0);
  }
  
  void moveForward(){
  
    if(!goesForward){
  
      Serial.println("forward");
      goesForward=true;
      
//      analogWrite(LeftMotorForward, 78.7);
//      analogWrite(RightMotorForward, 120);

      analogWrite(LeftMotorForward, 50);
      analogWrite(RightMotorForward, 60);

    
      analogWrite(LeftMotorBackward, 0);
      analogWrite(RightMotorBackward, 0); 
    }
  }
  
  void moveBackward(){
  
    Serial.println("backward");
  
    goesForward=false;
  
    analogWrite(LeftMotorBackward, 255);
    analogWrite(RightMotorBackward, 255);
    
    analogWrite(LeftMotorForward, 0);
    analogWrite(RightMotorForward, 0);
    
  }
  
  void turnRight(){
  
    Serial.println("turn right");
  
    analogWrite(LeftMotorForward, 150);
    analogWrite(RightMotorBackward, 150);
    
    analogWrite(LeftMotorBackward, 0);
    analogWrite(RightMotorForward, 0);
    
    delay(300);
    
    analogWrite(LeftMotorForward, 50);
    analogWrite(RightMotorForward, 60);
    
    analogWrite(LeftMotorBackward, 0);
    analogWrite(RightMotorBackward, 0); 
    delay(100);   
  }
  
  void turnLeft(){
  
    Serial.println("turn left");
  
    analogWrite(LeftMotorBackward, 250);
    analogWrite(RightMotorForward, 150);
    
    analogWrite(LeftMotorForward, 0);
    analogWrite(RightMotorBackward, 0);
  
    delay(500);
    
    analogWrite(LeftMotorForward, 50);
    analogWrite(RightMotorForward, 60);
    
    analogWrite(LeftMotorBackward, 0);
    analogWrite(RightMotorBackward, 0);
    delay(100);
  }
