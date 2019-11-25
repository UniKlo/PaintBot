#include <arduino.h>

#ifndef JOYSTICK_H
# define JOYSTICK_H

class Joystick {
  public:
    int readX;
    int readY;
    int neutral;
    int jsDeadZone;
    void updateJoystick(void);
    bool joystickIsActive(void);
    void joystickMove(int, int);
}

#endif
