int VRx = A1;
int VRy = A0;
int SW = 8;

int vSpeed = 1; 

const int motorB1      = 7; 

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(motorB1, OUTPUT);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

void loop() {
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
  
//  if (SW_state == 0) {
//    Serial.print(" Water On ");
// // digitalWrite (motorA1,HIGH);
//  digitalWrite (motorB1,HIGH);
//  }
//  else if (SW_state == 1) {
//    Serial.print(" Water Off ");
//  //digitalWrite (motorA1,LOW);
//  digitalWrite (motorB1,LOW);
//  } 



  if ( mapX >-400 , mapY >-350) {
    Serial.print(" Foward ");
  digitalWrite (motorB1,LOW);
  }
  else if (mapX >400 , mapY <150) {
    Serial.print(" Reverse ");
  digitalWrite (motorB1,HIGH);
  } 





  
  else{
    Serial.print(".");
  }
}
