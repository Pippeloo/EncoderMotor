# QEncoder
With this library you can control a Encoder motor.

## Components
These are the components that I used
* Arduino
* Encoder motor
* H-Bridge

## Functions

| Datatype | Description                    |
| ------------- | ------------------------------ |
| `EncoderMotor motor1(n, p, e)`      | Initialize the motor, where 'n' is a regular pin, 'p' a pwm pin and 'e' is normal pin used to enable the H-bridge. These are all `int` types      |
| `EncoderMotor motor1(n, p)` | Initialize the motor, where 'n' is a regular pin, 'p' a pwm pin. These are both `int` types
| Functions |  |
| `Start()`   | Start the motor (default clockwise with max speed). |
| `Stop()`   | Stop the motor (Sets the pins to `LOW`|
| `Speed(value)` | Set the speed of the motor. `value` can be 0-255. The Speed wil always update when executed, even if the motor is running! `value` is an `int` type. |
| `Direction(value)` | Defines the rotation direction of the motor. `value` can be `CW` or `CCW` and is a `String` type.|


## Example
Down below you can view an example

```c++
//===== LIBRARIES =====
#include "EncoderMotor.h"

//===== H-BRIDGE PINS =====
#define M1_ENABLE 7
#define M1_A1    4
#define M1_A2    5

//===== MOTOR SETUP =====
EncoderMotor motor(M1_A1, M1_A2, M1_ENABLE);

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
```
