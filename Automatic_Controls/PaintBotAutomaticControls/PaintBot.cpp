#include "PaintBot.h"

/**
* The PaintBot class represents the painting robot as a whole. The purpose of
* the PaintBot class is to simplify the initial set up and allow users to
* easily move the center piece by entering coordinates, or by entering a
* distance to travel, and an angle at which to travel. Automation of the center
* piece movement can be easily achieved through a queue of coordinates.
*
* @author Casey Singleton
* @version 1.0
*/

/**
* Default constructor for the PaintBot class
*/
PaintBot::PaintBot(void)
{
	_height = 0.0;
	_width = 0.0;
	_centerpiecePosition = NULL;
	_chainLengthRight = 0.0;
	_chainLengthLeft = 0.0;
	_rightGearBox = NULL;
	_leftGearBox = NULL;
}

/**
* Overloaded constructor for the PaintBot class
* @param height : The height of the painting canvas
* @param width : The width of the painting canvas
*/
PaintBot::PaintBot(float width, float height)
{
	_width = width;
	_height = height;
	_centerpiecePosition = new Vec2();
	_centerpiecePosition->x = width / 2.0;
	_centerpiecePosition->y = height / 2.0;
	_chainLengthRight = distanceBetweenVectors(Vec2(width / 2.0 + 5, height / 2.0 + 5), Vec2(width, height));
	_chainLengthLeft = distanceBetweenVectors(Vec2(width / 2.0 - 5, height / 2.0 + 5), Vec2(0.0, height));
	_rightGearBox = NULL;
	_leftGearBox = NULL;
}

/**
* Deconstructor for the PainBot class
* Frees any allocated memory if memory has been allocated
*/
PaintBot::~PaintBot(void)
{
	if (_centerpiecePosition)
	{
		free(_centerpiecePosition);
		_centerpiecePosition = NULL;
	}
	if (_rightGearBox)
	{
		free(_rightGearBox);
		_rightGearBox = NULL;
	}
	if (_leftGearBox)
	{
		free(_leftGearBox);
		_leftGearBox = NULL;
	}
}

/**
* Allows users to manually set/change the height of the canvas
* @param height : The height of the painting canvas
*/
void PaintBot::setHeight(float height) { _height = height; }

/**
* Allows users to manually set/change the width of the canvas
* @param width : The width of the painting canvas
*/
void PaintBot::setWidth(float width) { _width = width; }

/**
* Allows users to manually set/change the location of the painting center piece
* @param x : The horizontal position of the center piece in inches
* @param y : The vertical position of the center piece in inches
*/
void PaintBot::setCenterpiecePosition(float x, float y)
{
  if (_centerpiecePosition != NULL)
  {
    *_centerpiecePosition = Vec2(x, y);
  }
  else
  {
    _centerpiecePosition = new Vec2(x, y);
  }
}

/**
* Initializes or changes the rpwm and lpwm H bridge logic pins associated
* with the right GearBoxs' Motor
* @param rpwm : The pin on the arduino associated with the H bridge rpwm input
* @param lpwm : The pin on the arduino associated with the H bridge lpwm input
*/
void PaintBot::setupRightGearBoxMotor(int rpwm, int lpwm)
{
	if (_rightGearBox == NULL)
	{
		_rightGearBox = new GearBox();
	}
	_rightGearBox->setupMotor(rpwm, lpwm);
}

/**
* Initializes or changes the rpwm and lpwm H bridge logic pins associated
* with the left GearBoxs' Motor
* @param rpwm : The pin on the arduino associated with the H bridge rpwm input
* @param lpwm : The pin on the arduino associated with the H bridge lpwm input
*/
void PaintBot::setupLeftGearBoxMotor(int rpwm, int lpwm)
{
	if (_leftGearBox == NULL)
	{
		_leftGearBox = new GearBox();
	}
	_leftGearBox->setupMotor(rpwm, lpwm);
}

/**
* Initializes or changes the arduino pins associated with the Encoders output pins
* with the right GearBoxs' right Encoder
* @param pinA : The pin on the arduino associated with the Encoders pin A output
* @param pinB : The pin on the arduino associated with the Encoders pin B output
*/
void PaintBot::setupRightGearBoxEncoder(int pinA, int pinB)
{
	if (_rightGearBox == NULL)
	{
		_rightGearBox = new GearBox();
	}
	_rightGearBox->setupEncoder(pinA, pinB);
}

/**
* Initializes or changes the arduino pins associated with the Encoders output pins
* with the left GearBoxs' right Encoder
* @param pinA : The pin on the arduino associated with the Encoders pin A output
* @param pinB : The pin on the arduino associated with the Encoders pin B output
*/
void PaintBot::setupLeftGearBoxEncoder(int pinA, int pinB)
{
	if (_leftGearBox == NULL)
	{
		_leftGearBox = new GearBox();
	}
	_leftGearBox->setupEncoder(pinA, pinB);
}

/**
* A combination of the setupMotor and setupEncoder methods so that both the right
* motor and encoder can be initialized with a single method
* See setupMotor and setupEncoder above for further documentation on each individual
* method
* @param rpwm : The pin on the arduino associated with the H bridge rpwm input
* @param lpwm : The pin on the arduino associated with the H bridge lpwm input
* @param pinA : The pin on the arduino associated with the Encoders pin A output
* @param pinB : The pin on the arduino associated with the Encoders pin B output
*/
void PaintBot::setupRightGearBox(int rpwm, int lpwm, int pinA, int pinB)
{
	if (_rightGearBox == NULL)
	{
		_rightGearBox = new GearBox(rpwm, lpwm, pinA, pinB);
	}
	else
	{
		_rightGearBox->setupMotor(rpwm, lpwm);
		_rightGearBox->setupEncoder(pinA, pinB);
	}
}

/**
* A combination of the setupMotor and setupEncoder methods so that both the left
* motor and encoder can be initialized with a single method
* See setupMotor and setupEncoder above for further documentation on each individual
* method
* @param rpwm : The pin on the arduino associated with the H bridge rpwm input
* @param lpwm : The pin on the arduino associated with the H bridge lpwm input
* @param pinA : The pin on the arduino associated with the Encoders pin A output
* @param pinB : The pin on the arduino associated with the Encoders pin B output
*/
void PaintBot::setupLeftGearBox(int rpwm, int lpwm, int pinA, int pinB)
{
	if (_leftGearBox == NULL)
	{
		_leftGearBox = new GearBox(rpwm, lpwm, pinA, pinB);
	}
	else
	{
		_leftGearBox->setupMotor(rpwm, lpwm);
		_leftGearBox->setupEncoder(pinA, pinB);
	}
}

/**
* Returns the position of the PaintBots right encoder
* @return : A long representing the encoders position
*/
long PaintBot::rightEncoderPosition(void) const
{
	return (_rightGearBox->encoderPosition);
}

/**
* Returns the position of the PaintBots left encoder
* @return : A long representing the encoders position
*/
long PaintBot::leftEncoderPosition(void) const
{
	return (_leftGearBox->encoderPosition);
}

/**
* Returns the number of rotations of the right encoder
* @return : A float representing the number of rotations of the encoder
*/
float PaintBot::rightEncoderRotation(void) const
{
	return (_rightGearBox->encoderRotations);
}

/**
* Returns the number of rotations of the left encoder
* @return : A float representing the number of rotations of the encoder
*/
float PaintBot::leftEncoderRotation(void) const
{
	return (_leftGearBox->encoderRotations);
}

/**
* Moves the center piece to the default center position of the painting canvas
*/
void PaintBot::resetCenterpiecePosition(void)
{
	if (_height > 0.0 && _width > 0.0)
	{
		moveTo(Vec2(_width / 2, _height / 2));
	}
}

static float positiveDifference(float n1, float n2)
{
  return (fabs(max(n1, n2)) - fabs(min(n1, n2)));
}

/**
* Moves from the current center-piece position by a given distance at a given angle
* @param distance : The distance to travel
* @param angleInRadians : The angle to travel in radians
*/
void PaintBot::moveByInDirection(float distance, float angleInRadians)
{
	float x;
	float y;

	x = _centerpiecePosition->x + distance * cos(angleInRadians);
	y = _centerpiecePosition->y + distance * sin(angleInRadians);
	// Checking if x and y are withing the height and width bounds is not needed
	// in this scope. The error checking is handled in the moveTo method
	moveTo(Vec2(x, y));
}

/**
* Moves the center piece to a coordinate position
* @param x : The horizontal position of the center piece in inches
* @param y : The vertical position of the center piece in inches
*/
void PaintBot::moveTo(float x, float y)
{
	moveTo(Vec2(x, y));
}

/**
* Moves the center piece to a coordinate position
* @param point : A 2d vector representing the coordinate to move to
*/
void PaintBot::moveTo(const Vec2& point)
{
	bool rightChainLengthAtTarget = false;
	bool leftChainLengthAtTarget = false;
	Vec2 topRight = Vec2(_width, _height);
	Vec2 topLeft = Vec2(0.0, _height);
	Vec2 currentRightAnchorPoint = Vec2(_centerpiecePosition->x + 5, _centerpiecePosition->y + 5);
	Vec2 currentLeftAnchorPoint = Vec2(_centerpiecePosition->x - 5, _centerpiecePosition->y + 5);
	Vec2 predictedRightAnchorPoint = Vec2(point.x + 5, point.y + 5);
	Vec2 predictedLeftAnchorPoint = Vec2(point.x - 5, point.y + 5);
	float rightChainTargetLength = distanceBetweenVectors(predictedRightAnchorPoint, topRight);
	float leftChainTargetLength = distanceBetweenVectors(predictedLeftAnchorPoint, topLeft);
	float rightChainDistanceTraveled = 0.0;
	float leftChainDistanceTraveled = 0.0;
	float rightMotorVoltage = 0.0;
	float leftMotorVoltage = 0.0;
	bool rightMotorClockwise = (_chainLengthRight > rightChainTargetLength);
 	bool leftMotorClockwise = (_chainLengthLeft < leftChainTargetLength);

	if (point.x >= 0.0 && point.x <= _width && point.y >= 0.0 && point.y <= _height)
	{
		// While the current chain lengths have not reached their target lengths, spin the motors.
		// Motor rotation direction is determined by the difference between the current chain
		// length and the target chain length. For example, if the rotating a motor clockwise
		// reduces the current length of the chain, and the target length is less than the
		// current length. Then clockwise rotatio will be used.
		_rightGearBox->setEncoderPosition(0);
		_leftGearBox->setEncoderPosition(0);
		while (rightChainLengthAtTarget == false || leftChainLengthAtTarget == false)
		{
			// Math for below: # of rotations of the encoder * the pitch diameter of the encoder
			// sprocket / the gear ratio between the driver sprocket and the encoder sprocket
			// 2.375 is the distance of chain retrieved or released per rotation of the 80 tooth sprocket
			rightChainDistanceTraveled = _rightGearBox->encoderRotations() * 2.375 / 8.0;
			leftChainDistanceTraveled = _leftGearBox->encoderRotations() * 2.375 / 8.0;
			// Priority of voltage is given to the motor that needs to travel further
			rightMotorVoltage = fabs(positiveDifference(_chainLengthRight, rightChainTargetLength) / max(positiveDifference(_chainLengthRight, rightChainTargetLength), positiveDifference(_chainLengthLeft, leftChainTargetLength)));
			leftMotorVoltage = fabs(positiveDifference(_chainLengthLeft, leftChainTargetLength) / max(positiveDifference(_chainLengthRight, rightChainTargetLength), positiveDifference(_chainLengthLeft, leftChainTargetLength)));
			if (rightChainLengthAtTarget == false)
			{
				if (rightMotorClockwise && _chainLengthRight + rightChainDistanceTraveled > rightChainTargetLength)
				{
					_rightGearBox->rotateMotorClockwise(rightMotorVoltage);
				}
				else if (!rightMotorClockwise && _chainLengthRight + rightChainDistanceTraveled < rightChainTargetLength)
				{
					_rightGearBox->rotateMotorCounterClockwise(rightMotorVoltage);
				}
				else
				{
					_rightGearBox->stopMotor();
					rightChainLengthAtTarget = true;
				}
			}
			if (leftChainLengthAtTarget == false)
			{
				if (!leftMotorClockwise && _chainLengthLeft + leftChainDistanceTraveled > leftChainTargetLength)
				{
					_leftGearBox->rotateMotorCounterClockwise(leftMotorVoltage);
				}
				else if (leftMotorClockwise && _chainLengthLeft + leftChainDistanceTraveled < leftChainTargetLength)
				{
					_leftGearBox->rotateMotorClockwise(leftMotorVoltage);
				}
				else
				{
					_leftGearBox->stopMotor();
					leftChainLengthAtTarget = true;
				}
			}
		}
    	_chainLengthRight += rightChainDistanceTraveled;
    	_chainLengthLeft += leftChainDistanceTraveled;
		*_centerpiecePosition = point;
	}
}
