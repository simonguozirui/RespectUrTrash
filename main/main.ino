#include <DFRobotRomeoBLEMini.h>
#include <Servo.h>


const int flipServo1Pin = 2;
const int flipServo2Pin = 4;
const int motionPin = 10;
const int greenLedPin = 7;
const int redLedPin = 8;
const int buzzerPin = 13;


Servo flipServo1, flipServo2;
DFRobotRomeoBLEMini liftMotors;

void setup()
{
  pinMode(flipServo1Pin, OUTPUT);
  pinMode(flipServo2Pin, OUTPUT);
  pinMode(motionPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  flipServo1.attach(flipServo1Pin);
  flipServo2.attach(flipServo2Pin);
}

void greenLedOn() {
  digitalWrite(greenLedPin, HIGH);
}
void greenLedOff() {
  digitalWrite(greenLedPin, LOW);
}
void redLedOn() {
  digitalWrite(redLedPin, HIGH);
}
void redLedOff() {
  digitalWrite(redLedPin, LOW);
}

void flip() {
  int pos = 0;
  int speed = 5;
  for (pos = 0; pos < 90; pos += speed)
  {
    flipServo1.write(pos);
    flipServo2.write(180 - pos);
    delay(15);
  }
}
void flipback() {
  int pos = 0;
  int speed = 5;
  for (pos = 90; pos >= 1; pos -= speed)
  {
    flipServo1.write(pos);
    flipServo2.write(180 - pos);
    delay(15);
  }
}

void platformUp() {
  liftMotors.speed(255, 255);
}

void platformDown() {
  liftMotors.speed(-255, -255);
}

void platformHold() {
  liftMotors.speed(0, 0);
}

boolean motionDetect() {
  boolean detected = false;
  if (digitalRead(motionPin) == 1) detected = true;
  return detected;
}

void buzzer()
{
  unsigned char i, j;

  for (i = 0; i < 100; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(2);
    digitalWrite(buzzerPin, LOW);
    delay(2);
  }

}

void loop()
{
  flip();
  delay(500);
  flipback();
  //Serial.println(String(m8 l/otionDetect()));
  //redLedOn();
  platformUp();
  delay(4000);
  platformDown();
  delay(4000);
  //buzzer();
  platformHold();
  
}

