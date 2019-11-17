#include <arduino.h>
#include <Encoder.h>
#include "Motor.h"
#include "Vector.h"

#ifndef GEARBOX_H
# define GEARBOX_H

class GearBox
{
	private:
		Motor* _motor;
		Encoder* _encoder;
	public:
		GearBox(void);
		GearBox(int, int, int, int);
		~GearBox(void);
		void setupMotor(int, int);
		void setupEncoder(int, int);
		void setEncoderPosition(long);
		float encoderRotations(void) const ;
		long encoderPosition(void) const;
		long encoderAbsolutePosition(void) const;
		void rotateMotorClockwise(int);
		void rotateMotorClockwise(float);
		void rotateMotorCounterClockwise(int);
		void rotateMotorCounterClockwise(float);
		void stopMotor(void);
		void swapMotorRotation(void);
};

#endif
