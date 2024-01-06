#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;

const int leftMotorPin1 = 5;  // Connect left motor pins to Arduino
const int leftMotorPin2 = 6;
const int rightMotorPin1 = 9; // Connect right motor pins to Arduino
const int rightMotorPin2 = 10;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  if (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial.println("Failed to initialize MPU6050!");
    while (1);
  }

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Threshold values for gesture detection (adjust as needed)
  const int threshold = 5000;

  if (ay > threshold) { // Wrist facing upward
    moveForward();
  } else if (ay < -threshold) { // Wrist facing downward
    slowDown();
  } else if (ax > threshold) { // Wrist facing left
    turnLeft();
  } else if (ax < -threshold) { // Wrist facing right
    turnRight();
  } else {
    stopMoving();
  }
}

void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void slowDown() {
  analogWrite(leftMotorPin1, 150); // Adjust the speed as needed
  analogWrite(leftMotorPin2, LOW);
  analogWrite(rightMotorPin1, 150);
  analogWrite(rightMotorPin2, LOW);
}

void turnLeft() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void turnRight() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

void stopMoving() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}
  