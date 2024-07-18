#include <Servo.h>

Servo Motor;

int signalPin = A0; //analog pin connected to the circuit output
int motorControlPin = 9; //digital ~ pin connected to the motor control wire
int motorPosition = 0; // angle
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

//  readingsTotal = readingsTotal - readings[readIndex]; //removed the oldest reading from the total
  int signalValue = analogRead(signalPin); //read the signal
  Serial.println(signalValue);



  Motor.write(motorPosition);


  if (signalValue > 613 && motorPosition == 0){

    delay(2000);
    motorPosition = desiredAngle;
    Motor.write(motorPosition);

    

  }
  else if (signalValue > 613 && motorPosition < desiredAngle){

    delay(2000);
    motorPosition = 0;
    Motor.write(motorPosition);
    delay(5);

  }

  
  
  delay(3000);

}
