# InnoElevate
An arduino 

TUESFEST 2024 Project: Smart Cabin Controller
Welcome to the GitHub repository for our TUESFEST 2024 project, the Smart Cabin Controller. This project leverages the power and versatility of the Arduino Uno to create an intelligent cabin control system. The system includes a DC motor, a 12V generator, eight buttons, and an ultrasonic sensor to determine the exact location of the cabin.

Project Overview
The Smart Cabin Controller is designed to manage and control the movement of a cabin with precision and efficiency. Here’s a detailed breakdown of the components and functionality:

Components
Arduino Uno: Chosen for its large number of pins, it serves as the main controller.
DC Motor: Drives the movement of the cabin.
12V Generator: Powers the DC motor.
8 Buttons: Four buttons are placed inside the cabin and four outside, allowing for multiple control points.
Ultrasonic Sensor: Determines the exact location of the cabin, ensuring precise control.
Functionality
The system is designed using interrupts and C++ classes to ensure robust and efficient operation. The codebase is divided into two main parts:

Firmware Control: This part of the code manages the hardware interactions, such as reading button presses and controlling the motor.
Logical Calculations: This part handles the calculations for the cabin's movement and positioning, ensuring accurate and smooth operation.
Code Structure
The code is systemized and highly modular, leveraging C++ classes for better organization and maintenance. Here’s a brief overview of the key classes:

ButtonController: Manages the state and interactions of the eight buttons.
MotorController: Handles the operation of the DC motor.
SensorController: Reads data from the ultrasonic sensor and calculates the cabin's position.
CabinLogic: Integrates inputs from the buttons and sensor to control the motor, ensuring the cabin moves to the desired location.
Key Features
Interrupt-Driven Design: Ensures that the system responds quickly to button presses and sensor readings without unnecessary delays.
Class-Based Organization: Makes the code more readable, maintainable, and scalable.
Precise Control: The ultrasonic sensor provides accurate positioning, and the logical calculations ensure smooth movement.
Getting Started
To get started with this project, clone the repository and follow the instructions in the README to set up your hardware and upload the code to the Arduino Uno.

sh
Копиране на код
git clone https://github.com/YourUsername/SmartCabinController.git
Contributing
We welcome contributions to enhance the functionality and performance of the Smart Cabin Controller. Please fork the repository and create a pull request with your improvements.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Join us in creating a smarter, more efficient cabin control system and showcase your skills at TUESFEST 2024!
![image](https://github.com/Atefan/InnoElevate/assets/127405883/c4e67d90-f140-4ff5-bb8c-3d4b69de58f4)
![image](https://github.com/Atefan/InnoElevate/assets/127405883/cbacb628-671a-4e5d-a88b-42f4a8562376)
![image](https://github.com/Atefan/InnoElevate/assets/127405883/43ae4c15-0d33-4c39-b53d-5a96377e62e4)
![image](https://github.com/Atefan/InnoElevate/assets/127405883/7b75f7b6-926f-4d61-839a-3817e027de54)
