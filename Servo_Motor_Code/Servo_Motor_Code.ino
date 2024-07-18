#include <Servo.h>

Servo Motor;

const int signalPin = A0; //analog pin connected to the circuit output
const int motorControlPin = 9; //digital ~ pin connected to the motor control wire
int motorPosition = 0; // angle

void setup() {

  Serial.begin(9600);
  pinMode(motorControlPin, OUTPUT); //setting motor control pin as output
  digitalWrite(motorControlPin, LOW); //setting motor to be off initially

  Motor.attach(motorControlPin); //attaching the motor to the motor control pin
  Motor.write(MotorPosition); //starting position of the motor
  Serial.begin(9600);
}

void loop() {

//  readingsTotal = readingsTotal - readings[readIndex]; //removed the oldest reading from the total
  int signalValue = analogRead(signalPin); //read the signal
  Serial.println(signalValue);



  Servo1.write(motorPosition);


  if (signalValue > 613 && motorPosition == 0){

    delay(2000);
    motorPosition++;
    Motor.write(motorPosition);
    delay(5);

  }
  if (signalValue > 613 && motorPosition < 180){

    
    motorPosition++;
    Motor.write(motorPosition);
    delay(5);

  }

  else if (motorPosition == 180){
    delay(2000)
    motorPosition--;
    Motor.write(motorPosition);
    delay(5);
  }

  else if (motorPosition < 179 && motorPosition > 0){
    
    motorPosition--;
    Motor.write(motorPosition);
    delay(5);
  }
  
  delay(3000);

}
