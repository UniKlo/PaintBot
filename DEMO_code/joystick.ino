/********************************** Joystick ***********************************
 *  Functions for control motor to move any direction we want.                 *
 *  Based on joystick input value, move the centerpiece up, right, left, down. *
 *  @param  VRx           : Joystick x pin number                              *
 *  @param  VRy           : Joystick y pin number                              *
 *  @param  VolL          : Control left motor speed                           *
 *  @param  VolR          : Control right motor speed                          *
 ******************************************************************************/

void joystick(const int VRx, const int VRy, const int volL, const int volR)
{
  int readX = 500;         // Center point of Joystick X position
  int readY = 500;         // Center point of Joystick Y position
  
  readX = analogRead(VRx);
  readY = analogRead(VRy);
  while (readX < 300)
  {
    goRight(volL, volR);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
  while (readX > 700)
  {
    goLeft(volL, volR);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
  while (readY < 300)
  {
    goUp(volL, volR);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
  while (readY > 700)
  {
    goDown(volL, volR);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
}
