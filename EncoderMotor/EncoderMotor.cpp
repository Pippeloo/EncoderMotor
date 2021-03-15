#include "EncoderMotor.h"
#include <Arduino.h>

EncoderMotor *classEncoder;

int phase = 0;
int interrupt = 255;
bool isRunning = false;

EncoderMotor::EncoderMotor(int bridgeA, int bridgeB, int enablePin){
  classEncoder = this;
  _rotateSpeed = 255;
  
  _bridgeA = bridgeA;
  _bridgeB = bridgeB;
  _enablePin = enablePin;
  
  pinMode(_enablePin,    OUTPUT);
  pinMode(bridgeA,  OUTPUT);
  pinMode(bridgeB, OUTPUT);

  digitalWrite(_enablePin, HIGH);
  
}

EncoderMotor::EncoderMotor(int bridgeA, int bridgeB){
  classEncoder = this;
  _rotateSpeed = 255;
  
  _bridgeA = bridgeA;
  _bridgeB = bridgeB;
  
  pinMode(classEncoder->_bridgeA,  OUTPUT);
  pinMode(classEncoder->_bridgeB, OUTPUT);

}

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
    digitalWrite(classEncoder->_bridgeA, phase);
    analogWrite(classEncoder->_bridgeB, interrupt); 
  }
}

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
    digitalWrite(classEncoder->_bridgeA, phase);
    analogWrite(classEncoder->_bridgeB, interrupt); 
  }
}

static void EncoderMotor::Start(void){
  digitalWrite(classEncoder->_bridgeA, phase);
  analogWrite(classEncoder->_bridgeB, interrupt);
  isRunning = true;

}

static void EncoderMotor::Stop(void){
  digitalWrite(classEncoder->_bridgeA, LOW);
  digitalWrite(classEncoder->_bridgeB, LOW);
  isRunning = false;
}
