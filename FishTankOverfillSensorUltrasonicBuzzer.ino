/*
 * Fish Tank Overfill Sensor
 * Ultrasonic & Piezo Buzzer
 * Intended for Arduino Nano, should also work for Uno & Mega.
 * Copyright (C) Brian Woo-Shem
 * 2021-09-11
 * v1.1
 *
 * https://github.com/bwooshem/DIY-Arduino-Tank-Pool-Overfill-Alarm
 *
 * Wiring: Ultrasonic Sensor -> Arduino:
 * - VCC  -> 5VDC
 * - TRIG -> Pin 9
 * - ECHO -> Pin 8
 * - GND  -> GND
 *
 * Wiring: Piezo -> Arduino:
 * - Pin 3 -> 100 Ohm Resistor -> Piezo -> Ground
 *
 * 
 *  This program is free software: you can redistribute it and/or modify it under the terms of the 
 *  GNU General Public License version 3 as published by the Free Software Foundation.
 *  
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without 
 *  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 *  GNU General Public License at https://www.gnu.org/licenses/gpl-3.0.en.html for more details.
 */

int trigPin = 9;    // TRIG pin
int echoPin = 8;    // ECHO pin
const int piezo = 3;
const int warning = 5; //cm
const int alarm = 3; //cm


float duration, distance, d;

void setup() {
  // begin serial port for debugging. Line can probably be removed.
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);

  pinMode(piezo, OUTPUT);
}

void loop() {

  // Get distance in cm
  d = ultradist(trigPin,echoPin);
  // If distance less than 10cm
  if (d < warning){
    // If distance less than alarm cm, play alarm
    if (d < alarm){
      // Play high alert sound in Hz (A4 and E5) in 1s on, 1s off pattern
      tone(piezo, 440);
      delay(1000);
      tone(piezo,659.3);
      delay(1000);
      noTone(piezo);
    }
    else{
      // Warning
      //Play gentle alert sound in Hz (G3) in 0.3s on, 1.7s off pattern
      tone(piezo, 196);
      delay(300);
      noTone(piezo);
      delay(1700);
    }
    
  }

  delay(5000); //Wait 5s before next alarm sound; remove if you want the alarm to be harder to ignore.
}


// Function for the Ultrasonic sensor to read different distances. Returns distance in cm
float ultradist(int trigPin, int echoPin){
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
    
      // measure duration of pulse from ECHO pin
      duration = pulseIn(echoPin, HIGH);
    
      // calculate the distance
      d = 0.017 * duration;
      // Print current ultrasonic reading to the monitor for debugging purposes; comment out if not needed
      //Serial.println(d);
      return d; //current distance
}
