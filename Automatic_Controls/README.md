# 42 Robotics Lab Painting Robot
Atuomatic movement controls for the painting robot created by the 42 Silicon Valley Robotics team.

## Installation
Dependencies: Encoder.h created by Paul Stoffregen https://github.com/PaulStoffregen/Encoder<br>
Encoder.h can also be added by searching for Enchoder.h via the instal library feature using<br>
the Arduino IDE.<br>
* Clone the repository
* Open the file 'PaintBotAutomaticControls.ino' located in the PaintBotAutomaticControls<br>
directory in the Arduino IDE
* Upload the code on to an Arduino board with at least 6 interrupt pins

## Using the PaintBot class
### Creating a PaintBot object
The PaintBot class has two constructors:
#### PaintBot(void)
#### PaintBot(float width, float height)

In order for the paint bot to move, the dimensions (in inches) of the canvas must be specified.<br>
If the default constructor is used, the height and width can be set by calling the methods:<br>

#### void setWidth(float width)
#### void setHeight(float height)

### Seting up the Motors and Encoders
The PaintBot class contains two GearBox objects. One for the left gear box, and one for the right gear box.<br>
Each GearBox needs to be setup individually using the PaintBot methods<br>

#### void setupRightGearBox(int rpwm, int lpwm, int pinA, int pinB)
#### void setupLeftGearBox(int rpwm, int lpwm, int pinA, int pinB)

The rpwmPin and lpwmPin variables are used to initialize the Motor class.<br>
pinA and pinB variables are used to initialize the Encoder class.<br>

### Moving the center piece using the PaintBot class
There are three methods for moving the center piece:
#### void moveByInDirection(loat distance, float angleInRadians)
* Moves from the current center-piece position by a given distance in inches at a given angle

#### void moveTo(float x, float y)
* Moves the center piece to a coordinate position

#### void moveTo(const Vec2& point)
* Moves the center piece to a coordinate position

## Debugging using the PaintBot class
Fortunately the vast majority of debugging comes from observing the position of the encoders.<br>
There four methods for retrieving encoder information within the PaintBot class.<br>

#### long rightEncoderPosition(void)
* Returns the right encoder position in its original format as a long

#### long leftEncoderPosition(void)
* Returns the left encoder position in its original format as a long

#### float rightEncoderRotation(void)
* Returns the right number of rotations completed by the right encoder as a float

#### float leftEncoderRotation(void)
* Returns the right number of rotations completed by the left encoder as a float

## What's left to do
### PID
A PID is needed to fine tune the voltage of the motors. Theoretically if the same<br>
voltage is applied to each motor, the motors will spin at the same speed. This is not<br>
the case. Due to resistance of the physical structure the motor speeds are inconsistent.<br>
The PID should correct for this error by monitoring the rates at which the motors spin.<br>
If the ratio of the rates do not match the ratio of the voltages given, then the voltages<br>
should be adjusted by the PID accordingly.<br>

### Addition of a trigger motor class
The code in this repository is solely focused on the movement of the center piece. The<br>
trigger motor class should handle the rotation of the z-axis motor that pushes the paint<br>
gun trigger. All movement of the z-axis motor should use the motors built in encoder.<br>

### G-Code
I know integrating G-Code is possible, however I have little to add on this topic. I ran<br>
out of time before I was able to do any research.<br>

## Additional notes
For further documentation and class functionality, refer to the .cpp files. All .cpp files<br>
have been documented in the format of doc-strings.<br>
For any 42 students that have questions, my intra is csinglet.
