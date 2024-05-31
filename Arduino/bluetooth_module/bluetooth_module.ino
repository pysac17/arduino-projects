char inputByte;
void setup() {
 Serial.begin(9600);
// pinMode(13,OUTPUT);
}

void loop() {
while(Serial.available()>0){
  inputByte= Serial.read();
  Serial.println(inputByte);
  if (inputByte=='1'){
  Serial.println("High");
  }
  else if (inputByte=='0'){
  Serial.println("Low");
  } 
  }
}
