//====== LIBRARIES =====
#include "EncoderMotor.h"
#include <Arduino.h>

//===== VARIABLES ======
int phase = 0;
int interrupt = 255;
bool isRunning = false;

//===== CLASS WITH ENABLE =====
EncoderMotor::EncoderMotor(int bridgeA, int bridgeB, int enablePin){
  _rotateSpeed = 255;
  
  _bridgeA = bridgeA;
  _bridgeB = bridgeB;
  _enablePin = enablePin;
  
  pinMode(_enablePin,    OUTPUT);
  pinMode(bridgeA,  OUTPUT);
  pinMode(bridgeB, OUTPUT);

  digitalWrite(_enablePin, HIGH);
  
}

//===== CLASS WITHOUT ENABLE =====
EncoderMotor::EncoderMotor(int bridgeA, int bridgeB){
  _rotateSpeed = 255;
  
  _bridgeA = bridgeA;
  _bridgeB = bridgeB;
  
  pinMode(_bridgeA,  OUTPUT);
  pinMode(_bridgeB, OUTPUT);

}

//===== DIRECTION =====
static void EncoderMotor::Direction(String rotateDirection){
  _rotateDirection = rotateDirection;
  if(_rotateDirection == "CCW"){
    phase = 0;
    interrupt = _rotateSpeed;
  } else if (_rotateDirection == "CW"){

    phase = 1;
    interrupt = 255 - _rotateSpeed;

  }
  if(isRunning){
    digitalWrite(_bridgeA, phase);
    analogWrite(_bridgeB, interrupt); 
  }
}

//===== SPEED ======
static void EncoderMotor::Speed(int rotateSpeed){
  _rotateSpeed = rotateSpeed;
  if(_rotateDirection == "CCW"){
    phase = 0;
    interrupt = _rotateSpeed;
  }else if(_rotateDirection == "CW"){
    phase = 1;
    interrupt = 255 - _rotateSpeed;
  }
  if(isRunning){
    digitalWrite(_bridgeA, phase);
    analogWrite(_bridgeB, interrupt); 
  }
}

//===== START =====
static void EncoderMotor::Start(void){
  digitalWrite(_bridgeA, phase);
  analogWrite(_bridgeB, interrupt);
  isRunning = true;

}

//===== STOP =====
static void EncoderMotor::Stop(void){
  digitalWrite(_bridgeA, LOW);
  digitalWrite(_bridgeB, LOW);
  isRunning = false;
}
