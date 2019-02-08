# Auto-Detection Security (Lock)

**Author(s)**: *Raymond Okyere-Forson & Elyor Tukhtasinov*

**Google Document**: *https://docs.google.com/document/d/1EXmQ7teX7KDZrPH5cdPVMI5438ql7kau7XEo_zoTTfA/edit?usp=sharing*

---
## Purpose
*Did you forget to lock? LockPro v1 has your back!*

Elyor's roommate frequently forgets to lock the door. Unfortunately, the dorm room doors in the Deep Green Residence Hall do not autolock themselves after left unlocked for an unreasonable amount of time, i.e. more than 30 seconds. The problem is that somebody else can access the dorm room and potentially steal Elyor's and/or his roommate's belongings. LockPro v1 will auto-lock the door after it has been left unlocked for 30 seconds.

## Initial Design Plan
*To build LockPro v1, we will be using different hardware components along with the master code that will run the entire operation.*

- Arduino UNO
- Breadboard
- Relay
- Magnetic Lock (MagLock)
- Button
- Buzzer (5V)
- Power Supply (12V)
- Power Probes
- Connecting wires (Jumper Wires)
- Jumper Cables
- USB to micro USB cable
________________________________________________________________________________________________________________________________________

- Initializing constant and global variables
- Assigning pins to the appropriate components
- Turning on or off MagLock with a button

*Please see attached file: LockPro_Start_Code.ino to view full pseudocode.*


**Breadboard**:

![This is the breadboard view of project](images/bb_update.png)

**Schematic**:

![This is the schematic view of project](images/schem_update.png)

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

This project took us around 25 hours, and we were able to create a working lock system with automatic lock and emergency unlock features. As we worked on this project, we had to narrow down its scope, namely forgo the idea of being able to unlock the door using voice, vibration or keypad password as well as the idea of having a door sensor check whether the door is shut. This happened due to challenges presented by the hardware that we needed for an operatable autolock function.

At the prototype stage, after experimenting with a mock lock mimicked by an LED (off-open and on-locked), we received a magnetic lock and realized that the lock needs a 12V power supply, while the microcontroller is limitted to 5V. Therefore, we had to implement a relay to be able to control the maglock with the Arduino microcontroller. Due to scope limitatiomns, we replaced voice/sound/password lock/unlock feature, which we planned as an emergency feature to override the mechanism and unlock the door, with a simple button. We also experimented with a switch/door-sensor to design the feature that would autolock the door if the door sensor (or mimicked door sensor by a switch) shows that the door is shut but unlocked. However, we struggled with figuring out how to implement the door sensor, and agreed that the door sensor is out of the scope of the core problem that we are trying to solve, i.e. autolocking the lock after it was left open for 30 seconds. Therefore, we decided to let the door sensor go. At first we did not have an emergency unlock button, and our door-sensor/switch was inserted in between the microntroller and the relay, which controlled the current flow mechanically. We progressed with that and disconnected the emergency button from the relay and wired it exclusively to the to the microcontroller. We implemented the code to allow for control of the relay and respectively the lock via microcontroller based on the input from either emergency button or the program we wrote and loaded into the microcontroller. Last, we implemented a buzzer to enhance our autolock feature by making the autolock device notify the user by making sound when the lock is either locked or unlocked.

Along the way, we had troubles with proper wiring as well as scope and experience limitations. Nevertheless, we were able to overcome these challenges and solve the core problem.

## Instructions

- First, ensure that the button, buzzer, relay and arduino have all the proper connections.
- The normal state of the lock is being on or locked always. (This simulates poeple being indoor or outdoor and not interfering)
- To unlock the lock, press the button. The lock unlocks as you hear the buzzer sound.
- After the lock is unlocked, you have 30 seconds until it locks back again. You will hear the buzzer sound when the lock autolocks.

## Errors and Constraints

- There is no security mechanism implemented to unlock the door with a key or a password.
- If the door is still open and more than 30 seconds passes, the lock will lock itself anyway. To lock the door properly, the user will have to unlock the lock, close the door and wait for 30 seconds until the lock autolocks.

## Reflection

This project has been a daunting but great learning experience. Taking a course on electricity and electronics at the same time, we were glad that we already touched a breadboard and a multimeter before building our first embedded system solution. However, apart from dealing with wiring issues and taking measurements, we learned how code and electronic components interact by means of electric signals, and how to use these pieces of technology to build smart electronic devices. We found that taking both classes at the same time is helpful and immersive.

It was daunting to jump into first project with beginner knowledge and skills, but we got to appreciate the approach that this course is designed around. We learned by researching and solving problems as they appeared. First, we had a difference in voltage requirements between the maglock and the microcontroller, which we learned how to solve, i.e. by adding a relay and an additional power supply to our design. In addition, Elyor never used GitHub outside of C++ IDE, so he learned how to use GitHub and appreciated the benefits it offers for team projects.

Lastly, we got a valuable experience of handling scope limitations of a project. Identifying what is relevant and irrelevant is more challenging than it may seem. For example, we struggled to include the door sensor into our autolock structure but then realized that although the autolock and door sensor are closely related, they solve separate atomic problems. Autolock just locks the door after it has been unlocked for 30 seconds, while the door sensor solves the problem of whether the door is shut or not before locking it. Therefore, we decided to forgo the door sensor feature and focus on the core problem that we identified.

## References

- Assistance was received from Cody Mitchell, Teaching Assistant, and Dr. Scott Heggen, course instructor
- Explored sensor (to determine whether Red or Green LED (lock imitation)): https://startingelectronics.org/articles/arduino/measuring-voltage-with-arduino/
- Explored piezoelectric sensor (learned about it in the Arduino: examples>sensors>knock): https://youtu.be/1SNC3ib10_4
- Explored voice-control features enabled by Arduino: https://www.instructables.com/id/How-to-Make-Voice-Controlled-LEDs-Using-Arduino/
- Explored voice-control features enabled by Arduino: https://play.google.com/store/apps/details?id=appinventor.ai_nitinpandit_00.Arduino_bluetooth_voice_controller&hl=en_IN
- Explored how relay works with arduino: https://randomnerdtutorials.com/guide-for-relay-module-with-arduino/


## Final Self-Evaluations

### Ideation, Brainstorming, Design:

*Partner 1 Elyor Tukhtasinov: 5*

*Partner 2 Raymond Okyere-Forson: 5*

### Code creation: 

*Partner 1 Elyor Tukhtasinov: 5*

*Partner 2 Raymond Okyere-Forson: 5*

### Documentation creation:

*Partner 1 Elyor Tukhtasinov: 5*

*Partner 2 Raymond Okyere-Forson: 5*

### Teamwork & Participation:

*Partner 1 Elyor Tukhtasinov: 5*

*Partner 2 Raymond Okyere-Forson: 5*

