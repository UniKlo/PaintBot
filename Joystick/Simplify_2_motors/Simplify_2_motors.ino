#define l_motor 0 //Left motor analog in -- pin 0
#define r_motor 1  //right motor analog in -- pin 1
#define l_cw_output 5 // Arduino PWM output pin 5; connect to IBT-2 pin 1 (left motor RPWM)
#define l_ccw_output 6 // Arduino PWM output pin 6; connect to IBT-2 pin 2 (left motor LPWM)
#define r_cw_output 9 // Arduino PWM output pin 9; connect to IBT-2 pin 1 (right motor RPWM)
#define r_ccw_output 10 // Arduino PWM output pin 10; connect to IBT-2 pin 2 (right motor LPWM)

int pre_sv = 0; //previous sensor value for motor l;
int pre_sv1 = 0;
int stepSpeed = 5;
int pofmax = 1; //percentage to max speed

int cw_l = 0;
int ccw_l = 0;
int cw_r = 0;
int ccw_r = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
    // sensor value is in the range 0 to 1023, mid is 512
    // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    int sensorValue = analogRead(l_motor);
    int c_sv = (sensorValue - 512) / 2 * pofmax; //current sensor value
    if ((0< c_sv && c_sv < 10) || (0 > c_sv && c_sv>-10))
      c_sv = 0;
    if (c_sv > 240)
      c_sv = 255;
    if (c_sv <-240)
      c_sv = -255;
    if (c_sv > pre_sv)
      pre_sv = pre_sv + stepSpeed;
    else if (c_sv < pre_sv)
      pre_sv = pre_sv - stepSpeed;


    if(pre_sv > 0)
    {
      cw_l = pre_sv;
      ccw_l = 0;
    }
    else if (pre_sv < 0)
    {
      cw_l = 0;
      ccw_l = -pre_sv;
    }
    else
    {
      cw_l = 0;
      ccw_l = 0;
    }
    if (cw_l != 0 || ccw_l != 0)
    {
      Serial.print("current sensor L: ");
      Serial.print(c_sv);    
      Serial.print(" l_cw: ");
      Serial.print(cw_l);
      Serial.print(" l_ccw: ");
      Serial.println(ccw_l);
    }
    analogWrite(l_cw_output, cw_l);
    analogWrite(l_ccw_output, ccw_l);

    int sensorValue1 = analogRead(r_motor);
    int c_sv1 = (sensorValue1 - 512) / 2 * pofmax; //current sensor value
    if ((0 < c_sv1 && c_sv1 < 10) || (0 > c_sv1 && c_sv1 > -10))
      c_sv1 = 0;
    if (c_sv1 > 240)
      c_sv1 = 255;
    if (c_sv1 <-240)
      c_sv1 = -255;
    if (c_sv1 > pre_sv1)
      pre_sv1 = pre_sv1 + stepSpeed;
    else if (c_sv1 < pre_sv1)
      pre_sv1 = pre_sv1 - stepSpeed;
      

    if(pre_sv1 > 0)
    {
      cw_r = pre_sv1;
      ccw_r = 0;
    }
    else if (pre_sv1 < 0)
    {
      cw_r = 0;
      ccw_r = -pre_sv1;
    }
    else
    {
      cw_r = 0;
      ccw_r = 0;
    }
    if (cw_r != 0 || ccw_r != 0)
    {
      Serial.print("current sensor R: ");
      Serial.print(c_sv1);    
      Serial.print(" r_cw: ");
      Serial.print(cw_r);
      Serial.print(" r_ccw: ");
      Serial.println(ccw_r);
    }
    analogWrite(r_cw_output, cw_r);
    analogWrite(r_ccw_output, ccw_r);

}
