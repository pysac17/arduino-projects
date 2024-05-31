int motor1pin1 = 10;
int motor1pin2 = 5;

int motor2pin1 = 6;
int motor2pin2 = 9;

String text;
char c;
int flag;

#define CLK 2
#define DT 3

int counter = 0;
float rev = 0.0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";

void setup() 
{

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);

  Serial.begin(9600);


  lastStateCLK = digitalRead(CLK);
  
//   Call updateEncoder() when any high/low changed seen
//   on interrupt 0 (pin 2), or interrupt 1 (pin 3)
//  attachInterrupt(0, updateEncoder, CHANGE);
//  attachInterrupt(1, updateEncoder, CHANGE);
}

void loop() 
{
   while(Serial.available())
  {
    c = Serial.read();
    text+=c;
  }
  if(text == "RIGHT")
  {
    Serial.println("right");
    flag = 2;
    text = "";
  }
  if(text == "FORWARD")
  {
    Serial.println("forward");
    flag = 1;
    text = "";
  }
  
  if(text == "LEFT")
  {
    Serial.println("left");
    flag = 3;
    text = "";
  }

  if(flag == 1)
  {
    analogWrite(motor1pin1, 162);
    analogWrite(motor1pin2, 0);
    analogWrite(motor2pin1, 162);
    analogWrite(motor2pin2, 0);
    
    currentStateCLK = digitalRead(CLK);
  
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
    {
      if (digitalRead(DT) != currentStateCLK) 
      {
        counter ++;
        currentDir ="CCW";
      } 
      else 
      {
        counter ++;
        currentDir ="CW";
      }
  
      Serial.print("Direction: ");
      Serial.print(currentDir);
      Serial.print(" | Counter: ");
      Serial.println(counter);
    }
  
    lastStateCLK = currentStateCLK;
    
    while(Serial.available())
    {
      c = Serial.read();
      text+=c;
    }
    
    float val = text.toFloat();
    Serial.println(text); 
    Serial.print("rev: ");
    Serial.println(val);
    
    rev = val/22;
    
    Serial.print("rev: ");
    Serial.println(rev);
  
    Serial.print("Counterval: ");
    Serial.println(counter);
    
  
    if(counter >= rev*17.5)
    {
      Serial.println("Stop");
      analogWrite(motor1pin1, 0);
      analogWrite(motor1pin2, 0);
      analogWrite(motor2pin1, 0);
      analogWrite(motor2pin2, 0);  
      delay(5000);  
      text = "";
      counter = 0;
    }
  
  }
  if(flag == 2)
  {
    analogWrite(motor1pin1, 0);
    analogWrite(motor1pin2, 190);
    analogWrite(motor2pin1, 225);
    analogWrite(motor2pin2, 0);
    
    currentStateCLK = digitalRead(CLK);
  
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
    {
      if (digitalRead(DT) != currentStateCLK) 
      {
        counter ++;
        currentDir ="CCW";
      } 
      else 
      {
        counter ++;
        currentDir ="CW";
      }
  
      Serial.print("Direction: ");
      Serial.print(currentDir);
      Serial.print(" | Counter: ");
      Serial.println(counter);
    }
  
    lastStateCLK = currentStateCLK;
    
//    while(Serial.available())
//    {
//      c = Serial.read();
//      text+=c;
//    }
    text = "17";
    
    float val = text.toFloat();
    Serial.println(text); 
    Serial.print("rev: ");
    Serial.println(val);
    
    rev = val/22;
    
    Serial.print("rev: ");
    Serial.println(rev);
  
    Serial.print("Counterval: ");
    Serial.println(counter);
    
  
    if(counter >= rev*11)
    {
      Serial.println("Stop");
      analogWrite(motor1pin1, 0);
      analogWrite(motor1pin2, 0);
      analogWrite(motor2pin1, 0);
      analogWrite(motor2pin2, 0);  
      delay(5000);  
      text = "";
      counter = 0;
      flag = 0;
    }
    
  }
  if (flag == 3)
  {
    analogWrite(motor1pin1, 225);
    analogWrite(motor1pin2, 0);
    analogWrite(motor2pin1, 0);
    analogWrite(motor2pin2, 150);
    
    currentStateCLK = digitalRead(CLK);
  
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
    {
      if (digitalRead(DT) != currentStateCLK) 
      {
        counter ++;
        currentDir ="CCW";
      } 
      else 
      {
        counter ++;
        currentDir ="CW";
      }
  
      Serial.print("Direction: ");
      Serial.print(currentDir);
      Serial.print(" | Counter: ");
      Serial.println(counter);
    }
  
    lastStateCLK = currentStateCLK;
    
//    while(Serial.available())
//    {
//      c = Serial.read();
//      text+=c;
//    }

    text = "16";
    
    float val = text.toFloat();
    Serial.println(text); 
    Serial.print("rev: ");
    Serial.println(val);
    
    rev = val/22;
    
    Serial.print("rev: ");
    Serial.println(rev);
  
    Serial.print("Counterval: ");
    Serial.println(counter);
    
  
    if(counter >= rev*17.5)
    {
      Serial.println("Stop");
      analogWrite(motor1pin1, 0);
      analogWrite(motor1pin2, 0);
      analogWrite(motor2pin1, 0);
      analogWrite(motor2pin2, 0);  
      delay(5000);  
      text = "";
      counter = 0;
      flag = 0;
    }
    
  }
  if(flag == 0)
  {
      Serial.println("Stop");
      analogWrite(motor1pin1, 0);
      analogWrite(motor1pin2, 0);
      analogWrite(motor2pin1, 0);
      analogWrite(motor2pin2, 0);  
      delay(5000);  
      text = "";
      counter = 0;
      
  }
  
}
