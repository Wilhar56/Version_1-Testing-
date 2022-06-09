#include <Servo.h>
Servo myservo;

int VRx = A1;
int VRy = A0;
int SW = 8;

int vSpeed = 1; 

const int motorB1      = 7; 
const int motorB2      = 6; 
const int motorA1      = 5; 
const int motorA2      = 4; 

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int pos = 0;

void setup() {

  myservo.attach(13);
  
  Serial.begin(9600); 
  
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

void loop() {  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);


  if (mapX <= -400) {
    Serial.print(" Forward ");
    digitalWrite (motorB1,HIGH);
    digitalWrite (motorB2,LOW);
    digitalWrite (motorA1,HIGH);
    digitalWrite (motorA2,LOW);
  } 


  if ((mapX >= -10) && (mapX<= 10)) {
    Serial.print(" off ");
    digitalWrite (motorB1,LOW);
    digitalWrite (motorB2,LOW);
    digitalWrite (motorA1,LOW);
    digitalWrite (motorA2,LOW);
  }
  
  if (mapX >= 400) {
    Serial.print(" Reverse ");
    digitalWrite (motorB1,LOW);
    digitalWrite (motorB2,HIGH);
    digitalWrite (motorA1,LOW);
    digitalWrite (motorA2,HIGH);
  } 

  if (mapY >= 400) {
    Serial.print(" Sideways Right ");
    digitalWrite (motorB1,HIGH);
    digitalWrite (motorB2,HIGH);
    digitalWrite (motorA1,LOW);
    digitalWrite (motorA2,LOW);
  } 

  if (mapY <= -400) {
    Serial.print(" Sideways Left ");
    digitalWrite (motorB1,LOW);
    digitalWrite (motorB2,LOW);
    digitalWrite (motorA1,HIGH);
    digitalWrite (motorA2,HIGH);
  } 

  if (SW_state == 0) {
    Serial.print(" Water On ");
    myservo.attach(13);
    for (pos = 0; pos <= 160; pos += 1) { 
    myservo.write(pos);   
  }
  }
  if (SW_state == 1) {
    Serial.print(" Water Off ");
    myservo.detach();
}
}
