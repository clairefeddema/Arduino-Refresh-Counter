/* Arduino Refresh Counter With Timer
 * 
 * The Arduino Refresh Counter consists of an Arduino Uno board connected to three breadboards by wires. 
 * Two of the breadboards are wired with seven LED diodes arranged in the pattern of a seven-segment display 
 * and the remaining breadboard has a single button. 
 * 
 * The purpose of the Reset Counter is to record the number of times the button is clicked over a period of time. 
 * The two displays initially display the number zero. During a time interval (denoted by timeBase, measured in 
 * milliseconds) the button can be pressed up to 99 times, and during the following interval the number of 
 * button presses will be displayed on the two digit display.
 *  
 *  Written by Claire Feddema on August 14 2020
 */

#include <Event.h>
#include <Timer.h>

// Declarations 

//Creates timer from header file to count milliseconds since program began
Timer t;

// Pins connected directly to the display's tens digit LEDs
int leftLED1 = 9;
int leftLED2 = 11;
int leftLED3 = 10;
int leftLED4 = 12;
int leftLED5 = 7;
int leftLED6 = 6;
int leftLED7 = 8;

// Pins connected indirectly to the display's ones digit LEDs through charlieplexing
int charliePin1 = 5;
int charliePin2 = 4;
int charliePin3 = 3;
int charliePin4 = 2;

// Pin for imput from the button
int buttonPin = 13;

//Variables to keep track of the button's status (pressed or not) currently and 
// previously to compare (in order to know when it goes from pressed to unpressed, 
// which counts as a single button press) 
int buttonNew;
int buttonOld = 1;

// Delay variables in milliseconds
int delayTime = 10;
int d = 1;

//Keeps track of the amount of times the button is pressed in the current and previous interval
int count = 0;
int previousCount = 0;

// The length of each interval in milliseconds
int timeBase = 3000;

//The number currently being displayed in the tens and ones place on the display
int leftDisplayNum = 0;
int rightDisplayNum = 0;


// Changes both pin modes and statuses of each pin used in charlieplexing to turn on each
// of the 7 seperate LEDs on the ones digit of the display
void rightLED1 () {
  pinMode(charliePin1, OUTPUT);
  pinMode(charliePin2, OUTPUT);
  pinMode(charliePin3, INPUT);
  pinMode(charliePin4, INPUT);
  digitalWrite(charliePin1, HIGH);
  digitalWrite(charliePin2, LOW);
}
void rightLED2 () {
  pinMode(charliePin1, INPUT);
  pinMode(charliePin2, OUTPUT);
  pinMode(charliePin3, OUTPUT);
  pinMode(charliePin4, INPUT);
  digitalWrite(charliePin2, HIGH);
  digitalWrite(charliePin3, LOW);  
}
void rightLED3 () {
  pinMode(charliePin1, INPUT);
  pinMode(charliePin2, INPUT);
  pinMode(charliePin3, OUTPUT);
  pinMode(charliePin4, OUTPUT);
  digitalWrite(charliePin3, HIGH);
  digitalWrite(charliePin4, LOW);
}
void rightLED4 () {
  pinMode(charliePin1, OUTPUT);
  pinMode(charliePin2, OUTPUT);
  pinMode(charliePin3, INPUT);
  pinMode(charliePin4, INPUT);
  digitalWrite(charliePin1, LOW);
  digitalWrite(charliePin2, HIGH);
}
void rightLED5 () {
  pinMode(charliePin1, INPUT);
  pinMode(charliePin2, OUTPUT);
  pinMode(charliePin3, OUTPUT);
  pinMode(charliePin4, INPUT);
  digitalWrite(charliePin2, LOW);
  digitalWrite(charliePin3, HIGH);
}
void rightLED6 () {
  pinMode(charliePin1, INPUT);
  pinMode(charliePin2, INPUT);
  pinMode(charliePin3, OUTPUT);
  pinMode(charliePin4, OUTPUT);
  digitalWrite(charliePin3, LOW);
  digitalWrite(charliePin4, HIGH);
}
void rightLED7 () {
  pinMode(charliePin1, OUTPUT);
  pinMode(charliePin2, INPUT);
  pinMode(charliePin3, INPUT);
  pinMode(charliePin4, OUTPUT);
  digitalWrite(charliePin1, HIGH);
  digitalWrite(charliePin4, LOW);
}

// Changes statuses of each pin used for the tens digit of the display 
// to turn on the correct LEDs and display the numbers 0 though 9
void leftDisplay0 () {
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, HIGH); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, LOW); 
    digitalWrite(leftLED5, HIGH); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, HIGH); 
  }
void leftDisplay1 (){
    digitalWrite(leftLED1, LOW); 
    digitalWrite(leftLED2, LOW); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, LOW); 
    digitalWrite(leftLED5, LOW); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, LOW);   
  }
void leftDisplay2 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, LOW); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, HIGH); 
    digitalWrite(leftLED6, LOW); 
    digitalWrite(leftLED7, HIGH);     
  }
void leftDisplay3 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, LOW); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, LOW); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, HIGH);     
  }
void leftDisplay4 (){
    digitalWrite(leftLED1, LOW); 
    digitalWrite(leftLED2, HIGH); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, LOW); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, LOW);     
  }
void leftDisplay5 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, HIGH); 
    digitalWrite(leftLED3, LOW); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, LOW); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, HIGH);     
  }
void leftDisplay6 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, HIGH); 
    digitalWrite(leftLED3, LOW); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, HIGH); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, HIGH);     
  }
void leftDisplay7 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, LOW); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, LOW); 
    digitalWrite(leftLED5, LOW); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, LOW);     
  }
void leftDisplay8 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, HIGH); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, HIGH); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, HIGH);     
  }
void leftDisplay9 (){
    digitalWrite(leftLED1, HIGH); 
    digitalWrite(leftLED2, HIGH); 
    digitalWrite(leftLED3, HIGH); 
    digitalWrite(leftLED4, HIGH); 
    digitalWrite(leftLED5, LOW); 
    digitalWrite(leftLED6, HIGH); 
    digitalWrite(leftLED7, HIGH);     
}

//Calls the correct functions for each individual LED of the ones digit of the display 
// in quick succession to turn on the correct LEDs and display the numbers 0 though 9

// Delays are needed between function calls for each LED otherwise LEDs that are not called turn on
// don't know why or how it works but it does with delays 

void rightDisplay0 () {
  rightLED1 ();
  delay(d);
  rightLED2 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED5 ();
  delay(d);
  rightLED6 ();
  delay(d);
  rightLED7 ();
  delay(d);
}
void rightDisplay1 () {
  rightLED3 ();
  delay(d);
  rightLED6 (); 
  delay(d);
}
void rightDisplay2 () {
  rightLED1 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED5 ();
  delay(d);
  rightLED7 (); 
  delay(d); 
}
void rightDisplay3 () {
  rightLED1 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED6 ();
  delay(d);
  rightLED7 (); 
  delay(d); 
}
void rightDisplay4 (){
  rightLED2 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED6 (); 
  delay(d);
}
void rightDisplay5 () {
  rightLED1 ();
  delay(d);
  rightLED2 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED6 ();
  delay(d);
  rightLED7 (); 
  delay(d); 
}
void rightDisplay6 () {
  rightLED1 ();
  delay(d);
  rightLED2 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED5 ();
  delay(d);
  rightLED6 ();
  delay(d);
  rightLED7 (); 
  delay(d); 
}
void rightDisplay7 () {
  rightLED1 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED6 (); 
  delay(d);
}
void rightDisplay8 () {
  rightLED1 ();
  delay(d);
  rightLED2 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED5 ();
  delay(d);
  rightLED6 ();
  delay(d);
  rightLED7 (); 
  delay(d); 
}
void rightDisplay9 () {
  rightLED1 ();
  delay(d);
  rightLED2 ();
  delay(d);
  rightLED3 ();
  delay(d);
  rightLED4 ();
  delay(d);
  rightLED6 (); 
  delay(d);
  rightLED7 ();
  delay(d);
}


// Resets the count of times the button has been pressed and sets the
// current interval's count to the previous interval's count to be displayed
// also display the previous interval's count in the console 
void counterReset() {
  previousCount = count;
  count = 0; 
  Serial.println(previousCount);
}

// Runs once as the Arduino is plugged in
void setup() {
  // Starts console 
  Serial.begin(9600);
// Sets each pin for the tens digit LEDs to output 
  pinMode(leftLED1, OUTPUT);
  pinMode(leftLED2, OUTPUT);
  pinMode(leftLED3, OUTPUT);
  pinMode(leftLED4, OUTPUT);
  pinMode(leftLED5, OUTPUT);
  pinMode(leftLED6, OUTPUT);
  pinMode(leftLED7, OUTPUT);
  pinMode(buttonPin, INPUT);
  
// Uses the timer t available from the timer header file to run the counterReset
// funtion every timeBase (in milliseconds)
  t.every(timeBase, counterReset, NULL);
}

// Will continue to run as long as the Arduino is plugged in
void loop() {
// Updates the timer t, to keep in running in the setup function
  t.update();

// Reads the state of the button and sets buttonNew to 1 when unpressed or 0 when pressed 
// then checks when the button goes from pressed to unpressed, and adds to the count of button presses
  buttonNew = digitalRead(buttonPin);
  if(buttonOld == 0 && buttonNew == 1){
    count++;
    delay(delayTime);
  }
// Determines the numbers to be displayed in the tens and ones digit on the display based on the 
// first and second digit of the count being displayed 
  if(previousCount < 10) {
      leftDisplayNum = 0;
      rightDisplayNum = previousCount;    
  } else {
      rightDisplayNum = previousCount % 10;
      leftDisplayNum = (previousCount - rightDisplayNum) / 10; 
  }


// Calls the correct functions to display the numbers 0 through 9 in the tens digit of the display
  if(leftDisplayNum == 0) {
    leftDisplay0 (); 
  }
  if(leftDisplayNum == 1) {
    leftDisplay1 ();
  }
  if(leftDisplayNum == 2) {
  leftDisplay2 ();
  }
  if(leftDisplayNum == 3) {
    leftDisplay3 ();
  }
  if(leftDisplayNum == 4) {
    leftDisplay4 ();
  }
  if(leftDisplayNum == 5) {
    leftDisplay5 ();
  }
  if(leftDisplayNum == 6) {
    leftDisplay6 ();
  }
  if(leftDisplayNum == 7) {
    leftDisplay7 ();
  }
  if(leftDisplayNum == 8) {
    leftDisplay8 ();
  }
  if(leftDisplayNum == 9) {
    leftDisplay9 ();
  }

// Calls the correct functions to display the numbers 0 through 9 in the ones digit of the display
  if(rightDisplayNum == 0) {
    rightDisplay0 ();   
  }
  if(rightDisplayNum == 1) {
    rightDisplay1 ();  
  }
  if(rightDisplayNum == 2) {
    rightDisplay2 ();  
  }
  if(rightDisplayNum == 3) {
    rightDisplay3 ();  
  }
  if(rightDisplayNum == 4) {
    rightDisplay4 ();  
  }
  if(rightDisplayNum == 5) {
    rightDisplay5 ();  
  }
  if(rightDisplayNum == 6) {
    rightDisplay6 ();  
  }
  if(rightDisplayNum == 7) {
  rightDisplay7 ();  
}
if(rightDisplayNum == 8) {
  rightDisplay8 ();  
}
if(rightDisplayNum == 9) {
  rightDisplay9 ();  
}


// Sets the previous value of the button status to the new value to be compared in 
//the next loop iteration 
buttonOld = buttonNew;

}
