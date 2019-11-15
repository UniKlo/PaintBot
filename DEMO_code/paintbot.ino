/************************** Code Usage ******************************
 *  This program is for paint bot which can paint 3 ft by 3 ft area *
 *  This code is divided to 5 sections,                             *
 *  1. main                                                         *
 *    (a) Variable Definition                                       *
 *    (b) Setup                                                     *
 *    (c) Loop                                                      *
 *  2. joystick                                                     *
 *  3. move                                                         *
 *  4. spray                                                        *
 *  5. square                                                       *
 *  6. loop                                                         *
 *******************************************************************/

/************************ (a) Variable Definition *************************
 * Define the variable for Joystick, Encoder, Motor and Spray Gun control *
 *************************************************************************/
 
#include <Encoder.h>
#include <EEPROM.h>

#define SRPAY_MAX_VOLTAGE 255
#define MOTOR_VOLTAGE 200

// Joystic pin number
const int VRx = A1;                                  // Joystick x axis
const int VRy = A0;                                  // Joystick y axis
const int SW = 13;

// Right encoder pin number
const int encoderRightA = 20;                        // Green - pin 20 - Digital
const int encoderRightB = 21;                        // White - pin 21 - Digital

// Left encoder pin number
const int encoderLeftA = 18;                         // Green - pin 18 - Digital
const int encoderLeftB = 19;                         // White - pin 19 - Digital

const int RPWMOutputRight = 10;                      // Arduino PWM output pin 10; connect to IBT-2 pin 1 (RPWM)
const int LPWMOutputRight = 11;                      // Arduino PWM output pin 11; connect to IBT-2 pin 2 (LPWM)

const int RPWMOutputLeft = 8;                        // Arduino PWM output pin 8; connect to IBT-2 pin 1 (RPWM)
const int LPWMOutputLeft = 9;                        // Arduino PWM output pin 9; connect to IBT-2 pin 2 (LPWM)

const int ZMOTOR_A_Output = 6;                       // Arduino PWM output pin 6; connect to IBT-2 pin 1 (RPWM)
const int ZMOTOR_B_Output = 7;                       // Arduino PWM output pin 7; connect to IBT-2 pin 2 (LPWM)
const int encoderMidA = 2;                           // White - pin 2 - Digital
const int encoderMidB = 3;                           // Tan - pin 3 - Digital

// CW gives positive encoder values
// CCW gives negative encoder values
enum turnDirections {
  CW,                                                // Clockwise
  CCW,                                               // CounterClockwise
  Stop
};

enum joystickClickStatuses {
  CLICKED,                                           //This value is 0 when switched is clicked
  NOT_CLICKED                                        // This value is 1 when switched is not clicked
};

enum mode_of_machine {
  MOVING,                                            // For moving centerpiece only
  SQUARE,                                            // For moving centerpiece and running do_square
  CALLIBRATE_ZMOTOR,                                  // For callibrating zmotor
  TEST_SPRAY                                         // For testing spray gun working
};

const int spray_address = 42;
int spray_status = EEPROM.read(spray_address);

Encoder leftMotorEnc(encoderLeftA, encoderLeftB);
Encoder rightMotorEnc(encoderRightA, encoderRightB);
Encoder MiddleMotorEnc(encoderMidA, encoderMidB);

long encoderLeft = 0;
long encoderRight = 0;
long encoderMiddle = 0;
bool done = false;
long encL = 48000L;
long encR = 48000L;

// test loop number
int loopNum = 1;

/************************ (b) Setup ************************
 * Arduino setup to connect Motors and Joystick to control *
 ***********************************************************/
 
void setup() {
  
  Serial.begin(9600);

  // MOVEMENT MOTORS
  pinMode(RPWMOutputLeft, OUTPUT);
  pinMode(LPWMOutputLeft, OUTPUT);
  pinMode(RPWMOutputRight, OUTPUT);
  pinMode(LPWMOutputRight, OUTPUT);

  // JOYSTICK
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);

}

/************************ (c) Loop **********************************
 * Loop for controlling arduino. We can choose one of 4 modes,      *
 * 1. SQUARE :             moving centerpiece only                  *
 * 2. CALLIBRATE_ZMOTOR :  callibrating zmotor                      *
 * 3. MOVING :             moving centerpiece and running do_square *
 * 4. TEST_SPRAY :         testing spray gun working                *
 *******************************************************************/
 
void loop() {
  int mode = SQUARE;

  switchControl(mode);
}
