int pirPin = 2;                 
int pirStat;                   
void setup() {   
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            
   Serial.println("Object detected");
 } 
 else if(pirStat == LOW){
   Serial.println("No Object detected");
 }
} 
