#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIR_SENSOR 2  // PIR Sensor connected to Digital Pin 2
#define BUZZER 7      // Buzzer connected to Digital Pin 7
#define LED 8         // LED connected to Digital Pin 8

// Initialize LCD at I2C address 0x27 (change to 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(PIR_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(LED, OUTPUT);
    
    lcd.init();  // Initialize LCD
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Motion Detector");
    delay(2000);
    lcd.clear();
}

void loop() {
    int motion = digitalRead(PIR_SENSOR); // Read motion sensor state
    
    lcd.setCursor(0, 0);
    lcd.print("Motion: ");
    lcd.print(motion); // Display PIR sensor status
    lcd.setCursor(0, 1);
    
    if (motion == HIGH) {  // If motion is detected
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED, HIGH);
        lcd.print("Motion Detected! ");
    } else {
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED, LOW);
        lcd.print("No Motion    "); // Clear previous text
    }
    delay(500); // Small delay for stability
}