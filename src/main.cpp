// Student Name: Liam Tingley
// Student Number: 100161568
// Assignment: COMP-5163 - Analog Input
// Version: V1.0
// Date: October 9th, 2026

#include <Arduino.h>

void setup() {
 // Configure the USB serial monitor
 Serial.begin(15200);
}

void loop() {

 int iVal;
 // Read digitized value from the D1 Mini's A/D convertor
 iVal = analogRead(A0);

 const float TEMP_MAX = 50.0f; // In Celsius.
 const float VOLTAGE = 3.3f; // Voltage.

 float temperature = iVal * VOLTAGE / 1024 * (TEMP_MAX / VOLTAGE);

 // Temperature output-handling logic.
 if(temperature < 10.0f) {

    Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an temperature input of " + temperature + "deg. C, which is Cold!");

 } else if(temperature >= 10.0f && temperature < 15.0f) {

    Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an temperature input of " + temperature + "deg. C, which is Cool");

 } else if(temperature >= 15.0f && temperature < 25.0f) {

    Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an temperature input of " + temperature + "deg. C, which is Perfect");

 } else if(temperature >= 25.0f && temperature < 30.0f) {

    Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an temperature input of " + temperature + "deg. C, which is Warm");

 } else if(temperature >= 30.0f && temperature <= 35.0f) {

    Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an temperature input of " + temperature + "deg. C, which is Hot");

 } else if(temperature > 35.0f) {

    Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an temperature input of " + temperature + "deg. C, which is Too Hot!");

 }

 // Wait 2 seconds (2000 ms)
 delay(2000);

}