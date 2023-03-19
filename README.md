# Automatic Control for Lights
> via Person Counter using Ultrasonic Sensors

### 1. INTRODUCTION
This project  is made using Arduino Uno for controlling the room lights as well as counting how many people entering the room accurately. The counter is incremented when 
the person enters the room by ‘1’ and the light will turn ‘ON’. The counter is decremented when the person exits the room and the light will turn ‘OFF’. The LCD display will display the total number of people inside the room as well as the status of Lights.The Ultrasonic Sensor is used to detect no. of people entering and leaving the room. Also, only Half of the lights are switched ON for number of persons less than 10 (Hard Coded Threshold).

### 2. Circuit Connections (in Proteus)
<p align="center">
<h3 align=center>Overall Connections</h3>
<img src=https://user-images.githubusercontent.com/98400026/226192490-b9be19ea-6145-4c91-97f2-bd3a730269e4.png>
<h3 align=center>Utrasonic Sensors</h3>
<img src=https://user-images.githubusercontent.com/98400026/226192516-e0da7d28-9897-4129-bb78-dcd6d179b548.png>
<h3 align=center>Simulater of Distances of Utrasonic Sensosrs using Variable Resistances</h3>
<img src=https://user-images.githubusercontent.com/98400026/226192531-f9c28bf3-a122-4db2-85ba-182adcccc742.png>
<h3 align=center>16x2 LCD Display</h3>
<img src=https://user-images.githubusercontent.com/98400026/226192541-2cdaa9b8-c7e5-41b6-8282-c59564cafca4.png>
<h3 align=center>SPST Realys</h3>
<img src=https://user-images.githubusercontent.com/98400026/226192550-25fefa83-c7c3-4078-a26e-776d7684396e.png>
<h3 align=center>LED connections</h3>
<img src=https://user-images.githubusercontent.com/98400026/226192562-f547d624-a090-4225-b544-db9541fe28e2.png>
</p>

### 3. Working Principle
* The Two Ultrasonic sensors are used to sense the direction of motion of person (inside or outside)
* When the first sensor detects a nearby object then it waits for the next sensor if it senses the same. 
* If the sense on other sensor is same then the counter is incremented
* When the order of sensing is reversed then the counter is decremented
* Also the Hardcoded threshold states that only half of the lights are switched on for less than 10 persons inside the room.

### Limitation 
* It can't detect if two persons enter or leave the room simultaneously.
* It can also count objects as persons
