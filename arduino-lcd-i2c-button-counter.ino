/*
  Project Title: Arduino LCD I2C Button Counter

  Description:
  This beginner-friendly Arduino project demonstrates how to use a push button
  to increase a counter value and display it on a 16x2 LCD using an I2C module.
  Each time the button is pressed, the counter increases by 1 and the updated
  value appears on the LCD screen.

  Components:
  - Arduino Uno / Nano
  - LCD 16x2 with I2C module
  - Push Button
  - Breadboard
  - Jumper Wires

  Wiring:

  LCD I2C -> Arduino
  VCC -> 5V
  GND -> GND
  SDA -> A4
  SCL -> A5

  Push Button -> Arduino
  One leg  -> Pin D2
  Other leg -> GND

  Note:
  The button uses Arduino's internal pull-up resistor (INPUT_PULLUP).
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set LCD address (commonly 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;

int counter = 0;
int lastButtonState = HIGH;
int currentButtonState;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Button Counter");

  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {

  currentButtonState = digitalRead(buttonPin);

  // Detect button press (HIGH -> LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {

    counter++;

    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(counter);
    lcd.print("   "); // clear leftover digits
  }

  lastButtonState = currentButtonState;

  delay(50); // simple debounce
}