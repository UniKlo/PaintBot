/*
 * Author:  Sanghyun Ko, Felipe Prevelato, Casey Singleton, David Gaitsgory, Vincent Zhao, Robert Papagna
 * Created: 11.12.2019
 *
 * (c) Copyright by 42 Robolab.
 */

/************************** MOVEMENTS **************************
 *  Functions for control motor to move any direction we want. *
 ***************************************************************/

/*
 *  Move the centerpiece upward with same speed for both motor
 *  @param  vol : Input to control the both motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goUp(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
    
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

/*
 *  Move the centerpiece upward with differnt speed for each motor
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goUp(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, volL);
    
    analogWrite(RPWMOutputRight, volR);
    analogWrite(LPWMOutputRight, 0);
}

/*
 *  Move the centerpiece downward with same speed for both motor
 *  @param  vol : Input to control the both motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goDown(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

/*
 *  Move the centerpiece downward with same speed for both motor
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goDown(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, volL);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, volR);
}

/*
 *  Move the centerpiece rightward with same speed for both motor
 *  @param  vol : Input to control the both motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goRight(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

/*
 *  Move the centerpiece rightward with same speed for both motor
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goRight(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, volL);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, volR);
    analogWrite(LPWMOutputRight, 0);
}

/*
 *  Move the centerpiece leftward with same speed for both motor
 *  @param  vol : Input to control the both motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goLeft(int vol)
{
  if (vol >= 255)
    vol = 255;    
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

/*
 *  Move the centerpiece leftward with same speed for both motor
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */
 
void goLeft(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, volL);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, volR);
}

/*
 *  Move the centerpiece upward and rightward
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */

void goUpRight(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(LPWMOutputRight, volL);
    analogWrite(RPWMOutputRight, volR);
}

/*
 *  Move the centerpiece downward and leftward
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */

void goDownLeft(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(LPWMOutputRight, volL);
    analogWrite(RPWMOutputRight, volR);
}

/*
 *  Move the centerpiece upward and leftward
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */

void goUpLeft(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(LPWMOutputRight, volL);
    analogWrite(RPWMOutputRight, volR);
}

/*
 *  Move the centerpiece downward and rightward
 *  @param  volL : Input to control the left motor speed (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed (fraction of 255 resulting between 0 to 24 Volts)
 */

void goDownRight(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(LPWMOutputRight, volL);
    analogWrite(RPWMOutputRight, volR);
}

/*
 *  Stop moving left motor
 */
 
void stopLeft()
{
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, 0);
}

/*
 *  Stop moving right motor
 */
 
void stopRight()
{
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, 0);
}

/*
 *  Stop moving both motor
 */
 
void doStop()
{
    stopLeft();
    stopRight();
}

/*
 *  This function allows the centerpiece to move as well as use the to turn the sprayer on and off
 *  If the trigger is on, then you will not be able to move the centerpiece
 *  @param  click_status : status for checking the spray shoot. If it is false, do painting, otherwise stop painting.
 */

void main_Moving_with_trigger(int click_status)
{
  int spraying = false;
  
  joystick(VRx, VRy, encoderLeft, encoderRight);
  if (click_status == 0 && spraying == false) {
    spray();
    spraying = true;
  }
  while (spraying == true) {
    Serial.println(EEPROM.read(spray_address));
    if (digitalRead(SW) == 0) {
      stopSpraying();
      spraying = false;
    }
//  Serial.println("Press the switch again to move");
  }
}

/*
 *  Move upward until both encoder values meet more than pos value.
 *  @param  volL : Input to control the left motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveUp(int volL, int volR, long posH)
{
  while (1)
  {
    Serial.print(leftMotorEnc.read());
    Serial.print(" - ");
    Serial.println(rightMotorEnc.read());
    goUp(volL, volR);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft < -posH) && (encoderRight > posH))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

/*
 *  Move leftward until both encoder values meet more than pos value.
 *  @param  volL : Input to control the left motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveLeft(int volL, int volR, long pos)
{
  while (1)
  {
    Serial.print(leftMotorEnc.read());
    Serial.print(" - ");
    Serial.println(rightMotorEnc.read());
    goLeft(volL, volR);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft < -pos) && (encoderRight < -pos))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

/*
 *  Move downward until both encoder values meet more than pos value.
 *  @param  volL : Input to control the left motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveDown(int volL, int volR, long posH)
{
  while (1)
  {
    Serial.print(leftMotorEnc.read());
    Serial.print(" - ");
    Serial.println(rightMotorEnc.read());
    goDown(volL, volR);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > posH) && (encoderRight < -posH))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

/*
 *  Move rightward until both encoder values meet more than pos value.
 *  @param  volL : Input to control the left motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  volR : Input to control the right motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveRight(int volL, int volR, long pos)
{
  while (1)
  {
    Serial.print(leftMotorEnc.read());
    Serial.print(" - ");
    Serial.println(rightMotorEnc.read());
    goRight(volL, volR);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > pos) && (encoderRight > pos))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

/*
 *  Move upward rightward until both encoder values meet more than pos value.
 *  @param  volL : Input to control the right motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveUpRight(int vol, long pos)
{
  while (1)
  {
    goUpRight(0, vol);
    encoderRight = rightMotorEnc.read();
    if (encoderRight > pos)
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

/*
 *  Move downward leftward until both encoder values meet more than pos value.
 *  @param  volL : Input to control the right motor speed  (fraction of 255 resulting between 0 to 24 Volts)
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveDownLeft(int vol, long pos)
{
  while (1)
  {
    goDownLeft(vol, 0);
    encoderRight = rightMotorEnc.read();
    if (encoderRight < -pos)
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}
