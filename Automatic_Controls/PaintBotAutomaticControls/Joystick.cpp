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

/**
* Moves motors as long as joystick is active
*/
bool Joystick::joystick() {
    updateJoystick();
    while (joystickIsActive()) {        
      if (_xPos < 300) {  
        moveTo(Right, _power);
      } else if (_xPos > 700) {
        moveTo(Left, _power);
      } else if (readY < 300) {
        moveTo(Up, _power);
      } else if (readY > 700) {
        moveTo(Down, _power);
      }
      updateJoystick();
    }
    stopMotors();
}
