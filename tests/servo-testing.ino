#include <Servo.h>
Servo myservo;  // Creating a servo object name myservo
  // defining analog pin for potentiometer
int val=0;    // variable which will read analog pin values for potentiometer

void setup() {
  myservo.attach(9);  // defined pin 9 for PWM input signal of servo on Arduino
}
void loop() {
  val+=10;     // scale the value to use with the servo (value between 0 and 180)
  myservo.write(val);
  if (val>=180){
    val=0;
  }                  // sets servo position with scaled value
  delay(15);                           // waits for the servo to get to position
}