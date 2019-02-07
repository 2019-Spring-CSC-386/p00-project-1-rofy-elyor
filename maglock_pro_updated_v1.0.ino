/*
  Blink
  Turns an LED on for one second, then off for one second, repeatedly.
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products
  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
  digitalWrite(7, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(13, LOW);
}

/*void lockOnOff(){
  if (digitalRead(2)== LOW){
    digitalWrite(7,LOW);
  } 
  else {
    delay(5000);
    digitalWrite(7, HIGH);
    }
}*/

void lockOnOff(){
 Serial.println("Locking the door"); // Print in serial monitor to help track when door is locking
 digitalWrite(7, HIGH); // Lock MagLock
 /*if (digitalRead(2)== LOW){
  delay(1000);
  digitalWrite(7, LOW);
  delay(1000);
 }  else {
  digitalWrite(7, HIGH);
  delay(1000);
  }*/
 //digitalWrite(7, HIGH);
 //delay(3000);

// Use button to unlock door a.k.a MagLock
Serial.println("Unlocking the door"); // Print in serial monitor to help track when door is unlocking
  if (digitalRead(13)==HIGH){
    //delay(5000);
    digitalWrite(7, LOW);
    delay(5000);
    }
  else {
    digitalWrite(7, HIGH);
    //delay(2000);
    }
  /*else if (digitalRead(2)==HIGH){
      digitalWrite(7, HIGH);
      delay(2000);
      }
  else if (digitalRead(13)==HIGH){
    digitalWrite(7, LOW);
  }
  else{
    digitalWrite(7, HIGH);
    }
    
 /*delay(1000);
 digitalWrite(7, LOW);
 delay(1000);
 /*if (digitalRead(7)==LOW){
  delay(5000);
  digitalWrite(7, LOW);
  }*/
}

/*void openOnOff(){
  /*if (digitalRead(7) == HIGH){
    delay(5000);
    digitalWrite(7, LOW);
    }
  else {
    digitalWrite(7, LOW);
    }
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
  }*/

// the loop function runs over and over again forever
void loop() {
lockOnOff();
// Added a dor sensor to print when the "door" was opened or closed
int doorSensor = digitalRead(2);
//Serial.println(doorSensor);
//openOnOff();
}
