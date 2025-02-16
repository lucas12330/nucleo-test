#pragma once
class ultrason {
    public:
        ultrason(int trigPin, int echoPin);
        void init();
        float getDistance();

    private:
        int _trigPin;
        int _echoPin;
        long _duration;
        float _distance;

};