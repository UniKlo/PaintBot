#include "PaintBot.h"

/**
* This is an example of setting up and using the PaintBot class to move the
* center piece of the painting robot.
*
* @author Casey Singleton
* @version 1.0
*/

#define CANVAS_WIDTH 84.5
#define CANVAS_HEIGHT 64
// UP, DOWN, RIGHT, LEFT are directions in radians
#define UP PI / 2
#define DOWN 3 * PI / 2
#define RIGHT 0
#define LEFT PI

enum Directions {
  Left,
  Right,
  Up,
  Down
};


// Right motor H-bridge rpwm and rpwm pins
int rightMotorRpwmPin = 10;
int rightMotorLpwmPin = 11;
// Right encoder logic pins A and B
int rightEncoderPinA = 20;
int rightEncoderPinB = 21;
// Left motor H-bridge rpwm and rpwm pins
int leftMotorRpwmPin = 10;
int leftMotorLpwmPin = 11;
// Left encoder logic pins A and B
int leftEncoderPinA = 20;
int leftEncoderPinB = 21;
// Joystick pins
int jsX = A1;
int jsY = A0;
int once;
PaintBot pb = PaintBot(CANVAS_WIDTH, CANVAS_HEIGHT);

void setup()
{
  Serial.begin(9600);
  // Setting up the right gear box with the proper motor and encoder information
  pb.setupRightGearBox(rightMotorRpwmPin, rightMotorLpwmPin, rightEncoderPinB, rightEncoderPinA);
  // Setting up the left gear box with the proper motor and encoder information
  pb.setupLeftGearBox(leftMotorRpwmPin, leftMotorLpwmPin, leftEncoderPinA, leftEncoderPinB);
  once = 0;
}

// Movement over long distances is not accurate without a PID
void loop()
{
  if (once < 1)
  {
	// Movement using distance and direction in radians
    pb.moveByInDirection(12, LEFT); // Moving by 12 inches in the left direction
    pb.moveByInDirection(6, UP); // Moving by 6 inches in the up direction
    pb.moveByInDirection(24, RIGHT); // Moving by 24 inches in the right direction
    pb.moveByInDirection(6, DOWN); // Moving by 6 inches in the down direction
    pb.moveByInDirection(12, LEFT); // Moving by 12 inches in the left direction

	// Movement using coordinates
	pb.moveTo(CANVAS_WIDTH / 2 - 12, CANVAS_HEIGHT / 2); // Moving by 12 inches in the left direction
	pb.moveTo(CANVAS_WIDTH / 2 - 12, CANVAS_HEIGHT / 2 + 6); // Moving by 6 inches in the up direction
	pb.moveTo(CANVAS_WIDTH / 2 + 12, CANVAS_HEIGHT / 2 + 6); // Moving by 24 inches in the right direction
	pb.moveTo(CANVAS_WIDTH / 2 + 12, CANVAS_HEIGHT / 2); // Moving by 6 inches in the down direction
	pb.moveTo(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2); // Moving by 12 inches in the left direction

	// Note that the starting coordinate of the center piece will always be width / 2 by height / 2
	// This means the user has to keep track of the position of the center piece. This can be made
	// easier by using the Vec2 class
	Vec2 pos = Vec2(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2);
	pos += Vec2(-12, 0);
	pb.moveTo(pos); // Moving by 12 inches in the left direction
	pos += Vec2(0, 6);
	pb.moveTo(pos); // Moving by 6 inches in the up direction
	pos += Vec2(24, 0);
	pb.moveTo(pos); // Moving by 24 inches in the right direction
	pos += Vec2(0, -6);
	pb.moveTo(pos); // Moving by 6 inches in the down direction
	pos += Vec2(-12, 0);
	pb.moveTo(pos); // Moving by 12 inches in the left direction

	// moveByInDirection() is the easiest for a user to understand, however, for automations
	// purposes it is better to use moveTo with a list of Vec2 points
  }
  once = 1;
}
