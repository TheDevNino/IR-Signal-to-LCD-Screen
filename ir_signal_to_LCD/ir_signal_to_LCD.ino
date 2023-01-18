#include <IRremote.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C-Adresse des LCD-Displays, Anzahl der Zeichen pro Zeile, Anzahl der Zeilen
IRrecv irrecv(2); // IR-Empfänger an Pin 2
decode_results results;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.begin();
  lcd.backlight();
  irrecv.enableIRIn(); // IR-Empfänger aktivieren
}

void loop() {
  if (irrecv.decode(&results)) { // Wenn ein IR-Signal empfangen wurde
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HEX-Code: ");
    lcd.setCursor(0,1);
    lcd.print(results.value, HEX); // hexadezimalen Wert des Codes auf dem LCD-Display anzeigen
    irrecv.resume(); // Bereit für den Empfang von weiteren IR-Signalen
  }
}