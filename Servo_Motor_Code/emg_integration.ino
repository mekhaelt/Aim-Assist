#include <Servo.h>

Servo Motor;

// Analog pin connected to the circuit output
int signalPin = A0; 

// Digital pin connected to the motor control wire
int motorControlPin = 9; 
int motorPosition = 0; 
int desiredAngle = 90;

void setup() {
  Serial.begin(9600);

  // Set motor control pin as output
  pinMode(motorControlPin, OUTPUT);  
  // Initialize motor to be off
  digitalWrite(motorControlPin, LOW); 

  // Attach the motor to the motor control pin
  Motor.attach(motorControlPin); 
  // Set starting position of the motor
  Motor.write(motorPosition); 
}

void loop() {
  // Read the analog signal
  int signalValue = analogRead(signalPin); 
  // Print the signal value for debugging
  Serial.println(signalValue);

  // Write current motor position
  Motor.write(motorPosition);
  
  // Check if signal value is above threshold (3.27 V) and motor is in the initial position
  if (signalValue > 670 && motorPosition == 0) {
    // Print status for debugging
    Serial.println("Threshold Reached");
    // Delay for stabilization
    delay(750);
    // Move motor to desired angle
    motorPosition = desiredAngle;
    Motor.write(motorPosition);

    // Hold position before resetting
    delay(1000);
    // Reset motor position
    motorPosition = 0;
    Motor.write(motorPosition);
    // Small delay for smooth movement
    delay(5);
  } 
  // Delay before next loop iteration
  delay(3000);
}
