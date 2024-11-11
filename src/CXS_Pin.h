#ifndef CXS_PIN_H
#define CXS_PIN_H

#define DEBUG

#include "Arduino.h"

#define NONE   -0x1
#define ANALOG  0x0
#define DIGITAL 0x1

typedef unsigned int  uint;
typedef unsigned long ulong;

#ifdef DEBUG
typedef unsigned char byte;
#endif


namespace CXS {
class Pin {
public:

  Pin (byte pin, 
       bool reversed = false);

  Pin (byte pin, 
       byte mode, 
       byte type, 
       bool reversed = false);

  void begin   (byte mode,
                byte type, 
                bool reversed = false);
  void analog  (byte mode, 
                bool reversed = false);
  void digital (byte mode, 
                bool reversed = false);


  byte getMode     (void);          // get/set Mode
  void setMode     (byte mode);     // OUTPUT/INPUT/INPUT_PULLUP

  byte getType     (void);          // get/set Type:
  void setType     (byte type);     // PWM/ANALOG/DIGITAL

  bool getReversed (void);          // get/set Reversed:
  void setReversed (bool reversed);	// true/false

  int  getValue    (void);          // get/set Value:
  void setValue    (int value);     // PWM:0-255, ANALOG:0-1023, DIGITAL:0-1

  int  getPercent  (void);          // get/set Value as a percentage:
  void setPercent  (int percent);   // PWM/ANALOG: 0-100 DIGITAL: 0 or 100

  void on          (void);          // set Value to: PWM/ANALOG: 255, DIGITAL: 1
  void off         (void);          // set Value to: 0
  void toggle      (void);          // set toggle Value on and off

  bool isOn        (void);          // True if Value != 0
  bool isOff       (void);          // True if Value == 0
  
  int  read        (void);          // same as getValue()
  void write       (int value);     // same as setValue()

private:
  int  maxValue (void);

  byte pin      = NONE;
  byte mode     = NONE;
  byte type     = NONE;
  bool reversed = false;
};
}

#endif//CXS_PIN_H
