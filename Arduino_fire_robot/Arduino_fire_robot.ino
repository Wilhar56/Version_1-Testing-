#include <Servo.h>
Servo myservo;

//#define F_Sensor 2 //Flame sensor

int VRx = A1;
int VRy = A0;
int SW = 8;

int vSpeed = 1; 

const int motorB1      = 12; 
const int motorB2      = 11; 
const int motorA1      = 10; 
const int motorA2      = 9; 

const int buzzer = 4;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int pos = 0;

void setup() {
  
  pinMode(7, OUTPUT); // Set pin 7 to output
  
  Serial.begin(9600); 

//  pinMode(F_Sensor, INPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 

  pinMode(buzzer, OUTPUT);
}

void loop() {  

//  int fire = digitalRead(F_Sensor);
  
  xPosition = analogRead(VRx);
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


  if ((mapX <= -400) && (mapX >= -550)) {
    Serial.print(" Reverse ");
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
  
  if ((mapX >= 400) && (mapX <= 550)) {
    Serial.print(" Foward ");
    digitalWrite (motorB1,LOW);
    digitalWrite (motorB2,HIGH);
    digitalWrite (motorA1,LOW);
    digitalWrite (motorA2,HIGH);
  } 

  if ((mapY >= 400) && (mapY <= 550)) {
    Serial.print(" Sideways Right ");
    digitalWrite (motorB1,HIGH);
    digitalWrite (motorB2,LOW);
    digitalWrite (motorA1,LOW);
    digitalWrite (motorA2,HIGH);
  } 

  if ((mapY <= -400) && (mapY >= -550)) {
    Serial.print(" Sideways Left ");
    digitalWrite (motorB1,LOW);
    digitalWrite (motorB2,HIGH);
    digitalWrite (motorA1,HIGH);
    digitalWrite (motorA2,LOW);
  } 

  if (SW_state == 0) {
    digitalWrite(7, HIGH); // Set pin 7 as "high" or turn it on
    Serial.println("Should be on"); // prints that the pump should be on
    tone(buzzer, 6535);

  }

  if (SW_state == 1) {
    digitalWrite(7, LOW); // Set pin 7 as "low" or turn it off
    Serial.println("Should be off"); // prints that the pump
    Serial.print(" Water Off ");
    noTone(buzzer);
  }
}


//  if( fire == HIGH)
//  {
//    Serial.println("Fire Detected");
//  }
//  
//  if( fire == LOW)
//  {
//    Serial.println("Peace");
//  }
//}
