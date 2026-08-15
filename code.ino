#include <Servo.h>

Servo radarServo;

const int trigPin = 5;
const int echoPin = 4;

const int servoPin = 3;

const int in1 = 10;
const int in2 = 9;
const int in3 = 8;
const int in4 = 7;

const int enA =11;
const int enB = 6;

const int buttonPin = 2;
const int statusLed = 13;

bool robotOn = false;
int lastButtonState = HIGH;

int obstacleDistance = 10;
int forwardSpeed = 80;
int turnSpeed = 60;

int leftDistance = 0;
int rightDistance = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(statusLed, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  radarServo.attach(servoPin);

  radarServo.write(90);

  Serial.begin(9600);
}

void loop()
{
  readButton();
  if(robotOn)
  {
    digitalWrite(statusLed, HIGH);
    runRobot();
  }
  else
  {
    stopRobot();
    digitalWrite(statusLed, LOW);
  }
}


// read button

void readButton()
{
  int buttonState = digitalRead(buttonPin);
  
  if(buttonState == LOW && lastButtonState == HIGH)
  {
    robotOn = !robotOn;
  }
  lastButtonState = buttonState;
}


// run robot

void runRobot()
{
  int distance = getDistance();

  Serial.print("front:");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance > obstacleDistance)
  {
    moveForward();
  }
  else
  {
    avoidObstacle();
  }
}


// avoid obstacle

void avoidObstacle()
{
  stopRobot();
  leftDistance = lookLeft();
  rightDistance = lookRight();
  radarServo.write(90);
  delay(300);

  if(leftDistance > rightDistance)
  {
    turnLeft();
  }
  else
  {
    turnRight();
  }
  delay(400);
  stopRobot();
}


// get distance

int getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}


void moveForward()
{
  analogWrite(enA, forwardSpeed);
  analogWrite(enB, forwardSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft()
{
  analogWrite(enA, turnSpeed);
  analogWrite(enB, turnSpeed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight()
{
  analogWrite(enA, turnSpeed);
  analogWrite(enB, turnSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopRobot()
{
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


int lookLeft()
{
  radarServo.write(0);
  delay(500);
  int distance = getDistance();

  Serial.print("left:");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}

int lookRight()
{
  radarServo.write(180);
  delay(500);
  int distance = getDistance();

  Serial.print("right:");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}
