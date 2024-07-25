#include <Servo.h>

Servo Motor;

int signalPin = A0; //analog pin connected to the circuit output
int motorControlPin = 9; //digital ~ pin connected to the motor control wire
int motorPosition = 0; 
int desiredAngle = 90;

void setup() {

  Serial.begin(9600);
  pinMode(motorControlPin, OUTPUT); //setting motor control pin as output
  digitalWrite(motorControlPin, LOW); //setting motor to be off initially

  Motor.attach(motorControlPin); //attaching the motor to the motor control pin
  Motor.write(motorPosition); //starting position of the motor
  Serial.begin(9600);
}

void loop() {

  int signalValue = analogRead(signalPin); //read the signal
  Serial.println(signalValue);



  Motor.write(motorPosition);


  if (signalValue > 670 && motorPosition == 0){
    Serial.println(1);
    delay(750);
    motorPosition = desiredAngle;
    Motor.write(motorPosition);

    delay(1000);
    motorPosition = 0;
    Motor.write(motorPosition);
    delay(5);

  }

  
  
  delay(3000);

}
