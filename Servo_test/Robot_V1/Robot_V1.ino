#include <Servo.h>
 
Servo servo_test;                                //initialize a servo object for the connected servo  
                
int angle = 0;    
 
void setup() 
{ 
  Serial.begin(9600);
  Serial.print("Start");
  servo_test.attach(9);                         // What pin the servo is attached to digital pwm
} 
  
void loop() 
{ 
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
