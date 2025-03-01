#include <SoftwareSerial.h>
#include <Arduino.h>
#include <ultrason.h>
#include <rgb_lcd.h>
SoftwareSerial BTSerial(2, 3); // RX, TX

ultrason ultrason1(9, 8);

void setup() {
    Serial.begin(9600);     // Moniteur Série
    BTSerial.begin(9600);   // Module Bluetooth
    ultrason1.init();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if (BTSerial.available()) {
        String c1 = BTSerial.readString();  // Lire caractère
        Serial.println(c1);           // Afficher dans le Moniteur Série
        if (c1 == "c:123"){
            digitalWrite(LED_BUILTIN, HIGH);
        } else if (c1 == "c:456"){
            digitalWrite(LED_BUILTIN, LOW);
        } else if (c1 == "distance"){
            float distance = ultrason1.getDistance();
            BTSerial.println(distance);
        }
    }
    if(Serial.available()>0) {
        String c2 = Serial.readString();
        BTSerial.println(c2);
    }
    delay(10);
}

