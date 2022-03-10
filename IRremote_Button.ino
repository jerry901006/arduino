#define DECODE_NEC
#include <arduino.h>
#include "PinDefinitionAndmore.h"
#include <IRremote.hpp>
#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>
const byte ledPin = 2;       // Builtin-LED pin
const byte interruptPin = 0; // BOOT/IO0 button pin
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  pinMode(LED_BUILTIN,OUTPUT)
  Serial.begin(115200);
  Serial.println(F('START "_FILE_ " from " _DATE_"\r\nUsing library version " VERSION_IRREMOTE
  IrSender.begin();
  Serial.print("Ready to send IR signals at pin"));
  Serial.println(IR_SEND_PIN);
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}
