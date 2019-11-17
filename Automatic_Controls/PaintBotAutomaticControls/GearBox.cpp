#include "GearBox.h"

/**
* Default constructor for the GearBox class
*/
GearBox::GearBox(void)
{
	_motor = NULL;
	_encoder = NULL;
}

/**
* Overloaded constructor for the GearBox class
* @param rpwm : The pin to be associated with the H bridge rpwm input
* @param lpwm : The pin to be associated with the H bridge lpwm input
* @param pinA : The pin on the arduino associated with the Encoders pin A output
* @param pinB : The pin on the arduino associated with the Encoders pin B output
*/
GearBox::GearBox(int rpwmPin, int lpwmPin, int pinA, int pinB)
{
	_motor = new Motor(rpwmPin, lpwmPin);
	_encoder = new Encoder(pinA, pinB);
}

/**
* Deconstructor for the GearBox class
* If memory for the _motor or _encoder member variables has been allocated,
* the memory will be freed
*/
GearBox::~GearBox(void)
{
	if (_motor)
	{
		free(_motor);
		_motor = NULL;
	}
	if (_encoder)
	{
		free(_encoder);
		_encoder = NULL;
	}
}

/**
* Allows the user to manually initialize or change the pin associated with the H bridge
* rpwm and lpwm input
* @param rpwm : The pin to be associated with the H bridge rpwm input
* @param lpwm : The pin to be associated with the H bridge lpwm input
*/
void GearBox::setupMotor(int rpwmPin, int lpwmPin)
{
	if (_motor != NULL)
	{
		_motor->setRpwm(rpwmPin);
		_motor->setLpwm(lpwmPin);
	}
	else
	{
		_motor = new Motor(rpwmPin, lpwmPin);
	}
}

/**
* Initializes or changes the arduino pins associated with the Encoders output pins
* with the left GearBoxs' right Encoder
* @param pinA : The pin on the arduino associated with the Encoders pin A output
* @param pinB : The pin on the arduino associated with the Encoders pin B output
*/
void GearBox::setupEncoder(int pinA, int pinB)
{
  if (_encoder != NULL)
    free(_encoder);
  _encoder = new Encoder(pinA, pinB);
}

/**
* Allows the user to manually set the encoders position
* @param position : The desired position for the encoder
*/
void GearBox::setEncoderPosition(long position)
{
	_encoder->write(position);
}

/**
* Returns the number of rotations of the encoder
* The value 2400.0 comes from the specific encoder being used. The encoder
* has 600 contact points and 4 possible position combinations of pinA and pinB.
* The possible combinations are as follows:
* pinA - on, pinB - on
* pinA - on, pinB - off
* pinA - off, pinB - off
* pinA - off, pinB - on
* 600 contact points * 4 possible positions = 2400 total positions per rotation
* @return : How many rotations have been completed by the encoder
*/
float GearBox::encoderRotations(void) const
{
	return (_encoder->read() / 2400.0);
}

/**
* Returns the encoders numerical position
* @return : The number of times the encoder has experienced a different position
*/
long GearBox::encoderPosition(void) const
{
	return (_encoder->read());
}

/**
* Rotates the motor clockwise
* @param power : An integer whos value can be between 0 and 255 0 being
* 0% power and 255 being 100% power
*/
void GearBox::rotateMotorClockwise(int power)
{
	_motor->rotateClockwise(power);
}

/**
* Rotates the motor clockwise
* @param power : A float whos value can be between 0.0 and 1.0. 0.0 being
* 0% power and 1.0 being 100% power
*/
void GearBox::rotateMotorClockwise(float power)
{
	_motor->rotateClockwise(power);
}

/**
* Rotates the motor counter-clockwise
* @param power : An integer whos value can be between 0 and 255 0 being
* 0% power and 255 being 100% power
*/
void GearBox::rotateMotorCounterClockwise(int power)
{
	_motor->rotateCounterClockwise(power);
}

/**
* Rotates the motor counter-clockwise
* @param power : A float whos value can be between 0.0 and 1.0. 0.0 being
* 0% power and 1.0 being 100% power
*/
void GearBox::rotateMotorCounterClockwise(float power)
{
	_motor->rotateCounterClockwise(power);
}

/**
* Stops all motion of the motor
*/
void GearBox::stopMotor(void)
{
	_motor->stop();
}

/**
* Swaps the rotation of motor so that clockwise becomes counter-clockwise and
* vice versa
*/
void GearBox::swapMotorRotation(void)
{
	_motor->swapRotation();
}
