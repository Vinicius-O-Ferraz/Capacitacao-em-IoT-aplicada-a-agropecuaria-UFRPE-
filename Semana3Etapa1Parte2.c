#include <LiquidCrystal.h>

const int pinSensor = A0;
const int pinLedAzul = 2;
const int pinLedVerde = 3;
const int pinLedVermelho = 4;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);

  pinMode(pinLedAzul, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedVermelho, OUTPUT);
}

void loop() {
  float tension = analogRead(pinSensor) * (5000.0 / 1024.0);
  float temperature = (tension - 500) / 10;

  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(temperature);
  lcd.print("C");

  if (temperature < 18) {
    digitalWrite(pinLedAzul, HIGH);
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedVermelho, LOW);
  }

  else if (temperature >= 18 && temperature <= 30) {
    digitalWrite(pinLedAzul, LOW);
    digitalWrite(pinLedVerde, HIGH);
    digitalWrite(pinLedVermelho, LOW);
  }

  else {
    digitalWrite(pinLedAzul, LOW);
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedVermelho, HIGH);
  }

  delay(5000);
}
