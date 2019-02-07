# Auto-Detection Security (Lock)

**Author(s)**: *Raymond Okyere-Forson & Elyor Tukhtasinov*

**Google Document**: *https://docs.google.com/document/d/1EXmQ7teX7KDZrPH5cdPVMI5438ql7kau7XEo_zoTTfA/edit?usp=sharing*

---
## Purpose
*Did you forget to lock? LockPro v1 has your back!*

Elyor's roommate frequently forgets to lock the door. Unfortunately, the dorm room doors in the Deep Green Residence Hall do not autolock themselves after left unlocked for an unreasonable amount of time (more than 5 minutes). The problem is that somebody else can access the dorm room and potentially steal Elyor's and his roommate's belongings. LockPro v1 will auto-lock the door after it has been left unlocked for 30 seconds. The lock also has an override button to unlock the door.

## Initial Design Plan
*To build LockPro v1, we will be using different hardware components along with the master code that will run the entire operation.*

- Arduino UNO
- Breadboard
- Relay
- Magnetic Lock (MagLock)
- Button
- Door Sensor
- Power Supply (12V)
- Power Probes
- Connecting wires (Jumper Wires)
- Jumper Cables
- Resistor 10 kΩ
- USB to micro USB cable
________________________________________________________________________________________________________________________________________

- Initializing constant and global variables
- Assigning pins to the appropriate components
- Turning on or off MagLock based on door sensor

*Please see attached file: LockPro_Start_Code.ino to view full pseudocode.*


**Breadboard**:

![This is the breadboard view of project](images/bb.png)

**Schematic**:

![This is the schematic view of project](images/schem.png)

## Files
*The list of all files currently being used in this project.*

- Knock_example.ino: an example of code that uses piezo sensor to sense knocking (vibration)
- README.md: master file where we document everything about our project
- example-README.md: example of the master file with instructions that we have to follow in filling out our README.md
- images (folder): is a folder to store images to be inserted in README.md
- LockPro_Start_Code.ino: our master file for the code that currently contains the pseudocode
- MagLock Code_1.ino: Currently the best version of working code we have so far based on progress
- maglock_pro.ino: Trying to setup an auto-lock function of the system
- maglock_pro_v1.ino: Displaying progress of trying to make the code work
- maglock_pro_updated: Makes button unlock maglock, else it's always locked

## Summary

This project took us around 25 hours, and we were able to create a working lock system with automatic lock and emergency unlock features. As we worked on this project, we had to narrow down its scope, namely forgo the idea of being able to unlock the door using voice, vibration or keypad password. This happened due to challenges presented by the hardware that we needed for an operatable autolock function.

At the prototype stage, after experimenting with a mock lock mimicked by an LED (off-open and on-locked), we received a magnetic lock and realized that the lock needs a 12V power supply, while the microcontroller is limitted to 5V. Therefore, we had to implement a relay to be able to control the maglock with the Arduino microcontroller. We replaced voice/sound/password lock/unlock feature, which we planned as an emergency feature to override the mechanism and unlock the door, with a simple button. We also experimented with a switch/door-sensor to design the feature that would autolock the door if the door sensor (or mimicked door sensor by a switch) shows that the door is unlocked. At first we did not have an emergency unlock button, and our door-sensor/switch was inserted in between the microntroller and the relay, which controlled the current flow mechanically. We progressed with that and disconnected the emergency button and the door sensor from the relay and wired them exclusively to the to the microcontroller. We implemented the code to allow for control of the relay and respectively the lock via microcontroller based on the input from either emergency button or the door sensor.

Along the way, we had troubles with proper wiring as we needed to implement multiple connections to the ground pins. Nevertheless, we were able to overcome our hardware challenges, and our code started working as intended.

## Instructions



## Errors and Constraints



## Reflection
*You'll complete this part at the end of the project.*

Write 2 - 4 paragraphs on your reactions to the final project. 
Your reflection should be thoughtful and reflective. 
It is NOT a report about WHAT you did. 
Instead, it's a look back at what you learned by doing this project.
It should be critical of shortcomings (yours, as well as the instructors/assignments) 
as well as celebratory of what was achieved.

## References

- Assistance was received from Cody Mitchell, Teaching Assistant, and Dr. Scott Heggen, course instructor
- Sensor (Elyor: to determine whether Red or Green LED (lock imitation) is on; an analog pin should serve the purpose) Citation: https://startingelectronics.org/articles/arduino/measuring-voltage-with-arduino/
- Piezoelectric Sensor (Learned about it in the Arduino: examples>sensors>knock, googled and found this: https://youtu.be/1SNC3ib10_4)
- General research & useful sources: https://www.instructables.com/id/How-to-Make-Voice-Controlled-LEDs-Using-Arduino/ & https://play.google.com/store/apps/details?id=appinventor.ai_nitinpandit_00.Arduino_bluetooth_voice_controller&hl=en_IN


## Final Self-Evaluations

### Ideation, Brainstorming, Design:

*Partner 1 Elyor Tukhtasinov: 5*

*Partner 2 Raymond Okyere-Forson: 5*

### Code creation: 

*Partner 1 (replace this with your name): 5*

*Partner 2 (replace this with your name): 5*

### Documentation creation:

*Partner 1 (replace this with your name): 5*

*Partner 2 (replace this with your name): 5*

### Teamwork & Participation:

*Partner 1 (replace this with your name): 5*

*Partner 2 (replace this with your name): 5*

