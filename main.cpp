#include <Arduino.h>
#define LedGreenPin 11 // Uno Pin 11
#define LedYellowPin 12 // Uno Pin 12
#define LedRedPin 13 // Uno Pin 13

#define RedPhaseTime 5000
#define RedYellowPhaseTime 5000
#define GreenPhaseTime 5000
#define GreenBlinkCount 4
#define GreenBlinkTime 500
#define YellowPhaseTime 2000

enum TrafficLightStates {
  RedPhase, // 0
  RedYellowPhase, // 1
  GreenPhase, // 2
  GreenBlinkPhase, // 3
  YellowAfterGreenPhase, //4
  UnderfinedState // 5
};

void setup() {
  Serial.begin(115200);
  Serial.print("Starting setup...");
  pinMode(LedRedPin, OUTPUT);
  pinMode(LedYellowPin, OUTPUT);
  pinMode(LedGreenPin, OUTPUT);

  digitalWrite(LedRedPin, HIGH);
  digitalWrite(LedYellowPin, LOW);
  digitalWrite(LedGreenPin, OUTPUT);
}

uint8_t TrafficLightStates = GreenPhase;

void loop() {
  switch (TrafficLightStates)
  {
  case RedPhase:
    Serial.println("Red Phase started...");
    digitalWrite(LedRedPin, HIGH);
    digitalWrite(LedYellowPin, LOW);
    digitalWrite(LedGreenPin, LOW);
    delay(RedPhaseTime);
    TrafficLightStates = RedYellowPhase;
    break;
  
  case RedYellowPhase:
    Serial.println("Red-Yellow Phase started...");
    digitalWrite(LedRedPin, HIGH);
    digitalWrite(LedYellowPin, HIGH);
    digitalWrite(LedGreenPin, LOW);
    delay(RedYellowPhaseTime);
    TrafficLightStates = GreenPhase;
    break;

  case GreenPhase:
    Serial.println("Green Phase started...");
    digitalWrite(LedGreenPin, HIGH);
    digitalWrite(LedYellowPin, LOW);
    digitalWrite(LedRedPin, LOW);
    delay(GreenPhaseTime);
    TrafficLightStates = GreenBlinkPhase;
    break;
  

  case GreenBlinkPhase:
  Serial.println("Green-Blink Phase started...");
    for (uint8_t x = 0; x <= 4; x++)
    {
      digitalWrite(LedGreenPin, HIGH);
      digitalWrite(LedGreenPin, LOW);
      delay(GreenBlinkPhase);
      TrafficLightStates = YellowAfterGreenPhase;
      break;
    }
  
  case YellowAfterGreenPhase:
    Serial.println("Yellow-After-Green Phase started");
    digitalWrite(LedYellowPin, HIGH);
    digitalWrite(LedRedPin, LOW);
    digitalWrite(LedGreenPin, LOW);
    delay(YellowPhaseTime);
    TrafficLightStates = RedPhase;
    break;
  }
    
 }
