## ARDUINO BALL BALANCING SYSTEM (PID CONTROL)

PROJECT OVERVIEW
----------------
This project implements a "Ball and Beam" control system using an Arduino. This was developed as a team project to demonstrate the application of PID control in a physical feedback loop. The objective is to balance a ping-pong ball at the center of a beam using active feedback from an ultrasonic sensor and adjustments from a servo motor.

HARDWARE COMPONENTS
-------------------
* Microcontroller: Arduino (Uno/Nano)
* Sensor: HC-SR04 Ultrasonic Sensor
* Actuator: Standard Servo Motor
* Physical Structure: A balance beam mounted to the servo arm.

PIN CONFIGURATION
-----------------
* Servo Motor: Pin 9 (PWM)
* Ultrasonic Trig: Pin 11
* Ultrasonic Echo: Pin 12

CONTROL LOGIC (PID)
-------------------
The system utilizes the PID_v1 library to calculate motor adjustments.
* Kp (Proportional): 0.8
* Ki (Integral): 1.0
* Kd (Derivative): 0.2
* Setpoint: 28 cm
* PID Mode: REVERSE
* Output Limits: -50 to 80

CALIBRATION AND SAFETY
----------------------
* Distance Calculation: Based on the speed of sound (0.03463 cm/us) at 25 degrees Celsius.
* Fail-safe: If the ball is not detected for 30 cycles, the servo resets to 180 degrees.
* Precision: The system includes specific logic to detect when the ball is within the 23-33cm range for stabilization.

REPOSITORY STRUCTURE
--------------------
* final-code.ino: The main PID control implementation.
* sensor-testing.ino: Diagnostic script for verifying ultrasonic sensor accuracy.
* servo-testing.ino: Diagnostic script for testing servo motor range.

HOW TO USE
----------
1. Connect hardware according to the Pin Configuration.
2. Install the 'PID_v1' and 'Servo' libraries in the Arduino IDE.
3. Upload 'sensor-testing.ino' to verify distance readings.
4. Upload 'servo-testing.ino' to verify mechanical range.
5. Upload 'final-code.ino' for the full balancing system.

---
*Developed by part of a group project for "Introduction to ECE science" subject.*
