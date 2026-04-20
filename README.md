# Bionic Mirror Hand
An Arduino-based robotic hand that mimics human finger movements using a flex-sensor glove.

## Tech Stack
* **Microcontroller:** Arduino Uno
* **Power:** DC-DC Buck Converter (Step-down to 5V)
* **Actuators:** 5x Servo Motors
* **Sensors:** 5x Flex Sensors (Voltage Divider Circuit)

## Key Features
* **Custom Calibration:** Handles narrow sensor ranges (13-point swing) using mapped logic.
* **Signal Smoothing:** Uses an exponential moving average filter to prevent servo jitter.
* **Stable Power:** Integrated buck converter to manage high current draw from 5 servos.

##  Pin Mapping
| Finger | Analog Pin | Digital Pin |
| :--- | :--- | :--- |
| Thumb | A1 | 2 |
| Index | A3 | 3 |
| Middle | A2 | 4 |
| Ring | A4 | 11 |
| Pinky | A5 | 6 |
