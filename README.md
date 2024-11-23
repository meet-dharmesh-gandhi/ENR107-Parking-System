# ENR107-Parking-System

Overview
--------
This project is an Arduino-based system to monitor the availability of parking spaces using IR sensors, LEDs, and an LCD display. Each parking spot is monitored by an IR sensor, and the system indicates whether a spot is free or occupied.

Key Features:
- IR Sensors: Detect the presence of a vehicle in each parking spot.
- LED Indicators:
  - Green LED indicates a free spot.
  - Red LED indicates an occupied spot.
- LCD Display: Shows the status of all three parking spots in real-time.

Circuit Components
-------------------
- 1x Arduino board
- 1x 16x2 LCD display
- 3x IR sensors
- 3x Green LEDs
- 3x Red LEDs
- Resistors (as needed for LEDs)
- Jumper wires
- Breadboard

Pin Configuration
-----------------
| Component      | Arduino Pin |
|----------------|-------------|
| **IR Sensors** |             |
| IR1            | A3          |
| IR2            | A0          |
| IR3            | 10          |
| **Green LEDs** |             |
| G1             | A4          |
| G2             | A1          |
| G3             | 9           |
| **Red LEDs**   |             |
| R1             | A5          |
| R2             | A2          |
| R3             | 8           |
| **LCD Pins**   |             |
| RS             | 12          |
| Enable         | 11          |
| D4             | 5           |
| D5             | 4           |
| D6             | 3           |
| D7             | 2           |

Functionality
-------------
1. Each parking spot is monitored by an IR sensor to detect vehicle presence.
2. Status is indicated by LEDs:
   - Green LED: Spot is free.
   - Red LED: Spot is occupied.
3. The LCD displays the real-time status of all parking spots.

Example Display:
S1: FIL, S2: EMP S3: FIL

Installation
------------
1. Connect all components as per the Pin Configuration table.
2. Upload the provided code to your Arduino board using the Arduino IDE.
3. Power the Arduino to start the system.

Code Explanation
-----------------
**Functions**:
- `input(pin)`: Configures the specified pin as an input (used for IR sensors).
- `output(pin)`: Configures the specified pin as an output (used for LEDs).
- `setS1(pin1, pin2, mode1, mode2, newS1, newS2, newS3)`: Updates the LEDs and LCD display based on the parking status.
- `isIR(pin, mode, s, val)`: Checks if the IR sensor detects a change in the parking spot's state.

**Loop Logic**:
- Continuously monitors the state of each IR sensor.
- Updates the LEDs and LCD display if a state change is detected.

Dependencies
------------
This project uses the **LiquidCrystal** library for controlling the LCD. Ensure it is installed in your Arduino IDE.

How to Run
----------
1. Connect your Arduino to your computer via USB.
2. Upload the code to your Arduino.
3. Observe the LCD and LED indicators to monitor parking spot status.

Notes
-----
- Adjust the IR sensor placement and sensitivity for accurate vehicle detection.
- Use resistors to protect the LEDs and ensure correct brightness.

This project can be expanded to include additional parking spots or features such as network connectivity for remote monitoring.
