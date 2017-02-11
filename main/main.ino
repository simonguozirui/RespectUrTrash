#include <Servo.h>
const int flipServo1Pin = 2;
const int flipServo2Pin = 4;

Servo flipServo1, flipServo2;

void setup()
{
  flipServo1.attach(flipServo1Pin);
  flipServo2.attach(flipServo2Pin);
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
void loop()
{
  flip();
  delay(500);
  flipback();
}

