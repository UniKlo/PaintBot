#include <arduino.h>

#ifndef JOYSTICK_H
# define JOYSTICK_H

class Joystick {
  private:
    int _xPin, _yPin;
  public:
    int _xPos;
    int _yPos;
    int _neutral;
    int _deadZone;
    void updateJoystick(void);
    bool joystickIsActive(void);
    void joystickMove(int, int);
    void setPins(int, int);
    void setSensitivity(int, int, int);
}
#endif
