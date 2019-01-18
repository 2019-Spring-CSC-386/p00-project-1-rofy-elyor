/*
This is the pseudocode for the LockPro v1 for the Sound Detection Security System.

Source: https://www.instructables.com/id/How-to-Make-Voice-Controlled-LEDs-Using-Arduino/ & http://www.arduino.cc/en/Tutorial/Knock
*/

// include Serial for software and initialize variables for Bluetooth connection
// initialize constant for the voice command
// declare pin numbers for LED connection
#include <SoftwareSerial.h>

String voice;

int BL1 = 11; 
int BL2 = 12;

int Red = 3;  // connect to pin #3
int Green = 4;  // connect to pin #4

// bind the two constants for bluetooth connection
SoftwareSerial bluetooth(BL1, BL2);

// these constants won't change:
const int ledPin = 13;      // LED connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
  // setup code that will run once:
  // declare output pins

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // declare Serial and bluetooth rates to initiate communication

  Serial.begin(9600); // start Serial communication at 9600bps
  bluetooth.begin(9600); // set the rate for the bluetooth communication at 9600bps

}

void loop() {
  // main program code that will run repeatedly:

  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  // we check first to see if bluetooth is on and there is an available byte to read as well
  while (Serial.available() && bluetooth.available()) {
    // delay the program a bit to stabilize things
    delay(20);
    // we assign the voice variable to the string message that is gotten from the smartphone command app
     voice = bluetooth.readString();
     // turn on the red LED if we hear this voice command
     if (voice == "lock door"){
      digitalWrite(3, HIGH);
     }
     // turn on the green LED if we hear this voice command or hear a special knock pattern with the vibrating sensor
     else if (voice == "unlock door" || sensorReading > 0 && sensorReading >= threshold){
      digitalWrite(4, LOW);
     }
     // rest the voice command variable and the knock pattern variable
     else {
      delay(5);
      voice = "";   // reset the voice variable again
      sensorReading = 0;
     }
  }

}
