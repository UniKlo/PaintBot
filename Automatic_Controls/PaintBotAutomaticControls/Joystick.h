#include <arduino.h>

#ifndef JOYSTICK_H
# define JOYSTICK_H

class Joystick {
  private:
    int _xPin, _yPin;
  public:
    int _readX;
    int _readY;
    int _neutral;
    int _deadZone;
    void updateJoystick(void);
    bool joystickIsActive(void);
    void joystickMove(int, int);
}

#endif
