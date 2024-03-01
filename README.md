# Gesture-Controlled Robot Car

## Description
This project involves controlling a robot car using gestures detected by a glove equipped with sensors. The car's movement is controlled wirelessly via a WiFi connection, with commands sent from the glove to the car.

## Files
- `car.ino`: Arduino sketch for the robot car, responsible for receiving commands via WiFi and controlling the car's movements accordingly.
- `glove.ino`: Arduino sketch for the gesture-sensing glove, responsible for detecting gestures and sending corresponding commands to the robot car.

## How It Works
1. The glove captures hand gestures using sensors (e.g., accelerometers, flex sensors).
2. Detected gestures are translated into commands (e.g., forward, backward, left, right).
3. Commands are transmitted wirelessly to the robot car via a WiFi connection.
4. The robot car receives the commands and moves accordingly, controlling its motors to drive in the desired direction.

## Hardware Requirements
- Robot car chassis with motor drivers and WiFi module (e.g., ESP8266 or ESP32).
- Gesture-sensing glove with appropriate sensors.
- Power supply for both the robot car and the glove.

## Installation and Setup
1. Upload the `car.ino` sketch to the Arduino board connected to the robot car's microcontroller.
2. Upload the `glove.ino` sketch to the Arduino board connected to the gesture-sensing glove.
3. Connect the robot car and the glove to power sources.
4. Ensure that the WiFi credentials in the `car.ino` sketch match your network settings.
5. Power on both the car and the glove, and establish a WiFi connection.

## Usage
1. Put on the gesture-sensing glove.
2. Perform predefined gestures to control the movement of the robot car.
3. The robot car should respond to the gestures by moving accordingly.

## Credits
This project was created by Varun Ajith, Pranav Jayan, Emin Tomson, Rixon Sunny.

## License
This project is licensed under the [MIT License](LICENSE).
