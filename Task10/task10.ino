#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

#define b1 1
#define b2 2
#define b3 3
#define Anode 10
#define Cathode 11

const int maxAttempts = 3; // Maximum allowed attempts
const String correctPassword = "123"; // Correct password

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);

  pinMode(Anode, OUTPUT);
  pinMode(Cathode, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  delay(2000);
}

void loop() {
  static int attempts = 0;

  int buttonState1 = digitalRead(b1);
  int buttonState2 = digitalRead(b2);
  int buttonState3 = digitalRead(b3);

   if (buttonState1 == HIGH) {
      if (buttonState2 == HIGH) {
        if (buttonState3 == HIGH) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Correct Password");
          delay(10);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Door Unlocked");

          digitalWrite(Anode, HIGH);
          digitalWrite(Cathode, LOW);
          delay(2000);
          digitalWrite(Anode, LOW);
          digitalWrite(Cathode, LOW);
          lcd.clear();
          delay(10);
          attempts = 0;
          return;
        }
      }
  } else {
    attempts++;
    lcd.setCursor(0, 0);
    lcd.print("Wrong Password");
    digitalWrite(Anode, LOW);
    digitalWrite(Cathode, HIGH);
    delay(2000);
    digitalWrite(Anode, LOW);
    digitalWrite(Cathode, LOW);
    if (attempts >= maxAttempts) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Max Attempts");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("System Locked");
      while (true) {
        // Infinite loop to prevent further execution
      }
      return;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Password");
    delay(2000);

  }
  return;
}
