#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int lsb=13;
int m=10;
int count=0, b=0;
float p=A0;
void setup() {
  pinMode(13,INPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  String s=("Welcome to santization machine");
  lcd.println(s);
  delay(500);
  for(int i=0;i<s.length();i++){
    lcd.scrollDisplayLeft();
    delay(100);
  }
  lcd.clear();
  
  // put your setup code here, to run once:

}

void loop() {
  b=digitalRead(lsb);
  if(b==HIGH){
    count++;
    lcd.print(count);
    delay(1000);
    p=analogRead(A0);
    m=p;
    lcd.setCursor(0,0);
    lcd.print("Temp is:");
    lcd.print(p);
    delay(1000);
    lcd.clear();
    if (p>=95 && p<=100){
      analogWrite(10,m);
      lcd.setCursor(0,0);
      lcd.print("Sanitization done");
      delay(1000);
      lcd.clear();
       
    }
    else{
      analogWrite(10,0);
      lcd.setCursor(0,0);
      lcd.print("No Sanitization");
      delay(1000);
      lcd.clear();
    }
    
  }
  // put your main code here, to run repeatedly:

}
