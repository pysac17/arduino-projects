
int IR1=8;      
int IR2=9;    

int enA = 5;    
int MotorAip1=2;
int MotorAip2=3;

int enB = 6;    
int MotorBip1=4;
int MotorBip2=7;
void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{
  if(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH) 
  {
    Serial.println("stop1");
    analogWrite (enA, 0); 
    analogWrite (enB, 0);
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    
    delay(5000);

    analogWrite (enA, 80);
    analogWrite (enB, 80);
    //Move both the Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    Serial.println("FORWARD#");

    delay(650); 

  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)  //IR not on black line
  {
    Serial.println("FORWARD");
    analogWrite (enA, 90);
    analogWrite (enB, 90);
    //Move both the Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    Serial.println("FORWARD#");
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)
  {
    Serial.println("Turn1");
    analogWrite (enA, 105);
    analogWrite (enB, 65);
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);


  }

  else if(digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)
  {
    Serial.println("Turn2");
    analogWrite (enA, 65);
    analogWrite (enB, 105);
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);


  }

  else
  {
    analogWrite (enA, 0);
    analogWrite (enB, 0);
    Serial.println("stop2");
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW); 
    digitalWrite(MotorBip2,LOW);

    Serial.println("stop2");
  }
}
