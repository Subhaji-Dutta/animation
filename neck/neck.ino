

#include <Servo.h>
Servo myservo;
Servo servo;// create servo object to control a servo
// twelve servo objects can be created on most boards
int trigPin = A1;    
int echoPin = A0;   
int pos = 0;    // variable to store the servo position
int i=0;
long duration, dist;   

void setup() {
 
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  myservo.attach(9);
  
  servo.attach(6);
  myservo.write(40);// attaches the servo on pin 9 to the servo object
}

void loop() {
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
dist = duration*0.034/2;
Serial.println(dist);


    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  if(dist<100){
    myservo.write(40);
    for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    
  }
  for (pos = 60; pos >= 0; pos -= 1) {
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);}
  }
  for (pos = 90; pos >= 0; pos -= 1) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  if(dist<100){
    myservo.write(40);
    for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    
  }
  for (pos = 60; pos >= 0; pos -= 1) {
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);}
  }
  }
  
