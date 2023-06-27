//include library by using Sketch->Include Library->Add .Zip library-> find "SR04.zip"
//also find HC-SR04.zip because hc sr04 has 4 pins some have 3 pins
#include "SR04.h"

// assign pins for ultrasonic sensor HC-SR04
// trigger pin to #12; echo pin to #11
#define TRIG_PIN 12
#define ECHO_PIN 11

// we create an instance of the "SR04" object type (this is from the library file we include)
// the argument for creating the instance is the trigger pin and echo pin we specified.
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

// variable a is to store measured distance from ultrasonic sensor
long a;

// connect led pin to #7
int ledpin = 7;
// connect active buzzer pin to #3
int buzzerpin = 3;

//set a distance threshold value
long WarningDistance = 10; // threshold value is 10cm. if an object distance<WarningDistance, we let LED and buzzer on

void setup() {

  //initialize serial monitor
  Serial.begin(9600);
  //set ledpin and buzzerpin as OUTPUT (we send commands to them)
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);

  delay(1000);
}

void loop() {
  //
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");

  // LED and buzzer go on when measured distance < our threshold value WarningDistance
  if (a <= WarningDistance) {
    digitalWrite(ledpin, HIGH);
    digitalWrite(buzzerpin, HIGH);
  }
  // if distance>threshold, we turn off LED and Buzzer
  else {
    digitalWrite(ledpin, LOW);
    digitalWrite(buzzerpin, LOW);
  }
  delay(300);
}