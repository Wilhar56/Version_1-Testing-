#define buttonPin 5

void setup() {
  pinMode(buttonPin, INPUT),
  digitalWrite(buttonPin, HIGH),
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  int b = checkButton();
  
  if (b == 1) clickEvent();
  if (b == 3) holdEvent();
  if (b == 4) longHoldEvent();
}

void clickEvent() {
  Serial.print("Clicked");
}
void holdEvent() {
  Serial.print("Button Held");
}
void longHoldEvent() {
  Serial.print("Long Button Held");
}

//Button timing
int debounce = 20; //ms debounce period to prevent mistake
int holdTime = 1000; //ms hold period
int longHoldTime = 3000; // ms for long hold period

//Button variables
boolean buttonVal = HIGH;
boolean buttonLast = HIGH;
//boolean DCwaiting = false;
boolean DConUp = false;
boolean singleOK = true; //weather its ok to do a single click
long downTime = -1; //time the button was pressed down 
long upTime = -1; //time the button was released
boolean ignoreUp = false;
boolean waitForUp = false;
boolean holdEventPast = false;
boolean longHoldEventPast = false;

int checkButton() {
  int event = 0;
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == LOW && buttonLast == HIGH && (millis() - upTime ) > debounce)
  {
    downTime = millis();
    ignoreUp = false;
    waitForUp = false;
    singleOK = true;
    holdEventPast = false;
    longHoldEventPast = false;
    if ((millis()-upTime)< DCgap && DConUp == false && DCwaiting == true) DConUp = true;
    else DConUp = false;
    DCwaiting = false;
  }

  else if (buttonVal == HIGH && buttonLast == LOW && (millis()- downTime)> debounce)
  {
    if (not ignoreUp)
    {
      upTime = millis();
      if (DConUp == false) DCwaiting = true;
      else
      {
        event = 2;
        DConUp = false;
        DCwaiting = false;
        singleOK = false;
      }
    }
  }
  if (buttonVal == HIGH && (millis()-upTime) >= DCgap && DCwaiting == true && DConUp == false && singleOK == true && event != 2)
  {
    event = 1;
    DCwaiting = false;
  }
  if (buttonVal == LOW && (millis() - downTime) >= holdTime){
    if (not holdEventPast)
    {
      event = 3;
      waitForUp = true;
      ignoreUp = true;
      DConUp = false;
      DCwaiting = false;
      holdEventPast = true;
    }
    if ((millis() - downTime) >= longHoldTime)
    {
      if (not longHoldEventPast)
      {
        event = 4;
        longHoldEventPast = true;
      }
    }
  }
  buttonlast = buttonVal;
  return event;
}
