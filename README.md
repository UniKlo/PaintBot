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
[<img src="https://imgur.com/UIRjAdK.jpg" width="200">](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/7d0dce7c-0327-4c29-8f80-19949124757a/A6B893AF-5B91-4EBE-B7AC-E00EC5459D5E.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=ASIAT73L2G45CFZBT5XP%2F20191115%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20191115T082712Z&X-Amz-Expires=86400&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEDAaCXVzLXdlc3QtMiJGMEQCIAUO7B%2B5k17YGmQs1PXu%2BkSPHHJxscoJCVqCYNmg5vyaAiAd9%2B4hUmrIms3INPAjYfIx1CZvNfKom%2BQYh3wdzwF31irRAghZEAAaDDI3NDU2NzE0OTM3MCIM%2B8fQlbSrENvdzQesKq4CU5k1G%2FL%2FBnqNh6bNl2BidvJr4t6VtqUPoQrEuaSDCxDOtIRGV2Tinavso05p84wu78VNNPFE98byosxCIZ%2FFh3y%2BsBW3WCc39rOhWgox5HACxyZF2opOkwe8mxPhTMtiOxFi2PNhofNqMXaVsT0WLj01ag7YY0i2NfPUicUyGyAdWLK3zoty%2BOwg7u2aH9jFu9ITm96Gj1ivigHycevdvP70Iyb%2Fwx3hTVjpvv%2BGsZdUL25BgZBgaKIrD%2FGSshHl6DCFN%2F0qSIcxY4bX0GZLJCS9T4vYf29xovZkyclDXoetBDcA%2Ftaar2dxJEq4qwF35XZJ01c5rwgtDKq9LMQQ8SJqUQENCtEHvi%2BgiVrwu8gFtOVkm9xR4E1oSlmLUaFGCHZP8PhxDSBjBdl%2F5hkwj7O57gU6zwJPRRSXc0t3XNzGKtIhUWtL%2BIigonfDcSIut%2F5KoLnBMi2LCVm2OY5YYpyq2ZnJY0IdBbp72bHmGWh2t2eB1F7dV68txRdhtia5mwYqWXujsCvmLiLI3Fukam5i9HdcSnsZZGXp3OClDx0MLQv1uA3UY3QmqqEUlzLKSEos8E2Br33QInjn2gi5ciJqAdmVI9RiUQjSqtPUttlq%2Fpev4nS5%2FNY5IjLX9jjF0FbIhWU%2F0b%2BX5MW5Vl3rX9C8u72i75%2BF52OTYpDuLWo4%2BjFlOxLw9kpxxtxePI65zF6oBGlWmJL0mM%2BoCnwpbFt%2FBo5BD18lNlxNeBRGbGxTjvPFpykGldnPROfL550Aw9WTl61oa7sFszrFHqm2PxM%2BI8%2B4VRiyKIF4iFYtFaUPVr6vCBK9qsc3K3vfl3tlpWD%2BINBk227ceGELarSZ%2B9m5uMG6ug%3D%3D&X-Amz-Signature=e8210ff572d41ac41e3a4d45dd7b0e9ea9be742d2cf8a51b6ef6d667bda4f8f6&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22A6B893AF-5B91-4EBE-B7AC-E00EC5459D5E.mp4%22 "Paint Bot")<br/>
[Code](https://github.com/UniKlo/PaintBot/tree/master/DEMO_code) used encoders output to control the paintbot spraying 3 ft x 3 ft on the wall

### [Automatic Controls - (unfinished)](https://github.com/CaseySingleton/RoboLabPaintBotMotorController)
