#include <Event.h>
#include <Timer.h>


Timer t;
int leftLED1 = 9;
int leftLED2 = 11;
int leftLED3 = 10;
int leftLED4 = 12;
int leftLED5 = 7;
int leftLED6 = 6;
int leftLED7 = 8;
int charliePin1 = 5;
int charliePin2 = 4;
int charliePin3 = 3;
int charliePin4 = 2;

int buttonPin = 13;

int buttonNew;
int buttonOld = 1;

int delayTime = 10;
int d = 1;
int count = 0;
int previousCount = 0;
int timeBase = 3000;


int leftDisplayNum = 0;
int rightDisplayNum = 0;


// charlieplexing for each LED on the right side to turn on 
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

// make left display numbers 0 thorough 9
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

//make right side display numbers 0 through 9 
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

void counterReset() {
  timeCount = millis ();
  previousCount = count;
  count = 0; 
  Serial.println(previousCount);
}

void setup() {
  Serial.begin(9600);

  pinMode(leftLED1, OUTPUT);
  pinMode(leftLED2, OUTPUT);
  pinMode(leftLED3, OUTPUT);
  pinMode(leftLED4, OUTPUT);
  pinMode(leftLED5, OUTPUT);
  pinMode(leftLED6, OUTPUT);
  pinMode(leftLED7, OUTPUT);
  pinMode(buttonPin, INPUT);

  t.every(timeBase, counterReset, NULL);
}


void loop() {

  t.update();

  buttonNew = digitalRead(buttonPin);


  if(buttonOld == 0 && buttonNew == 1){
    count++;
    delay(delayTime);
  }

  if(previousCount < 10) {
      leftDisplayNum = 0;
      rightDisplayNum = previousCount;    
  } else {
      rightDisplayNum = previousCount % 10;
      leftDisplayNum = (previousCount - rightDisplayNum) / 10; 
  }



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


 
buttonOld = buttonNew;

}
