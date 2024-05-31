char c;
String text;
void setup() 
{
 Serial.begin(9600);
}

void loop() 
{
  while(Serial.available())
  {
    delay(10);
    c = Serial.read();
    text+=c;
  }
  Serial.println(text);
  int val = text.toInt() + 1;
  Serial.println(val);

}
