#ifndef CXS_PIN_H
#define CXS_PIN_H

#define DEBUG

#include "Arduino.h"

#define NONE   -0x1
#define ANALOG  0x0
#define DIGITAL 0x1

#define MVAL(type,mode) ((type == ANALOG) ? (mode == OUTPUT) ? 1023 : 255 : 1)

typedef unsigned int  uint;
typedef unsigned long ulong;


namespace CXS
{
  class Pin
  {
    public:
      Pin               (byte pin); 

      Pin               (byte pin, 
                         byte mode, 
                         byte type);

      Pin begin         (byte mode,
                         byte type); 
      Pin analog        (byte mode); 
      Pin digital       (byte mode); 
      Pin reversed      (void);


      byte getPin       (void);          // get Pin number
      bool isReversed   (void);          // True if reversed
    
      byte getMode      (void);          // get/set Mode
      void setMode      (byte mode);     // OUTPUT/INPUT/INPUT_PULLUP

      byte getType      (void);          // get/set Type:
      void setType      (byte type);     // PWM/ANALOG/DIGITAL


      int  getValue     (void);          // get/set Value:
      void setValue     (int value);     // PWM:0-255, ANALOG:0-1023, DIGITAL:0-1

      int  getPercent   (void);          // get/set Value as a percentage:
      void setPercent   (int percent);   // PWM/ANALOG: 0-100 DIGITAL: 0 or 100

      void on           (void);          // set Value to: PWM/ANALOG: 255, DIGITAL: 1
      void off          (void);          // set Value to: 0
      void toggle       (void);          // set toggle Value on and off

      bool isOn         (void);          // True if Value != 0
      bool isOff        (void);          // True if Value == 0
      
      int  read         (void);          // analogRed || digitalRead
      void write        (int value);     // analogWrite || digitalWrite

      int  analogRead   (void);
      void analogWrite  (int value);

      int  digitalRead  (void);
      void digitalWrite (int value);

    private:
      byte pin     = NONE;
      byte mode    = NONE;
      byte type    = NONE;
      bool reverse = false;
  };
}
#endif//CXS_PIN_H
