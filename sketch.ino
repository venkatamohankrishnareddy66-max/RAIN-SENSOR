#include <Wire.h>
#include <LiquidCrystal_I2C.h>


int LDRPin = 0;            // Connect LDR sensor to analog pin 0
int rainPin = 3;           // Connect rain sensor to digital pin 3
int buzzerPin = 8;         // Connect buzzer to digital pin 8
int ledPin = 7;            // Connect LED to digital pin 7

LiquidCrystal_I2C lcd(0x27, 16, 3);  


void setup() {
    // Set the pin modes for sensors and actuators
  pinMode(LDRPin, INPUT);
  pinMode(rainPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

 lcd.init();                 // Initialize the lcd 
 lcd.backlight();           // Turn on the backlight
   
  Serial.begin(9600);    // Initialize serial communication for debugging
}

void loop() {
  int LDRValue = analogRead(LDRPin);
  int rainValue = digitalRead(rainPin);

  lcd.clear();  // Clear the LCD screen
  lcd.setCursor(0, 0);  // First column of the first row
  lcd.print("What the LDR: ");
  lcd.print(LDRValue);
  lcd.setCursor(0, 1);  // First column of the second row
  lcd.print("Rain Value: ");
  lcd.print(rainValue);

  Serial.print("What the LDR: ");
  Serial.println(LDRValue);
  Serial.print("Rain Value: ");
  Serial.println(rainValue);

  if (rainValue == LOW) {
    // Activate the buzzer and LED if rain is detected
    tone(buzzerPin, 1000);
    digitalWrite(ledPin, HIGH);
    delay(300);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  } else {
     // Turn off the buzzer and LED if no rain is detected
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }

  delay(600);
}