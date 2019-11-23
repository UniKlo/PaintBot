# Motor Rack with Tensioner

 <img src="https://github.com/UniKlo/PaintBot/blob/master/img_gif/motor_rack_with_tensioner_H.jpg" width="250px">  <img src="https://imgur.com/nwCuBPG.jpg" width="250">   <img src="https://imgur.com/Q2PnVoB.jpg" width="250">

For full design view: [OnShape Document](https://cad.onshape.com/documents/c35a5db4d6efdd4b831e7e66/w/d232ff81f911a9e59ca8bc06/e/0a6c8383d003cd06b363736f)

### Design goals

* Align the encoder, motor, Sprockets for safe and consistently operations
* Use the least amount of power to control movement of centerpiece while increasing mechanical advantage of motor 
| Assumptions | Calculations |
| :--- | :--- |
9 Tooth #25 chain
⇒ Pitch = ¼ “ 
⇒ # of Teeth (N) = 9
Radius of sprocket = PD2
1” = 2.54 cm
1 kg = 2.2 lbs
1 N = 1 kg * 9.8 m/s2
Torque = Force x perpendicular distance 
Perpendicular distance = radius of sprocket
Pitch Diameter (PD) = Pitch(P) / sin(180N)

Torque = Force x distance
Torque = (Weight) x (radius of 9 teeth sprocket on motor) 
Torque = Weight x PD / 2
Torque = Weight x Pitch(P) / 2 * sin(180 / N)
Weight = Torque * 2sin(180/N) /Pitch = 0.34 Nm * 2sin(180 / 9) / 0.25" * 1" / 0.0254 m * 1 / 9.8 m/s2
**Max Weight Motor can lift = ~10 kg = ~22 lbs**
**Note: Pulley system is designed as a 1:4 pulley system so motor is just pulling ¼ * hanging weight (currently hanging weight is 27 lbs)**

## Parts
| | Part | Description |
|:-: | :---: | :--- |
A. | **Motor** <br/> <img width="274" alt="Scooter Motor" src="https://user-images.githubusercontent.com/49771001/69472945-4218c900-0d65-11ea-82c6-2e8c3950b605.png"> | [24 Volt 100 Watt MY6812 Electric Motor with 9 Tooth #25 Chain Sprocket](https://www.monsterscooterparts.com/rae124vo100w.html)
B. | **Rotary Encoder** <br/> <img width="290" alt="Rotary Encoder" src="https://user-images.githubusercontent.com/49771001/69473098-55c52f00-0d67-11ea-830c-afe1d32d1d45.png"> | [Optical encoder 360 ppr LPD3806-360BM-24C AB Two Phase Incremental optical shaft 6mm Rotary Encoder 360 Pulses lines](https://sdgteach.en.alibaba.com/product/60729529433-806678094/Optical_encoder_360_ppr_LPD3806_360BM_G5_24C_AB_Two_Phase_Incremental_optical_shaft_6mm_Rotary_Encoder_360_Pulses_lines.html)
C. | **Sprocket** <br/> <img src="https://www.mcmaster.com/mvB/Contents/gfx/ImageCache/679/6799K2p1-d03b-digitall@2x_636870476790198650.png" width="200"> | [ANSI 25 Chain, 10 Teeth, for 1/4" Shaft Diameter](https://www.mcmaster.com/6799k2)
D. | **Bearing** <br/> <img src="https://sc01.alicdn.com/kf/HTB191g3fJzJ8KJjSspkq6zF7VXaj/High-precision-zz809-abec-7-deep-groove.jpg" width="200"> | [zz809 abec 7 deep groove ball bearing](https://www.alibaba.com/product-detail/High-precision-zz809-abec-7-deep_60718249836.html?spm=a2700.7724857.main07.17.1bd252feC2zsEu)
E. | **Gear Bolt** <br/> <img src="https://mobileimages.lowes.com/product/converted/008236/008236638325.jpg?size=xl" width="200">|[ Hillman 5/16-in x 4-in Galvanized Coarse Thread](https://www.lowes.com/pd/Hillman-5-16-in-x-4-in-Coarse-Thread-Carriage-Bolt/1000381581)
F. | **Cage Bolt** <br/> <img src="https://www.mcmaster.com/mvB/Contents/gfx/ImageCache/917/91772A253p1-b01-digitall@2x_636619301374924024.png" width="200"> | [10-24 x 1/2" Machine Screws / Phillips](https://www.mcmaster.com/91772a253)
