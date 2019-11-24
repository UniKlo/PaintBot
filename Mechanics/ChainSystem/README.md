# Chain System

The goal of the centerpiece is to be able to move to any edge of the painting frame while constrained at each corner by tensioned chains. Via pulleys, the chain system allows that to happen by creating a pulling force via weights and by shortening the chain.

<img src="https://github.com/UniKlo/PaintBot/blob/master/Mechanics/ChainSystem/chain-system-02-01.png" width="400">

1. Double Bearing Pulley that guides the chains through the Motor Rack.
2. 10 teeth #25 sprocket, connected to bolt, that drives the motion of the chains by using the torque translated from the motor inside the [Motor Rack](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorRack).
3. Double Bearing that guides the chains to the Wooden Bracket and to the Centerpiece
4. Connection to Top Corner of Centerpiece
5. Weight holder connects to [Pulley Weight](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleyWeights) to add tension to the system.
6. Single bearing attached to bottom of the pillar, encased in [Wooden Bracket](https://github.com/UniKlo/PaintBot/blob/master/Mechanics/Wooden%20Bracket).
7. Connection to Bottom Corner of Centerpiece

## Design considerations

* Develop a chain system that keeps the centerpiece stable during operation
  * Centerpiece held in place from the tension of two equal weights on opposite sides
  * The tension in the chains stables and prevents the Centerpiece from vibrating violently during spraying
* Increase efficency and safety during operations
  * Increasing mechanical advantage by using 1:4 Pulley System: Refer to diagram below.
  * Limit the range of distance the Pulley Weight travels while increase operating range of centerpiece 
    * Limiting the distance the Pulley Weight travels reduces the likelihood it colliding with people underneath
    * Increasing operating range of centerpiece is practical in achieving more paint coverage

![Pulley Systems](https://user-images.githubusercontent.com/49771001/69490092-82e11280-0e37-11ea-8bda-d5d2c92d5691.png)

## Parts
| Part | Description |
| :--: | :-- |
**ANSI #25 Roller Chain** <br/> <img width="100" alt="25 ANSi Chain" src="https://user-images.githubusercontent.com/49771001/69489463-d26e1100-0e2c-11ea-9208-3ee7e888c19d.png"> | - ANSI Chain No. 25 used to connect the pulley systems <br/> - 140 lbs is the rated working load of the chain <br/> - [Specifications](https://www.renoldjeffrey.com/media/2395574/ansi-standard-roller-chain-renold-jeffrey.pdf)


## Photos
| &nbsp; | &nbsp; | &nbsp; |
|:-:|:-:|:-:|
**Chain by centerpiece** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/Mechanics/ChainSystem/Image%20from%20iOS.jpg" width="400"> | **Chain by Wooden Bracket** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/Mechanics/ChainSystem/Image%20from%20iOS%20(2).jpg" width="400"> | **Chain by Motor Rack(In)** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/Mechanics/ChainSystem/Image%20from%20iOS%20(3).jpg" width="400">
**Chain by Motor Rack(Out)** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/Mechanics/ChainSystem/Image%20from%20iOS%20(5).jpg" width="400"> | **Chain above Pulley Weight** <br/> <img src="https://github.com/UniKlo/PaintBot/blob/master/Mechanics/ChainSystem/Image%20from%20iOS%20(4).jpg" width="400">
