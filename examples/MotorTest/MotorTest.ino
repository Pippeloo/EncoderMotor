//===== LIBRARIES =====
#include "EncoderMotor.h"

//===== H-BRIDGE PINS =====
#define M1_ENABLE 7
#define M1_A1    4
#define M1_A2    5

//===== MOTOR OUTPUT PINS =====
EncoderMotor motor(4, 5, 7);

//===== SETUP =====
void setup() {
  //Set the motor direction ("CW" or "CCW")
  motor.Direction("CW");
  
  //Start the motor
  motor.Start();
}

//===== LOOP =====
void loop() {
  
  delay(1000);
  
  //Stop the motor
  motor.Stop();
  
  delay(200);
  
  //Set the motor direction and start the motor
  motor.Direction("CCW");
  motor.Speed(255);
  motor.Start();

  delay(1000);
  
  //Lower the speed
  motor.Speed(200);
  
  delay(1000);

  //Stop the motor
  motor.Stop();
  delay(200);

  //Start the motor with low speed in a CW direction
  motor.Direction("CW");
  motor.Speed(100);
  motor.Start();
  
}
