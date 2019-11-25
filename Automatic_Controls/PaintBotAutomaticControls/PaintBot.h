#include <arduino.h>
#include "GearBox.h"
#include "Joystick.h"

#ifndef PAINTBOT_H
# define PAINTBOT_H

class PaintBot
{
	private:
		GearBox* _rightGearBox;
		GearBox* _leftGearBox;
		Vec2* _centerpiecePosition;
		float _height, _width, _chainLengthRight, _chainLengthLeft;
		Joystick _joystick;
	public:
		PaintBot(void);
		PaintBot(float, float);
		~PaintBot(void);
		void setHeight(float);
		void setWidth(float);
		void setCenterpiecePosition(float, float);
		void setupRightGearBoxMotor(int, int);
		void setupLeftGearBoxMotor(int, int);
		void setupRightGearBoxEncoder(int, int);
		void setupLeftGearBoxEncoder(int, int);
		void setupRightGearBox(int, int, int, int);
		void setupLeftGearBox(int, int, int, int);
		void setupJoystick(int, int);

		long rightEncoderPosition(void) const;
		long leftEncoderPosition(void) const;
		float rightEncoderRotation(void) const;
		float leftEncoderRotation(void) const;

		void resetCenterpiecePosition(void);
		void moveByInDirection(float, float);
		void moveTo(float, float);
		void moveTo(const Vec2&);
		void joystickMove(void);
};

#endif
