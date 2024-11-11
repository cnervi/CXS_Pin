#include <CXS_Pin.h>

namespace CXS {
Pin::Pin(byte pin, bool reversed) {
  this->pin = pin;
  setReversed(reversed);
}

Pin::Pin(byte pin, byte mode, byte type, bool reversed) : Pin(pin, reversed) {
  setMode(mode);
  setType(type);
}

void Pin::begin(byte mode, byte type, bool reversed) {
  setMode(mode);
  setType(type);
  setReversed(reversed);
}

void Pin::analog(byte mode, bool reversed) {
  begin(mode, ANALOG, reversed);
}


void Pin::digital(byte mode, bool reversed) {
  begin(mode, DIGITAL, reversed);
}

byte Pin::getMode(void) {
  return mode;
}

void Pin::setMode(byte mode) {
  this->mode = mode;
  ::pinMode(pin, mode);
}

byte Pin::getType(void) {
  return type;
}

void Pin::setType(byte type) {
  this->type = type;

  _read  = (type == ANALOG) ? ::analogRead  : ::digitalRead;
  _write = (type == ANALOG) ? ::analogWrite : ::digitalWrite;
}

bool Pin::getReversed(void) {
  return reversed;
}

void Pin::setReversed(bool reversed) {
  this->reversed = reversed;
  maxValue();
}

int Pin::read(void) {
  int value = (ANALOG) ? ::analogRead(pin) : ::digitalRead(pin);
  return (reversed) ? ::map(value, 0, maxValue(), maxValue(), 0) : value;
}

void Pin::write(int value) {
  value = (reversed) ? ::map(value, 0, maxValue(), maxValue(), 0) : value;
  (ANALOG) ? ::analogWrite(pin, value) : ::digitalWrite(pin, value);
}

int Pin::getValue(void) {
  return read();
}

void Pin::setValue(int value) {
  write(value);
}

int Pin::getPercent(void) {
  return ::map(getValue(), 0, maxValue(), 0, 100);
}

void Pin::setPercent(int percent) {
  setValue(::map(percent, 0, 100, 0, maxValue()));
}

void Pin::on(void) {
  setPercent(100);
}

void Pin::off(void) {
  setPercent(0);
}

bool Pin::isOn(void) {
  return (getValue() != 0);
}

bool Pin::isOff(void) {
  return (getValue() == 0);
}

int Pin::maxValue(void) {
  return (type == ANALOG) ? (mode == OUTPUT) ? 1023 : 255 : 1;
}
}
