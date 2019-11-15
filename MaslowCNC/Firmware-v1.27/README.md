# PaintBot

In order to by pass the calibration, we added a few function under MaslowCNC/Firmware-v1.27/cnc_ctrl_v1/GCode.cpp.

    if(gcodeLine.substring(0, 6) == "B42 ON"){ //press on Z, pls // to handle
        singleAxisMove(&zAxis, zAxis.read() - 0.9, 800);
        return STATUS_OK;
    }
    if(gcodeLine.substring(0, 7) == "B42 OFF"){ //release on Z
        singleAxisMove(&zAxis, zAxis.read() + 0.9, 800);
        return STATUS_OK;