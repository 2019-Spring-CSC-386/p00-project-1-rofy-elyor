/*
 Initial code borrowed from:
 Blink
  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Blink

  MagLockPro Auto-Detection Security (Lock System)
  This code ALWAYS has the magnetic lock on or locked, unless a button is pressed to cause a state change which unlocks the magnetic lock. 
  The lock stays unlocked for 30 seconds and then auto-locks. 
  There is a buzzer sound as the state of the magnetic lock changes, thus, when it locks and unlocks.

  ***void buzz() function borrowed from toneMelody example file and then modified to sync with lock and unlock
*/

/*************************************************
 * Public Constants
 *************************************************/
// notes defined here because including another file was not working as expected (had issues with no such file or directly)
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// the setup function runs once when you press reset or power the board

boolean alreadyRun = false; // set initial status to time buzzer

void setup() {
  // initialize digital pin  as an output.
  pinMode(7, OUTPUT); // this connects the relay to the magnetic lock (MagLock)
  pinMode(13, INPUT); // this connects the button
  Serial.begin(9600); // set the rate for communication
  digitalWrite(7, HIGH); // set the initial state of the magnetic lock through the relay as on
  digitalWrite(13, LOW); // set the initial state of the button as off
}

// this function makes the buzzing sound as the magnetic locks and unlocks
void buzz(){
  // notes in the melody:
  int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };
  
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
  };
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  if (alreadyRun == false){
    alreadyRun = true;
  }
  else{
    alreadyRun = false;
    } 
}

// this function controls the state of the magnetic lock through the button press
void lockOnOff(){
 Serial.println("Locking the door"); // Print in serial monitor to help track when door is locking
 digitalWrite(7, HIGH); // Lock MagLock

// Use button to unlock door a.k.a MagLock
Serial.println("Unlocking the door"); // Print in serial monitor to help track when door is unlocking
  if (digitalRead(13)==HIGH){ // if button is pressed then...
    digitalWrite(7, LOW); // set the magnetic lock state to off, thus, unlock
    if (alreadyRun == false)
  {
    buzz(); // call buzz funtion to set off buzzer
  }
    delay(30000); // waits for 30 seconds and then locks again
    }
  else {
    digitalWrite(7, HIGH);
    if (alreadyRun == true)
  {
    buzz(); // call buzz funtion to set off buzzer
  }
    }
}

// the loop function runs over and over again forever
void loop() {
lockOnOff(); // call the main function that runs the system
}
