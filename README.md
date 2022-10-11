# DIY-Arduino-Tank-Pool-Overfill-Alarm
CC-By-NC-SA [Brian Woo-Shem](https://www.brianwooshem.com): Design & programming for calibration tool, documentation, testing and validation.

Alarm when a pool, fish tank, or other reservoir filled via hose is about to overflow. Uses Arduino and Ultrasonic sensor.

![Overfill alarm in use](https://github.com/bwooshem/DIY-Arduino-Tank-Pool-Overfill-Alarm/blob/main/FishTankOverfillAlarm.png)

The original device was built after a giant fish tank I fill via hose overflowed because nobody was paying attention. After cleaning up the mess, I decided to build a sensor to prevent such accidents. Ultrasonic is a good choice because it bounces sound waves off of another surface and detects how long it takes to reflect back. The water has sufficiently different speed of sound, so it acts as a practically solid surface. Thus, there is no need to physically touch or put anything in the water to detect it.

The 3D printed mount fits my particular fish tank; the .STL and .SLDPRT files are included so others can modify it to fit their systems. Feel free to fork or create a pull request with CAD for mountings to other things. 

With a little creativity, mounts or connectors to swimming pools, ponds, and other things can be made; the only requirement is the Ultrasonic must be perpendicular to and directly above the water.

## Materials
- Arduino: Nano, Uno, or Mega will all work
- Ultrasonic Sensor HC-SRO4
- Piezo Buzzer
- 4x In-Out jumper wires
- 3x out-out jumper wires
- Small breadboard
- Resistor: 100Ω-10kΩ
- 3D Printed mounting (optional)

## Instructions

1. Wire the Ultrasonic Sensor -> Arduino:
    1. VCC  -> 5VDC
    1. TRIG -> Pin 9
    1. ECHO -> Pin 8
    1. GND  -> GND

2. Connect the resistor to pin D3 (you can use any PWM pin as long as you change the variable in _FishTankOverfillSensorUltrasonicBuzzer.ino_).
3. Connect the piezo to the other side of the resistor
4. Connect the other leg of the piezo to GND
5. Load _FishTankOverfillSensorUltrasonicBuzzer.ino_ onto the Arduino. Use Arduino IDE, see this [guide](https://www.arduino.cc/en/Guide/Environment) if you are unfamiliar with it.
6. (Optional) mount onto 3D printed clip

Also see the [circuit on TinkerCAD](https://www.tinkercad.com/things/g29VphFcNcn)

![Circuit Diagram](https://github.com/bwooshem/DIY-Arduino-Tank-Pool-Overfill-Alarm/blob/main/Arduino_Fishtank_Overfill_Alarm_Sensor_Circuit.png)

![Circuit Schematic](https://github.com/bwooshem/DIY-Arduino-Tank-Pool-Overfill-Alarm/blob/main/Arduino_Fishtank_Overfill_Alarm_Sensor_Schematic.png)

## License

All text, graphics, and non-code content is licensed [CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/)    
All code is licensed under the [GNU General Public License v3](https://www.gnu.org/licenses/gpl-3.0.en.html)

RTClib and Adafruit_SCD30 are Copyright (c) Adafruit Industries and used under the open source MIT license.   
Arduino IDE and related components are open source and licensed under the GNU GPL v2 and/or CC BY-SA Arduino.
