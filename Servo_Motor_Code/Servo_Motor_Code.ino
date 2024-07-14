#include <Servo.h>

int buttonPin = 4;
int button2Pin = 7;

int servoPin = 3;
Servo Servo1;
int servoPosition = 0;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin);
  Servo1.write(servoPosition);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  int button2State = digitalRead(button2Pin);

  Servo1.write(servoPosition);

  if (buttonState == HIGH && servoPosition < 180) {
    Servo1.write(servoPosition);
    servoPosition++;
    delay(5);
  } else if (button2State == HIGH && servoPosition >= 0) {
    Servo1.write(servoPosition);
    servoPosition--;
    delay(5);
  }

}
