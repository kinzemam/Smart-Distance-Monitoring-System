#include <LiquidCrystal.h>

// C++ code
//
LiquidCrystal lcd(13,12,8,7,6,5);
int ledPin=4, trigPin=3 , echoPin=2;
void setup()
{
 lcd.begin(16, 2);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
 digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance=duration*0.034/2.0;
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  if (distance < 10 && distance > 0) {
    lcd.print("ALERT: TOO CLOSE");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  else{
    lcd.print("Safe Distance");
    digitalWrite(ledPin, LOW);
  }
  
  delay(200);
  
  
}