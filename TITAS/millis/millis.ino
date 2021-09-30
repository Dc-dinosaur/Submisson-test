#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//unsigned long time_now;  //no decimal
float time_now;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  time_now = millis();
  Serial.print("Time: ");
  Serial.print(time_now / 1000);
  Serial.println("s");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(5, 0);
  lcd.print(time_now / 1000);
  lcd.setCursor(10, 0);
  lcd.print("s");
}
