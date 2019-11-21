# PaintBot
Paintbot is a machine that paints upright surfaces. It's a prototype that can paint indoor walls. The goal of this prototype is to extend it to paint or draw on walls of any size, indoors and outdoors alike. This document is a wiki for the robot's mechanics, electronics and code.<br/>

| Overview | Demonstration |
:-------------------------:|:-------------------------:
![](https://github.com/UniKlo/PaintBot/blob/master/img_gif/paintbot_v5.png) | ![](https://github.com/UniKlo/PaintBot/blob/master/img_gif/demo.gif) <br/> Autonomously paints a 3'x 3' square on the wall

## Mechanics
| Part | Description |
:-------------------------:|:-------------------------:
Motor Rack with Tensioner <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/motor_rack_with_tensioner_H.jpg" height="300px"> | [More info for Rack](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorRack)<br/>[More info for Motor Block](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorBlock)<br/>- Controls the movement and location of the centerpiece by feeding or withdrawing chain from opposite ends using proper motor control<br/>- Encasing for Motor Rack to ensure proper alignment of chains and sprockets
Centerpiece<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/center_piece_H.jpg" height="300px"/> | [More info for Centerpiece](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Centerpiece)<br/>- Placeholder for spray-gun to ensure proper upright position during spraying
Spray Gun Holder<br/><img src="https://i.imgur.com/Dsu4iA6.jpg" height="300px"/> | [More info for Spray Gun Holder](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/SprayGunHolder)<br/> - Case used to hold spray-gun along with the motor that controls activation and deactivation of spray
Safety Brace <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/safety_brace_H.jpg" height="300px" width="400px"> | <div style="text-align: left">  [More Info for Safety Brace](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleySystem) <br/> - Passive device that acts as a physical barrier to prevent the pulley weights from colliding with the "Motor Rock with Tensioner part" <br/> - Other functions inclue: <br/> -- Preventing the pulley weights from descending too low <br/> --Catching the pulley weights in case of chain system failure <br/> -- Strapping the pulley weights in place during transportation of the PaintBot <br/> - Note: Ratchet straps are used in coordination with this passive device. <br/> - Note: THere are a total of 4 Safety Braces on the Frame (2 on the front and back fo each pillar) <br/> [How to Assemble]() </div>
Wooden Bracket<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/safety%20brackets.jpg" height="300px"/>| [More info for Wooden Bracket]()<br/> - Devices to ensure safe operations
Pulley Weight<br/><img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/pulley%20weights.jpg" height="300px"/> | Pulley Weights<br/> | [More info for Pulley Weights](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleyWeights)<br/> Weight for system
Frame <br/> Need a picuture? | [More info on Pillar](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Pillar)<br/> - Part of the frame of the PaintBot <br/> - Standard 2x4 Wood Framing Stud, please include what paint was used
Chain system<br/>Need a picture here | [More info on Chain System](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/ChainSystem) | - Design and Chain hook-up throughout the robot
Paint Compressor <br/> Need a picture here | [More info on Paint Compressor]() <br/> - compressor for the paint
Control Box <br/> What picture to use here? | Wiring Schematics <br/> <img src="https://user-images.githubusercontent.com/49771001/69264211-b2fc8d00-0b7b-11ea-83b4-03c42b3dda64.jpg" height="300px" width="350px"> <br/> [More info on ]()


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
