int VRx = A1;
int VRy = A0;
int SW = 8;


const int motorA1      = 7;  
const int motorA2      = 6; 
const int motorAspeed  = 9;
const int motorB1      = 5; 
const int motorB2      = 4; 
const int motorBspeed  = 11;


int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  Serial.begin(9600); 
  
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
  if (SW_state == 0) {
    Serial.print(" Water On ");
    digitalWrite (motorA1,HIGH);
    digitalWrite(motorA2,HIGH);                       
    digitalWrite (motorB1,HIGH);
    digitalWrite(motorB2,HIGH);
  }
  else if (SW_state == 1) {
    Serial.print(" Water Off ");
  } 
  else{
    Serial.print(".");
  }
}
