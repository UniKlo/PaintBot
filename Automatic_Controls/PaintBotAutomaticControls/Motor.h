#include <arduino.h>

#ifndef MOTOR_H
# define MOTOR_H

class Motor
{
	private:
		int _rpwmPin, _lpwmPin;
	public:
		Motor(void);
		Motor(int, int);
		~Motor(void);
		void setRpwm(int);
		void setLpwm(int);
		void rotateClockwise(float);
		void rotateClockwise(int);
		void rotateCounterClockwise(float);
		void rotateCounterClockwise(int);
		void stop(void);
		void swapRotation(void);
		void write(float);
};

#endif
