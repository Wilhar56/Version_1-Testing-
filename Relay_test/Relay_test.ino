        /*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-pump
 */

#include <ezOutput.h>

ezOutput pump(2);    // create ezOutput object attached to pin 2

void setup() {
  Serial.begin(9600);
  pump.low(); // turn pump off
}

void loop() {
  pump.loop();   // MUST call the loop() function first
    Serial.println("Pump is started");
    pump.low();
    pump.pulse(4000); // turn on for 10000 milliseconds ~ 10 seconds
    Serial.println("end");
    // after 10 seconds, pump will be turned off by pump.loop() function
}








///*
// * Created by ArduinoGetStarted.com
// *
// * This example code is in the public domain
// *
// * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-controls-pump
// */
//
//// constants won't change
//const int RELAY_PIN = A5;  // the Arduino pin, which connects to the IN pin of relay
//
//// the setup function runs once when you press reset or power the board
//void setup() {
//  Serial.begin(9600);
//  // initialize digital pin A5 as an output.
//  pinMode(RELAY_PIN, OUTPUT);
//}
//
//// the loop function runs over and over again forever
//void loop() {
//  digitalWrite(RELAY_PIN, HIGH); // turn on pump 5 seconds
//  Serial.println("ON");
//  delay(5000);
//  digitalWrite(RELAY_PIN, LOW);  // turn off pump 5 seconds
//  Serial.println("ON");
//
//  delay(5000);
//}
