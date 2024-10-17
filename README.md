# Parking-System
This repository contains the implementation of a Parking System using ultrasonic sensors and an ATmega32 microcontroller. The system detects obstacles and provides real-time warnings to assist in safe parking.

Features
Ultrasonic Sensor Integration: Measures the distance between the vehicle and nearby obstacles.
Proximity Alerts: Five states based on distance:
Idle
Detecting
Safe
Warning
Danger
Real-time Feedback: Displays distance information and alerts through visual and audio indicators.
Software Architecture
This project follows a layered software architecture:

MCAL (Microcontroller Abstraction Layer):

GPIO Driver: Handles digital input/output operations for controlling sensors and actuators.
ICU (Input Capture Unit) Driver: Captures and processes ultrasonic sensor pulse timings for distance measurements.
Register Definitions: Uses bit-field definitions for direct access to ATmega32 registers.
HAL (Hardware Abstraction Layer):

Buzzer Driver: Controls the buzzer for warning alerts.
LCD Driver: Displays distance and state information.
LED Driver: Provides visual feedback for proximity alerts.
Ultrasonic Driver: Manages ultrasonic sensor operations and processes distance measurements.
Getting Started
Hardware Required:
Ultrasonic Sensor (e.g., HC-SR04)
ATmega32 Microcontroller
LCD Display
Buzzer/LED for warnings
Steps:
Clone the repository:
bash
Copy code
git clone https://github.com/IbrahimMohsenMoussa/Parking-System.git
Set up hardware: Connect the ultrasonic sensor, LCD, buzzer, and LEDs to the ATmega32 microcontroller.
Compile and upload code using an AVR-compatible IDE like Atmel Studio.
Distance Thresholds:
Idle: Distance > 100 cm
Detecting: 70 cm < Distance <= 100 cm
Safe: 40 cm < Distance <= 70 cm
Warning: 20 cm < Distance <= 40 cm
Danger: Distance <= 20 cm
Usage
Adjust the distance thresholds in the code or modify the sensor readings to fit specific use cases.
Compile the project and observe real-time distance feedback on the LCD display with audio/visual warnings.
Contributing
Contributions are welcome! Feel free to submit issues or pull requests.
