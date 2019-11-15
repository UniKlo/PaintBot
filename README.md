# PaintBot

## Overview
Paintbot is a machine that paints upright surfaces. It's designed to extend to arbitrary lengths to accommodate walls of any size, indoors and outdoors alike. This document is a wiki for the robot's mechanics, electronics and code.

[Blog documentation (Notion.so)](https://www.notion.so/Paint-Bot-9628c4905eeb4714969bc28a3e177a94)

## Iterations
  * [V-Plotter](https://github.com/UniKlo/PaintBot/tree/master/Iterations/V-Plotter)
  
## Mechanics
  * [Motor Rack with Tensioner](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorRack)
  * [Centerpiece](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Centerpiece)
  * [Spray Gun Holder](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/SprayGunHolder)
  * [Motor Block](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/MotorBlock)
  * [Pulley System (Brackets)](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleySystem)
  * [Pillar](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/Pillar)
  * [Pulley Weights 15Kg](https://github.com/UniKlo/PaintBot/tree/master/Mechanics/PulleyWeights)

## Electronics
  - ### Wiring Schematics
    * [Circuits and Connections with Pictures](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Wiring)
  
  - ###  Parts Reference
    * [Spray Gun](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Parts/SprayGun)
    * [Arduino Mega 2560](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Parts/Arduino)
    * [H-Bridge](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Parts/H-Bridge)
    * [12v Power Supply](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Parts/PowerSupply)
    * [XY Motors](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Parts/XYMotors)
    * [Z-Axis Motor](https://github.com/UniKlo/PaintBot/tree/master/Electronics/Parts/Z-AxisMotor)

## DEMO_code

For good paint result, each spray layer should have 50% overlay <br/>
### Demo 11/12/2019 <br/>
[<img src="https://imgur.com/UIRjAdK.jpg" width="200">](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/7d0dce7c-0327-4c29-8f80-19949124757a/A6B893AF-5B91-4EBE-B7AC-E00EC5459D5E.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=ASIAT73L2G45DBMCXPO5%2F20191115%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20191115T200821Z&X-Amz-Expires=86400&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEDwaCXVzLXdlc3QtMiJGMEQCIEaLvJ%2FOjXHkfg9mhRX4ueAn69jCKhThtkOdvCpvW1%2FWAiAQxvSDeZCQUqcxG2ZmEQOxBxFh7ryqjhEGLUN7NYWYOirSAghlEAAaDDI3NDU2NzE0OTM3MCIMceDnkVEkDF9NeedvKq8CvTUS6iAMqofI6eFMe%2FGr2kDZ6DEaeD57btWXB4%2BjFH40VbonR2gsKwzQ904sBp1NUKCfa354tOciLQFzcJoJYgfaF99RSGDH2Zr3T75uc2%2F3kOednZHdPZtkN41bvy5KuZH6N5vw8WT1MpLKC%2B2t7vuF39Q1gK%2FhcdXy4zhIyyUUx%2FvO2WsupHlAdAOqEj84PrN2WCXeojMDEo%2Fm6RRVnfUUc0Evxy35%2BtwtAFWdoR%2FsCDRjNlSqO%2BUviQCbmqIE4tyOLTkZlwdQz7tU%2FMJQ7t7D1qKEFcwsWSlgTghZg1Akag514S1y2ND0AUljcs0lnnOOzX7XxnbijcgOve5GGVL%2FwB7fhKpo8WeA%2BfdJ11rRM9VC2fI%2FB%2F2t2x7CuXpmaKDPMltg801bTy0X9tr5MJ%2BEvO4FOs4C4evUfmXvmzotW681HPhEgHKIyEaOPoAS8DLjkslfFiO9i5ZcMO3nGPFxShJoAu6NS2GQKfGNzUXpm7w4U4zGA712A8%2BRNLbhmm2z%2Bpo8wWZLT%2FsR2DbhZNSQ46axeYQ5kMDBDiio6%2Fi5mrAh5%2B0g0S1w0Zz39aA91z0a8ujWITA07sJcErQ3pO%2BBXAwP%2B%2FglNVq%2FQFu0ufF6fD%2BsxJyQg3jxWL5LdRZzIE9tmWVkNNP9u8OHccGd5qrowCK9miD%2BZzgkw2cSwRfpqWC0cwNkAHheISTnn8tV20fv6vlRhiBh77%2F6cuR2p%2FpgoQmtlYUqfdsF668PDr%2FjwdE3%2FgCch5a0SpXpUuvZL6XgdSuS%2F6XVHZ3tbgvcjm%2FxfRFbTNM0Lr67Td6GHKb1kpAG5%2FDgkikF4B%2B%2BdsFzsH8DKMNRdcIYCw5%2BTJETkFfEID%2FwpQ%3D%3D&X-Amz-Signature=b6f62035a80d82c78fff5caff5c8b72676dcd71e71a5f25b5f62878464285633&X-Amz-SignedHeaders=host)<br/>
[Code](https://github.com/UniKlo/PaintBot/tree/master/DEMO_code) used encoders output to control the paintbot spraying 3 ft x 3 ft on the wall

### [Automatic Controls - (unfinished)](https://github.com/CaseySingleton/RoboLabPaintBotMotorController)
