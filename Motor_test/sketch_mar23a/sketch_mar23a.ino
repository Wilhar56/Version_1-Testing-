//L293 Connection   
  const int motorA1      = 7;  
  const int motorA2      = 6; 
  const int motorAspeed  = 9;
  const int motorB1      = 5; 
  const int motorB2      = 4; 
  const int motorBspeed  = 11

#include <Servo.h>
Servo servo_test;                                //initialize a servo object for the connected servo  
int angle = 0;  

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  servo_test.attach(9);                         // What pin the servo is attached to digital pwm

  Serial.begin(9600);

  delay(3000);
  
}

void loop() {
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);


  for(angle = 0; angle < 180; angle += 1)    
  {                                  
    servo_test.write(angle);               
    Serial.print("1st");      
  } 
    delay(200);                                //How long it turns for
  for(angle = 180; angle>=1; angle-=1)      
  {                                
    servo_test.write(angle);              
    Serial.print("2nd");                        
  } 
    delay(200);
  }










 
