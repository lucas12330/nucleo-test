#pragma once
#include <ultrason.h>
#include <Arduino.h>

ultrason::ultrason(int trigPin, int echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
}

// Initialise les port des pins
void ultrason::init() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}  

// Récupère la distance
float ultrason::getDistance() {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    _duration = pulseIn(_echoPin, HIGH);
    _distance = _duration * 0.034 / 2;
    return _distance;
}