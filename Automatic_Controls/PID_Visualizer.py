"""
PID script to visualize key values in control loop. One might have to change the sys.path.append value
(that’s the location where python packages are installed so imports work correctly) and the port to match whatever
port you put in for Serial.begin(port). The data is read from a comma separated string so order has to be respected
@author : David Gaitsgory - @dgaitsgo@student.42.fr
"""

import sys
sys.path.append("/usr/local/lib/python3.7/site-packages")
import serial
import matplotlib.pyplot as plt
import numpy as np

plt.ion()
fig = plt.figure()
port = '/dev/cu.usbmodem14201'
ser = serial.Serial(port, 9600, timeout = 5)
ser.close()
ser.open()

# ts -> time stamp
# current speed -> pv
# desired speed -> sp
# output -> op

timestamps = []
pvs = []
sps = []
ops = []

while True:

    data = ser.readline()
    data = data.decode()
    print(data)
    data = data.split(',')
    ts = float(data[0]) / 1000
    pv = float(data[1])
    sp = float(data[2])
    op = float(data[3])

    timestamps.append(ts)
    pvs.append(pv)
    sps.append(sp)
    ops.append(op)

    plt.plot(timestamps, pvs, color='red', linewidth=1, label='Process Variable (Current speed)')
    plt.plot(timestamps, sps, color='green', linewidth=1, label='Set Point (Target speed)')
    plt.plot(timestamps, ops, color='blue', linewidth = 1, label='Output (Adjustment speed')
    plt.show()
    plt.pause(0.0001)
