#include <Servo.h>
const int flipServo1Pin = 2;
const int flipServo2Pin = 4;
const int motionPin = 10;
const int greenLedPin = 7;
const int redLedPin = 7;

Servo flipServo1, flipServo2;

void setup()
{
  pinMode(flipServo1Pin, OUTPUT);
  pinMode(flipServo2Pin, OUTPUT);
  pinMode(motionPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  Serial.begin(9600);
  flipServo1.attach(flipServo1Pin);
  flipServo2.attach(flipServo2Pin);
}

void greenLedPinOn() {
  digitalWrite(greenLedPin, HIGH);                                 
}
void greenLedPinOff(){
  digitalWrite(greenLedPin, LOW);          
}
void redLedPinOn() {
  digitalWrite(redLedPin, HIGH);                                 
}
void redLedPinOff(){
  digitalWrite(redLedPin, LOW);          
}
void flip() {
  int pos = 0;
  int speed = 5;
  for (pos = 0; pos < 180; pos += speed)
  {
    flipServo1.write(pos);
    flipServo2.write(180 - pos);
    delay(15);
  }
}
void flipback() {
  int pos = 0;
  int speed = 5;
  for (pos = 180; pos >= 1; pos -= speed)
  {
    flipServo1.write(pos);
    flipServo2.write(180 - pos);
    delay(15);
  }
}

boolean motionDetect() {
  boolean detected = false;
  if (digitalRead(motionPin) == 1) detected = true;
  return detected;
}
void loop()
{
  //flip();
  //delay(500);
  //flipback();
  //Serial.println(String(motionDetect()));
}

