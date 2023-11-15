#include <Arduino.h>
#define ButtonPin 12
#define RedLedPin 13
#define LdrPin 19


bool OldButtonState = false;
int ldrValue = 0;
bool ButtonPressed = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting setup...");
  pinMode(ButtonPin, INPUT);
  pinMode(RedLedPin, OUTPUT);
  pinMode(LdrPin, INPUT);


  digitalRead(ButtonPin);
  digitalWrite(RedLedPin, LOW);
  

}

void loop() {
  bool ActualButtonState = digitalRead(ButtonPin);
  ldrValue = analogRead(LdrPin);

  if(ActualButtonState != OldButtonState) 
  {
    OldButtonState = ActualButtonState; 


    //raising edge
    if(ActualButtonState)
    {
      digitalWrite(RedLedPin, !digitalRead(RedLedPin));
    }
  }
  if(ldrValue < 350 && ButtonPressed)
  {
    digitalWrite(RedLedPin, HIGH);
    ButtonPressed = 0;
  }
  if(ldrValue > 350 && !ButtonPressed)
  {
    digitalWrite(RedLedPin, LOW);
    ButtonPressed = 1;
  }


}