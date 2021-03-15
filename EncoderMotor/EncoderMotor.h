#ifndef EncoderMotor_H_
#define EncoderMotor_H_

#include "Arduino.h"

class EncoderMotor {
  public:

    EncoderMotor(int bridgeA, int bridgeB, int enablePin);
    EncoderMotor(int bridgeA, int bridgeB);

    void Direction(String rotateDirection);
    void Speed(int rotateSpeed);
    void Start(void);
    void Stop(void);

    
  private:
    int _bridgeA;
    int _bridgeB;
    int _enablePin;
    int _rotateSpeed;
    String _rotateDirection;

};

#endif
