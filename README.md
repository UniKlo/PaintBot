# PaintBot
Paintbot is a machine that paints upright surfaces. It's a prototype that can paint indoor walls. The goal of this prototype is to extend it to paint or draw on walls of any size, indoors and outdoors alike. This document is a wiki for the robot's mechanics, electronics and code.<br/>

| Overview | Demo |
:-------------------------:|:-------------------------:
![](https://user-images.githubusercontent.com/49771001/69208512-aee35780-0b08-11ea-93d2-45092e5c55ee.png) | ![](https://github.com/UniKlo/PaintBot/blob/master/img_gif/demo.gif)

## Mechanics
| Part | Description |
:-------------------------:|:-------------------------:
![Motor Rack with Tensioner](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorRack)<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/motor%20rack%20with%20tensioner.jpg" height="300px"> |- Controls the movement and location of the centerpiece by feeding or withdrawing chain from opposite ends using proper motor control
![Centerpiece](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Centerpiece)<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/center%20piece.jpg" height="300px"/> | - Placeholder for spray-gun to ensure proper upright position during spraying
![Spray Gun Holder](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/SprayGunHolder)<br/><img src="https://i.imgur.com/Dsu4iA6.jpg" height="300px"/> | - Case used to hold spray-gun along with the motor that controls activation and deactivation of spray
![Motor Block](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorBlock)<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/side.jpg" height="300px"/> | - Encasing for Motor Rack to ensure proper alignment of chains and sprockets
![Safety Brace](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleySystem)<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/safety%20brace.jpg" height="300px"/> | - Protects against impact and dropping of weights
![Wooden Bracket]()<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/safety%20brackets.jpg" height="300px"/> | - Devices to ensure safe operations
![Pulley System](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleyWeights)<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/pulley%20weights.jpg" height="300px"/> | Weight for system
![Pillar](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Pillar)<br/>Need a picture here | - Part of the frame of the PaintBot
![Chain System](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/ChainSystem)<br/>Need a picture here | - Design and Chain hook-up throughout the robot
![Paint Compressor]()<br/>Need a picture here | - compressor for the paint
![Electric Circuits]()<br/>Need a picture here | - Wiring schematics
![2x4 Wood Stud]()Need a picture here | - Standard 2x4 Wood Framing Stud, please include what paint was used


## Electronics
  - ### Wiring Schematics
    * [Circuits and Connections with Pictures](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Wiring)
  
  - ###  Parts Reference
    * [Spray Gun](https://www.amazon.com/Graco-257025-Project-Painter-Sprayer/dp/B004Z2090U/ref=asc_df_B004Z2090U/?tag=hyprod-20&linkCode=df0&hvadid=198077767340&hvpos=1o2&hvnetw=g&hvrand=15997159825197345473&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032020&hvtargid=pla-373698499647&psc=1)
    * [Arduino Mega 2560](https://store.arduino.cc/usa/mega-2560-r3)
    * [H-Bridge](https://www.amazon.com/HiLetgo-BTS7960-Driver-Arduino-Current/dp/B00WSN98DC)
    * [12v Power Supply](https://www.amazon.com/MENZO-Universal-Regulated-Switching-Computer/dp/B06VWV5YCH)
    * [XY Motors](https://electricscooterparts.com/motors-my6812.html)
    * [Z-Axis Motor](https://www.makermadecnc.com/product/z-axis-replacement-motor/)

## Code
### [Demo 11/12/2019](https://github.com/UniKlo/PaintBot/tree/master/DEMO_code) <br/>
This used the encoders' output to control the displacement of the centerpiece so the paintbot could spray 3ft. x 3ft. area on the wall.

### [Automatic Controls](https://github.com/UniKlo/PaintBot/tree/master/Automatic_Controls)

## Use
 * For an even coat, each spray layer should have 50% overlay
 * The spray-gun should 1ft. away from the wall
 
## Previous Iterations
 * [V-Plotter](https://github.com/UniKlo/PaintBot/tree/master/Iterations/V-Plotter)
