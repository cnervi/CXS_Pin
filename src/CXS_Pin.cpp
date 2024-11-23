#include "CXS_Pin.h"

namespace CXS
{
  Pin::Pin(byte pin) {
    this->pin = pin;
  }

  Pin::Pin(byte pin, byte mode, byte type) : Pin(pin) {
    setMode(mode);
  }

  Pin Pin::begin(byte mode, byte type) {
    setMode(mode);
    setType(type);
    return *this;
  }

  Pin Pin::analog(byte mode) {
    return begin(mode, ANALOG);
  }

  Pin Pin::digital(byte mode) {
    return begin(mode, DIGITAL);
  }

  Pin Pin::output(byte type) {
    return begin(OUTPUT, type);
  }

  Pin Pin::input(byte type) {
    return begin(INPUT, type);
  }

  Pin Pin::inputPullup(byte type) {
    return begin(INPUT_PULLUP, type);
  }

  Pin Pin::reversed(void) {
    reverse = true;
    return *this;
  }

  byte Pin::getPin(void) {
    return pin;
  }

  bool Pin::isReversed(void) {
    return reverse;
  }

  byte Pin::getMode(void) {
    return mode;
  }

  void Pin::setMode(byte mode) {
    this->mode = mode;
    pinMode(mode);
  }

  byte Pin::getType(void) {
    return type;
  }

  void Pin::setType(byte type) {
    this->type = type;
  }

  int Pin::getValue(void) {
    return read();
  }

  void Pin::setValue(int value) {
    write(value);
  }

  int Pin::getPercent(void) {
    return ::map(getValue(), 0, MVAL(type, mode), 0, 100);
  }

  void Pin::setPercent(int percent) {
    setValue(::map(percent, 0, 100, 0, MVAL(type, mode)));
  }

  void Pin::on(void) {
    setPercent(100);
  }

  void Pin::off(void) {
    setPercent(0);
  }

  void Pin::toggle(void) {
    (isOn()) ? off() : on();
  }

  bool Pin::isOn(void) {
    return (getValue() != 0);
  }

  bool Pin::isOff(void) {
    return (getValue() == 0);
  }

  int Pin::read(void) {
    int value = (ANALOG) ? analogRead() : digitalRead();
    return (reverse) ? ::map(value, 0, MVAL(type, mode), MVAL(type, mode), 0) : value;
  }

  void Pin::write(int value) {
    value = (reverse) ? ::map(value, 0, MVAL(type, mode), MVAL(type, mode), 0) : value;
    (ANALOG) ? analogWrite(value) : digitalWrite(value);
  }

  void Pin::beep(uint freq) {
    (freq == NONE) ? noTone() : tone(freq, 0);
  }


  void Pin::pinMode(byte mode) {
    ::pinMode(pin, mode);
  }

  int Pin::analogRead(void) {
    return ::analogRead(pin);
  }

  void Pin::analogWrite(int value) {
    ::analogWrite(pin, value);
  }

  int Pin::digitalRead(void) {
    return ::digitalRead(pin);
  }

  void Pin::digitalWrite(int value) {
    ::digitalWrite(pin, value);
  }

  ulong Pin::pulseIn(byte  state, ulong tout) {
   return ::pulseIn(pin, state, tout);
  }

  ulong Pin::pulseInLong (byte  state, ulong tout) {
   return ::pulseInLong(pin, state, tout);
  }

  byte Pin::shiftIn(Pin  clock, byte order) {
    return ::shiftIn(pin, clock.getPin(), order);
  }

  void Pin::shiftOut(Pin  clock, byte order, byte value) {
   ::shiftOut(pin, clock.getPin(), order, value);
  }

  void Pin::noTone(void) {
    ::noTone(pin);
  }

  void Pin::tone(uint freq, ulong time) {
    ::tone(pin, freq, time); 
  }

