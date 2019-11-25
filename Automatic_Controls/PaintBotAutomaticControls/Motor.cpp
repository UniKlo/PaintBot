#include "Motor.h"

/**
* The Motor class represents the Unite Motor Co. Model: MY6812B motor used
* to create the PaintBot. The Motor class' purpose is to abstract away any
* arduino code required for powering/spinning a motor.
*
* @author Casey Singleton
* @version 1.0
*/

/**
* Default constructor for the Motor class
* The private members _rpwmPin and _lpwmPin are set to values that do not
* exist on an arduino board. This allows for error checking if the user
* does not specify which specific pins should be associated with the H bridge
* rpwm and lpwm inputs.
*/
Motor::Motor(void) :
	_rpwmPin(-1),
	_lpwmPin(-1) {}

/**
* Overloaded constructor for the Motor class
* @param rpwm : The pin to be associated with the H bridge rpwm input
* @param lpwm : The pin to be associated with the H bridge lpwm input
*/
Motor::Motor(int rpwm, int lpwm) :
	_rpwmPin(rpwm),
	_lpwmPin(lpwm) {}

/**
* Deconstructor for the Motor class
*/
Motor::~Motor(void) {}

/**
* Allows the user to manually set or change the pin associated with the H bridge
* rpwm input
* @param rpwm : The pin to be associated with the H bridge rpwm input
*/
void Motor::setRpwm(int rpwm) { _rpwmPin = rpwm; }

/**
* Allows the user to manually set or change the pin associated with the H bridge
* lpwm input
* @param lpwm : The pin to be associated with the H bridge lpwm input
*/
void Motor::setLpwm(int lpwm) { _lpwmPin = lpwm; }

/**
* Rotates the motor clockwise
* @param power : A float whos value can be between 0.0 and 1.0. 0.0 being
* 0% power and 1.0 being 100% power
*/
void Motor::rotateClockwise(float power)
{
	int translatedPower;

	translatedPower = 160 * fmin(fmax(power, 0.0), 1.0);
	if (_rpwmPin > -1 && _lpwmPin > -1)
	{
		analogWrite(_rpwmPin, translatedPower);
		analogWrite(_lpwmPin, 0);
	}
}

/**
* Rotates the motor clockwise
* @param power : An integer whos value can be between 0 and 255 0 being
* 0% power and 255 being 100% power
*/
void Motor::rotateClockwise(int power)
{
	int translatedPower;

	translatedPower = min(max(power, 0), 160);
	if (_rpwmPin > -1 && _lpwmPin > -1)
	{
		analogWrite(_rpwmPin, 0);
		analogWrite(_lpwmPin, translatedPower);
	}
}

/**
* Rotates the motor counter-clockwise
* @param power : A float whos value can be between 0.0 and 1.0. 0.0 being
* 0% power and 1.0 being 100% power
*/
void Motor::rotateCounterClockwise(float power)
{
	int translatedPower;

	translatedPower = 160 * fmin(fmax(power, 0.0), 1.0);
	if (_rpwmPin > -1 && _lpwmPin > -1)
	{
		analogWrite(_rpwmPin, 0);
		analogWrite(_lpwmPin, translatedPower);
	}
}

/**
* Rotates the motor counter-clockwise
* @param power : An integer whos value can be between 0 and 255 0 being
* 0% power and 255 being 100% power
*/
void Motor::rotateCounterClockwise(int power)
{
	int translatedPower;

	translatedPower = min(max(power, 0), 160);
	if (_rpwmPin > -1 && _lpwmPin > -1)
	{
		analogWrite(_rpwmPin, translatedPower);
		analogWrite(_lpwmPin, 0);
	}
}

/**
* Stops all motion of the motor
*/
void Motor::stop(void)
{
	analogWrite(_rpwmPin, 0);
	analogWrite(_lpwmPin, 0);
}

/**
* Swaps the rotation of motor so that clockwise becomes counter-clockwise and
* vice versa
*/
void Motor::swapRotation(void)
{
	int tmp;

	tmp = _rpwmPin;
	_rpwmPin = _lpwmPin;
	_lpwmPin = tmp;
}

/**
* Encodes counter clockwise and clockwise motion into a single value and directly writes to motor
* @param speed - signed value indicating rotational direction and power of motor (- is ccw, + is cw)
* @author David Gaitsgory - dgaitsgo@student.42.fr
*/

void Motor::write(float speed) {
  speed = constrain(speed, -255, 254);
  bool forward = speed > 0;
  speed = fabs(speed);
  if (speed == 0) {
    analogWrite(_lpwmPin, 0);
    analogWrite(_rpwmPin, 0);
  } else if (forward) {    
    analogWrite(_lpwmPin, speed);
    analogWrite(_rpwmPin, 0);
  } else {
    analogWrite(_lpwmPin, 0);
    analogWrite(_rpwmPin, speed);
  }
}
