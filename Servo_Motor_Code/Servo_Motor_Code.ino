#include <Servo.h>

Servo myServo;

const int signalPin = A0; //analog pin connected to the circuit output
const int motorControlPin = 9; //digital ~ pin connected to the motor control wire
const int N = 10; //numbers of readings for dynamic threshold
int readings[N]; //array of size 10 to hold the readings
int readIndex = 0; // index to track the current reading position
int readingsTotal = 0; //sum of readings for average
int averageReading = 0; //dynamic threshold

void setup() {

  Serial.begin(9600);
  pinMode(motorControlPin, OUTPUT); //setting motor control pin as output
  digitalWrite(motorControlPin, LOW); //setting motor to be off initially

  for(int i = 0; i <= 10; i++){
    readings[i] = 0; //initializing all readings to zero
  }

  myServo.attach(motorControlPin); //attaching the motor to the motor control pin
  myServo.write(10); //starting position of the motor

}

void loop() {

//  readingsTotal = readingsTotal - readings[readIndex]; //removed the oldest reading from the total
  int signalValue = analogRead(signalPin); //read the signal
  Serial.println(signalValue);


//  if(signalValue > averageReading){
  if (signalValue > 750){

    myServo.attach(9);
    digitalWrite(motorControlPin, HIGH); 
    myServo.write(110); //adjusts the motor 90 degrees
    delay(2500);
    myServo.write(10);
    delay(2500);
    digitalWrite(motorControlPin, LOW);

  }
  myServo.detach();

}
