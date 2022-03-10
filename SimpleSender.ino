#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>
void setup(){
  pinMode(LED_BUILTIN,OUTPUT)
  Serial.begin(115200);
  Serial.println(F('START "_FILE_ " from " _DATE_"\r\nUsing library version " VERSION_IRREMOTE
  IrSender.begin();
  Serial.print("Ready to send IR signals at pin"));
  Serial.println(IR_SEND_PIN);
}
