# obstacle-avoidance-robot

This project use an HC-SR04 ultrasonic sensor servo servo motor to scan the environment. The robot measures the distance in front, then looks left and right when an obstacle is detected, Based on the measured distance, it chooses the clearer path and continues moving forward.

A push button is used for start-stop control, and a LED to show when the robot is on.


Note: A separate 5V regulator (such as a buck converter) could be used for the servo, but the L298N 5V output is sufficient for this single servo project and keeps the circuit simple.


## Components List

- **1×** Arduino Uno board
- **1×** L298N motor driver module
- **2×** 12v DC gear motor with wheels
- **1×** Servo motor SG90
- **1×** Ultrasonic sensor HC-SR04
- **1×** LED
- **1×** 330ohm Resistor
- **1×** push button
- **2×** 18650 Li-ion batteries (3.7v each)
- **1×** 18650 battery holder
- **1×** 2WD robot chasis kit
- **30×** jumber wires


## Source code: 

[code.ino](code.ink)


## Circuit schematic: 

[schematic.fzz](schematic.fzz) 

[schematic.png](schematic.png)


## Project video: 

[video.mp4](video.mp4) 

[YouTube](https://youtube.com/shorts/ZcSxQrTm-8I?si=mGbtV4SB16S39HmF)
