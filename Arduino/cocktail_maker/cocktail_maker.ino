#include<LiquidCrystal.h>
#include<Keypad.h>
const byte ROWS=4;
const byte COLS=3;
char keys[ROWS][COLS]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};
 byte rowsPins[ROWS]={10,9,8,7};
 byte colsPins[COLS]={11,12,13};
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
Keypad keypad = Keypad(makeKeymap(keys),rowsPins,colsPins,ROWS,COLS);

char state = '0';
int pourTime = 500;

//drivermotor pin connection 
// flow rate is 34 ml/s
int motorPin1 =2;
int motorPin2 = 3;
int motorPin3 =4;
int motorPin4 =5;
int motorPin5 =0;
int motorPin6 =1;
int infraPin = 6;
void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(0,OUTPUT);
 pinMode(1,OUTPUT);
 pinMode(infraPin,INPUT);

 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(0,LOW);
 digitalWrite(1,LOW);
 
lcd.begin(20,4);
displayMenu();
}

void loop() {
  // put your main code here, to run repeatedly:
char key=keypad.getKey();

if(key!= 0 && key!='0' && key!='8' && key!='9' && key!= '*' && key!='#')
{
 confirmOrder(key);
}
}
void Mixer(int delayTimeDrink1,int delayTimeDrink2,int delayTimeDrink3)
{

  digitalWrite(motorPin1,HIGH);
  delay(delayTimeDrink1);
  digitalWrite(motorPin1,LOW);
  delay(pourTime);

  digitalWrite(motorPin4,HIGH);
  delay(delayTimeDrink2);
  digitalWrite(motorPin4,LOW);
  delay(pourTime);
 
  digitalWrite(motorPin5,HIGH);
  delay(delayTimeDrink3);
  digitalWrite(motorPin5,LOW);
  delay(pourTime);
  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Your Order Is Ready");
  delay(1000);
  displayMenu();
}

void displayMenu()
{
lcd.clear();
lcd.print("1)drk1 2)drk2 3)drk3 ");
lcd.setCursor(0,1);
lcd.print("4)drk4 5)drk5 6)drk6 ");
lcd.setCursor(0,2);
lcd.print("7)drk7 ");
}
// flow rate of motor 34ml/s 
// one serving 250 ml motor has to work for 7.3 sec
void finalOrder(char state)
{
  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("drink ");
  lcd.print(state);
  lcd.print("in making");
 if(state == '1'){ Mixer(7300,0,0);}
 // only drink2
 if(state == '2'){ Mixer(0,7300,0);}
 // oly drink3
 if(state == '3'){Mixer(0,0,7300);}
 // drink1+drink2
 if(state == '4'){Mixer(3650,3650,0);}
 // drink1+drink3
 if(state == '5'){Mixer(3650,0,3650);}
 // drink2+drink3
 if(state == '6'){Mixer(0,3650,3650);}
 // drink1+drink2+drink3
 if(state == '7'){Mixer(2430,2430,2430);}
}

void confirmOrder(char state)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You have choosen ");
  lcd.setCursor(0,1);
  lcd.print("drink ");
  lcd.print(state);
  lcd.setCursor(0,2);
  lcd.print("press * to go back ");
  lcd.setCursor(0,3);
  lcd.print("press # to continue ");
  while(1){
  char key=keypad.getKey();
  if(key=='#' && digitalRead(infraPin) == HIGH )
  {
    finalOrder(state);
    break;
  }
  else if(key=='#' && digitalRead(infraPin) == LOW){
    lcd.clear();
    lcd.print("cup not found ");
    lcd.setCursor(0,2);
    lcd.print("please place cup ");
    lcd.setCursor(0,3);
    lcd.print("and press # to continue");
  }
  else if(key=='*'){
    displayMenu();
    break;
  }
}
}
