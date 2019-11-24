# PaintBot
Paintbot is a machine that paints upright surfaces. It's a prototype that can paint indoor walls. The goal of this prototype is to extend it to paint or draw on walls of any size, indoors and outdoors alike. This document is a wiki for the robot's mechanics, electronics and code.<br/>

| Overview | Demonstration |
:-------------------------:|:-------------------------:
![](https://github.com/UniKlo/PaintBot/blob/master/img_gif/paintbot_v5.png) | ![](https://github.com/UniKlo/PaintBot/blob/master/img_gif/demo.gif) <br/> Autonomously paints a 3'x 3' square on the wall <br/> [Youtube link](https://www.youtube.com/watch?v=X723J_k0E64&feature=youtu.be)

## Mechanics
| | **Part** | **Description** |
:---:|:-------------------------:|:-------------------------
A. | **Motor Rack with Tensioner** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/motor_rack_with_tensioner_H.jpg" height="300px"> | Device that controls the movement of the centerpiece and spray gun by feeding or withdrawing chain from opposite ends <br/><br/> [Design goals, parts, CAD drawings/documents](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorRack) <br/><br/> [How to assemble](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/How%20to%20Assemble/Motor%20Rack%20with%20Tensioner/README.md)
B. | **Centerpiece** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/center_piece_H.jpg" height="300px"/> | Placeholder for spray-gun to ensure proper upright position during spraying <br/><br/> [Design goals, Force diagrams, CAD drawing/documents, and Iterations](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Centerpiece)
C. | **Spray Gun Holder** <br/> <img src="https://i.imgur.com/Dsu4iA6.jpg" height="300px"/> | Encasing used to hold the spray gun upright and controls whether to engage or disengage spraying during operation <br/><br/> [Design goals, Parts, CAD drawing/documents](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/SprayGunHolder) <br/><br/> [How to assemble](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/How%20to%20Assemble/Spray%20Gun%20Holder)
D. | **Safety Brace** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/safety_brace_H.jpg" height="300px" width="400px"> | Passive device that acts as a physical barrier to prevent the pulley weights from colliding with the bracket under "Motor Rack with Tensioner part" <br/> - Other functions include: <br/> -- Preventing the pulley weights from descending too low <br/> -- Catching the pulley weights in case of chain system failure <br/> -- Strapping the pulley weights in place during transportation of the PaintBot <br/> - Note: Ratchet straps are used in coordination with this passive device <br/> There are a total of 4 Safety Braces on the Frame (2 on the front and back of each pillar) <br/><br/> [Design goals, Force Diagrams, and CAD drawing/documents](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/Safety%20Brace/README.md) <br/><br/> [How to Assemble](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/How%20to%20Assemble/Safety%20Brace/README.md)
E. | **Wooden Bracket** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/safety%20brackets.jpg" height="300px"/>| Device that is designed to handle forces from the tension in the chain system by holding the chain in place during operations <br/><br/> [Design Goals, Force Diagrams, CAD Drawings/Documents](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/Wooden%20Bracket/README.md) <br/> <br/> [How to Assemble](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/How%20to%20Assemble/Wooden%20Bracket/README.md)
F. | **Pulley Weight** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/pulley%20weights.jpg" height="300px"/>  |  Weights used to create tension in our chains to allow Cartesian control <br/><br/> [Design Goals](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleyWeights) <br/> <br/> [How to Assemble](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/How%20to%20Assemble/Pulley%20Weights/README.md)
G. | **Frame** <br/> <img src="https://imgur.com/GtiJIYm.jpg" width="400"> | <br/> Structure, created with 2" x 4" wood studs, to provide an exoskeleton for the Paintbot <br/><br/> [Design goals](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Pillar) <br/><br/> [How to assemble](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/How%20to%20Assemble/Frame/README.md)
H. | **Chain system** <br/> <img width="400px" alt="Chain System" src="https://user-images.githubusercontent.com/49771001/69489288-37743780-0e2a-11ea-8122-9b9f2348c3bc.jpg"> | Pulley System developed with #25 ANSI Standard Roller Chains to utilize the torque in the motor to control the movement of the Centerpiece in Cartesian plane
 <br/><br/> [Design considerations, Force diagrams, Parts, and More Photos](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/ChainSystem) <br/><br/> [Chain Layout]() | - Design and Chain hook-up throughout the robot
I. | **Paint Compressor** <br/> <img width="400px" alt="Paint Compressor" src="https://user-images.githubusercontent.com/49771001/69471953-9c139180-0d59-11ea-84b0-b35e9d8fb10f.png"> | Magnum Project Painter Plus Electric TrueAirless Sprayer <br/> - Device used to pressurize and spray paint <br/><br/> [Design considerations](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Paint%20Compressor) <br/><br/> [How to Connect/Use (Youtube Video by GracoPaintSprayers)](https://www.youtube.com/watch?v=pey29Z3UQR4)
J. | **Control Box** <br/> <img width="400" alt="Control Box" src="https://user-images.githubusercontent.com/49771001/69489268-efedab80-0e29-11ea-86c0-b64131e187a6.png"> | Wiring Schematics <br/> <img src="https://user-images.githubusercontent.com/49771001/69264211-b2fc8d00-0b7b-11ea-83b4-03c42b3dda64.jpg" height="300px" width="350px"> <br/> [More info on ](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/Electric%20Circuits/README.md)


## Electronics
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
