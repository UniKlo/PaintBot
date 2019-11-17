/*
 * Author:  Sanghyun Ko, Felipe Prevelato, Casey Singleton, David Gaitsgory, Vincent Zhao, Robert Papagna
 * Created: 11.12.2019
 *
 * (c) Copyright by 42 Robolab.
 */

/************************ SWITCH CONTROL ****************************
 * Loop for controlling arduino. This loop consists 4  parts,       *
 * 1. SQUARE            :  moving centerpiece only                  *
 * 2. CALLIBRATE_ZMOTOR :  callibrating zmotor                      *
 * 3. MOVING            :  moving centerpiece and running do_square *
 * 4. TEST_SPRAY        :  testing spray gun working                *
 * @param   mode        :  Select mode for control the arduino
 *******************************************************************/

void  switchControl(int mode)
{
  int turn = digitalRead(SW);
  switch (mode) {
  case SQUARE:
  {
    if (turn)
      joystick(VRx, VRy, MOTOR_VOLTAGE, MOTOR_VOLTAGE);
    else
    {
      while (!done)
      {
        resetEncoder();
        for (int i = 0; i < loopNum; i++) {
          square(encL *  2.5, encL * 0.5);
        }
        break ;
      }
    }
    break;
  }
  case CALLIBRATE_ZMOTOR:
    main_ZMotor(digitalRead(SW), CCW, SRPAY_MAX_VOLTAGE/2);
    break;
  case MOVING:
    main_Moving_with_trigger(digitalRead(SW));
    break;
  case TEST_SPRAY:
    if (turn == 0) {
      for (int i = 0; i < loopNum; i++) {
        spray();
        stopSpraying();
      }
    }
    break;
  }
}

/*
 *  Reset the both encoder values.
 */
 
void  resetEncoder()
{
  leftMotorEnc.write(0);
  rightMotorEnc.write(0);
  delay(100);
  leftMotorEnc.write(0);
  rightMotorEnc.write(0);
}
