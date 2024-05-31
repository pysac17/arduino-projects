
int IRsensor = 2;
int LED = 13;

void setup() {
  // put your setup code here, to run once:
 pinMode(IRsensor, INPUT);
 pinMode(LED, OUTPUT);

 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusSensor = digitalRead(IRsensor);

  if (statusSensor == 0){
  digitalWrite(LED, LOW);
  Serial.println(statusSensor);
  }
  else{
    digitalWrite(LED, HIGH);
    Serial.println(statusSensor); 
  }
}
