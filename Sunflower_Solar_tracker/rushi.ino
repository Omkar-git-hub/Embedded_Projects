#include <Servo.h>


// Include servo library


// Define servo objects
Servo servoX;
Servo servoY;

// Define LDR pins
const int ldr1Pin = A0;
const int ldr2Pin = A1;
const int ldr3Pin = A2;
const int ldr4Pin = A3;

// Initialize LDR values
int ldr1Value, ldr2Value, ldr3Value, ldr4Value;

void setup() {
    // Attach servo pins
    servoX.attach(9);
    servoY.attach(10);
}

void loop() {
    // Read LDR values
    ldr1Value = analogRead(ldr1Pin);
    ldr2Value = analogRead(ldr2Pin);
    ldr3Value = analogRead(ldr3Pin);
    ldr4Value = analogRead(ldr4Pin);

    // Calculate servo angles based on LDR values
    int servoXAngle = map(ldr1Value - ldr2Value, 0, 1023, 0, 180);
    int servoYAngle = map(ldr3Value - ldr4Value, 0, 1023, 0, 180);
    int servoZAngle = map(ldr2Value - ldr1Value, 1, 1023, 0, 180);
    int servoBAngle = map(ldr4Value - ldr3Value, 1, 1023, 0, 180);

    // Set servo positions
    servoX.write(servoXAngle);
    servoY.write(servoYAngle);
    servoX.write(servoZAngle);
    servoY.write(servoBAngle);

    // Add delay for stability
    delay(100);
}