#include "Joystick.h"

/**
* The Joystick class represents the HiLetgo Game Joystick Sensor Game Controller used to displace the
* PaintBot's centerpiece.
*
* @author David Gaitsgory
* @version 1.0
*/

/**
* Default constructor for the Joystick class
*/

Joystick::Joystick(int xPin, int yPin) :
  _xPin(xPin),
  _yPin(yPin),
  _neutral(500),
  _xPos(500),
  _yPos(500),
  _deadZone(30),
  _power(200) {}

/**
* Overloaded Joystick constructor to specify sensitivity or if using different joystick model
* @param xPin : The pin # the joystick's x position can be read from 
* @param yPin : The pin # the joystick's y position can be read from
* @param neutral : The value of the pins when the joystick is resting
* @param xPos : Joystick's current x position, set by default to neutral
* @param yPos : Joystick's current y position, set by default to neutral
* @param deadZone : To reduce sensitivity, a boundary is put around the neutral position before the joystick is considered "active"
* @param power: The power sent to direct writes to motors
*/
Joystick::Joystick(int xPin, int yPin, int neutral, int deadZone, int power) :
  _xPin(xPin),
  _yPin(yPin),
  _neutral(neutral),
  _xPos(neutral),
  _yPos(neutral),
  _deadZone(30),
  _power(200) {}
}

/**
* Getter for x position
*/
int getXPos() {
  return (_xPos);
}

/**
* Getter for y position
*/
int getYPos() {
  return (_yPos);
}

/**
* Getter for power
*/
int getPower() {
  return (_power);
}


/**
* Sets pins to read x,y values from
*/
void Joystick::setPins(int xPin, int yPin) {
  _xPin = xPin;
  _yPin = yPin;
}

void Joystick::setSensitivity(int neutral, int deadZone, int power) {
  _neutral = neutral;
  _deadZone = deadZone;
  _power = power;
}

/**
* Reads x,y values from joystick pins
*/
void Joystick::updateJoystick() {
   _xPos = analogRead(_xPin);
   _yPos = analogRead(_yPin);
}

/**
* The joystick is considered active if the x or y positions are outside of the deadzone
*/
bool Joystick::joystickIsActive() {
  return (
    _xPos <= _neutral - _deadZone ||
    _xPos >= _neutral + _deadZone ||
    _yPos <= _neutral - _deadZone ||
    _yPos >= _neutral + _deadZone
   );
}
