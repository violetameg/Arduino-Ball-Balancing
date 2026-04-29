#include <PID_v1.h>
#include <Servo.h>

Servo myservo;

//PID control values
const float Kp = 0.8;
const float Ki = 1;
const float Kd = 0.2;

int i=0, j=0;

//arduino pins used
const int servoPin = 9;
const int echoPin = 12;
const int trigPin = 11;

int minimum = -50, maximum = 80;
double input, output, setpoint = 28;
double getdistance(void);
PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, REVERSE);

void setup(){
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
  input = getdistance();
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(minimum, maximum);
}

void loop(){
  input = getdistance();
  if (input < 55){
    i=0;
    myPID.Compute();
    if (input >= 23 && input <= 33){
      j++;
      if (j >= 10){
        output = 10;
      }
      output = 0;
    }
    else{
      j=0;
    }
    Serial.println(output);
    myservo.write(125 + output);
    delay(500);
    }
  else{
    i++;
  }
  if (i == 30){
    myservo.write(180);
    delay(700);
    i=0;
  }
}

double getdistance(void) {
  //function used to calculate the distance between the ball and the ultrasonic sensor
  unsigned long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //calculates the total time (in microseconds) echoPin is high
  duration = pulseIn(echoPin, HIGH);
  //the total time found before is used to calculate the distance (in centimeters/microseconds) between the sensor and the ball
  distance = (duration * 0.03463) / 2; //0.03463 cm/microsecs is the speed of sound in the air in 25 degrees Celsius

  Serial.print("duration: ");
  Serial.println(duration);
  Serial.print("distance: ");
  Serial.println(distance);
  Serial.println();

  return distance;
}
