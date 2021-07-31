# IoT based Intelligent Clothes Wardrobe – Automated Motorized Cloth Dryer System

A smart clothes drying rack was built from scratch to automate natural clothes drying process. The rack was designed as a wardrobe with wheels and a collision detection system. It was designed to detect sunlight and optimally position itself to speed up natural drying process within a bounded region. The system had a rain detection sensor which triggered side panels to open and close to protect the clothes from the rain. The wardrobe was connected to the internet to remotely control it using a simple android app.

## Project Modules

A detailed explanation of each module of this system is available in the report. This readme will briefly introduce each part and list the components used.

### Structural Design
The frame of the wardrobe was made using aluminum and the body was made using plywood. It had the following dimensions:
- Height: 110cm
- Width: 88.5cm
- Length: 51cm
- Weight: 13kg

### Mobility
The system was designed with an Arduino MEGA R3 2560 at its core. For mobility, two 12V DC motors with a rated torque of 19kg/cm was used. These motors were mounted to the rear of the wardrobe and a caster wheel was placed on the front. An L298N Dual H Bridge DC motor driver module was used to connect the motor to the Arduino. A 12V Li-Po battery was used to power the system.

List of Components:
- Arduino MEGA R3 2560 - x1
- 12V Li-Po battery - x1
- 12V DC motors (JGB37-3530) - x2
- 8cm Wheels - x2
- Caster wheel - x1

### Boundaries and Low-cost Collision Detection System
For this project, the wardrobe was designed to perform within a bounded region. TCRT5000 IR sensors which uses LM393 comparator was used to detect the line of the bounded region. HC-SR04 ultrasonic sensors were use to create a low-cost collision detection system to avoid colliding with objects within the bounded region. 

List of Components:
- TCRT5000 IR Sensors - x4
- HC-SR04 - x4

### Detecting Optimal Sunlight
LDR sensors were mounted on top of the wardrobe to detect sunlight. The PCB for the sensor was designed using Eagle Lite and printed in the lab. 

List of Components:
- LDR Sensor - x4
- 10k potentiometer - x4

### Rain Detection
A rain sensor was used mounted on top of the wardrobe to detect rainfall. The sides of the wardrobe were open but covered with a waterproof fabric made of PUL to act as shutters. 12V DC motors with higher RPM were used to open and close the sides in case of rain.  

List of Components:
- Rain Sensor - x1

### Wireless Connectivity 
NodeMCU with ESP8266 WiFi microchip was used to connect the system to the internet for remote connectivity and control. A simple Android app was designed to send messages to control the movement and shutters of the wardrobe.

List of Components:
- NodeMCU - x1

## Usage 
The report has a detailed explanation on how to combine all the modules and program the Arduino to create this system. Flowcharts and circuit diagrams are available in the Schematics folder to help you understand the working principles. 

## Future Work
This project can be expanded by improving the design and performance of the wardrobe so that it can be used as a smart furniture. As the wardrobe was designed to work within a bounded region, limitations on locating residence can be solved with the help of a camera and deep learning algorithms. Also, since the LDR sensors are used to detect sunlight, solar panels can be installed onto the system which can further save energy consumption.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
