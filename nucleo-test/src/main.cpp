#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);  // RX, TX

void setup() {
    Serial.begin(9600);     // Moniteur Série
    BTSerial.begin(9600);   // Module Bluetooth
}

void loop() {
    if (BTSerial.available()) {
        String c1 = BTSerial.readString();  // Lire caractère
        Serial.println(c1);           // Afficher dans le Moniteur Série
    }
    if(Serial.available()>0) {
        String c2 = Serial.readString();
        BTSerial.println(c2);
    }
    delay(10);
}
