/************************************************************* SPRAY ***********************************************************
 * Functions in this tab                                                                                                       *
 * 1. Spray              : Tturns the z motor to engage the trigger to start spraying                                          *
 * 2. stop_Spraying      : Turns the z motor to disengage the trigger to stop spraying                                         *
 * 3. main_ZMotor        : Main logic for mode CALLIBRATE_ZMOTOR: press to spin Zmotor, release to stop spinning               *
 * 4. spin_ZMotor        : Only used for mode CALLIBRATE_ZMOTOR: Determines the direction of spin of Zmotor (CW, CCW, or STOP) *
 * 5. check_spray_status : Checks if the trigger is on or off and disengages the trigger                                       *
 ******************************************************************************************************************************/

/*
 *  Changes the value in EEPROM of spray_Address to 1 (true for spraying)
 *  Rotates the encoder/motor by set angle to engage the trigger and start spraying
 */

void spray() {

  int encZ = MiddleMotorEnc.read();
  
  EEPROM.write(spray_address, 1);
  while(encZ > -1450)
  {
    analogWrite(ZMOTOR_A_Output, SRPAY_MAX_VOLTAGE);
    analogWrite(ZMOTOR_B_Output, 0);
    encZ = MiddleMotorEnc.read();  
  }
    
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, 0);
    Serial.print(MiddleMotorEnc.read());
    Serial.print(","); 
}

/*
 *  Changes the value in EEPROM of spray_Address to 0 (false for spraying)
 *  Rotates the encoder/motor by set angle to disengage the trigger and stop spraying
 */

int stopSpraying() {
  int encZ = MiddleMotorEnc.read();
      
  EEPROM.write(spray_address, 0);
  while (encZ < 0)
  {
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, SRPAY_MAX_VOLTAGE);
    encZ = MiddleMotorEnc.read();
  }
    
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, 0);
    Serial.println(MiddleMotorEnc.read());
    return (1);
}

/*
 *  Main logic of CALLIBRATE_ZMOTOR mode: 
 *  If the switch is pressed, the Zmotor spins in the indicated direction until switch is released
 *  @param click_status: input from digitalread to see if switch was clicked
 *  @param spin_direction: CW for clockwise, or CCW for Counterclockwise
 *  @param power: The ratio of power supplied to Zmotor to determine the speed of the spin
 */
 
void main_ZMotor(int click_status, int spin_direction, int power)
{
    while (click_status == CLICKED) {
      spinZMotor(spin_direction, power);
      int released = digitalRead(SW);
      if (released) {
        spinZMotor(Stop, power);
        break;
      }    
    }
}

/*
 *  Takes input and writes values to pins accordingly to spin clockwise, counterclockwise, or not at all
 *  @param: turnDirection: Choices of CW, CCW, and Stop
 *  @param: power: Ratio of pwer supplied to Zmotor to determine the speed of the spin
 */

void spinZMotor(int turnDirection, int power) {
   //turns in endless circle
   if (turnDirection == CW) {
       analogWrite(ZMOTOR_A_Output, 0);
       analogWrite(ZMOTOR_B_Output, power);
   } else if (turnDirection == CCW) {
       analogWrite(ZMOTOR_A_Output, power);
       analogWrite(ZMOTOR_B_Output, 0);
   } else if (turnDirection == Stop) {
       analogWrite(ZMOTOR_A_Output, 0);
       analogWrite(ZMOTOR_B_Output, 0);
   }
}

/*
 *  function that checks the global variable of spray_status from EEPROM on Arduino
 *  and executes the stopSpraying function if case is true for spraying
 */

void  check_spray_status()
{
    if (spray_status == 1) {
      stopSpraying();
      Serial.print("new spray_status=");
      Serial.println(spray_status);
      spray_status = EEPROM.read(spray_address);
    }
}
