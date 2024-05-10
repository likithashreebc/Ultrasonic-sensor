// Include Arduino libraries
#include <Arduino.h>

// Declare the external assembly function
extern "C" {
    int get_len(int x);
}

// Define constants and variables
const int trigPin = 15;
const int echoPin = 14;
const int ledPin = 16;

unsigned long duration;
int distance;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance <= 20) {
        digitalWrite(ledPin, HIGH);
        Serial.print("Object Detected Nearby at a Distance of: ");
        Serial.print(distance);
        Serial.println(" cm");
    } else {
        digitalWrite(ledPin, LOW);
    }
    delay(1000);

    // Call the assembly function and print the result
    int result = get_len(distance);
    Serial.print("Length of the cocoon is : ");
    Serial.println(result);
    Serial.println(" cm");

    delay(1000);
}