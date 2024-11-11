/*
  Arduino CXS Pin Library Example - Blink, Turns on/off an LED in one second invervals.
*/

#include <CXS_Pin.h>  // https://github.com/cnervi/CXS_Pin

CXS::Pin ledBuiltin(LED_BUILTIN);

void setup() {
  // initialize ledBuiltin as digital output.
  ledBuiltin.Digital(OUTPUT);
}

void loop() {
  // toggle the LED on/off.
  ledBuiltin.toggle();
  // wait for a second.
  delay(1000);
}
