int SENSOR_PIN = 0; // center pin of the potentiometer
int SENSOR_PIN1 = 1; // center pin of the potentiometer
int RPWM_Output = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
int RPWM_Output1 = 9; // Arduino PWM output pin 9; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output1 = 10; // Arduino PWM output pin 10; connect to IBT-2 pin 2 (LPWM)
int pre_diff = 0;
int pre_diff1 = 0;
void setup() {
Serial.begin(9600);

}

void loop() {
    // sensor value is in the range 0 to 1023, mid is 512
    // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    int stepSpeed = 2;
    int sensorValue = analogRead(SENSOR_PIN);
    int diff = (sensorValue - 512) / 2;
//    if (pre_diff + stepSpeed < diff || pre_diff - stepSpeed > diff)
//    {
//      Serial.print("diff: ");
//      Serial.print(diff);
//      Serial.print(" Pre_diff: ");
//      Serial.println(pre_diff);
//    }
    if (diff == pre_diff && (diff > 10 || diff < -10))
    {
      Serial.print("diff: ");
      Serial.println(diff);
      if (diff > 0)
      {
        analogWrite(LPWM_Output, diff);
        analogWrite(RPWM_Output, 0);
        Serial.println("Move forward");
      }
      else
      {
        if (diff < -255)
          diff = -255;
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, -diff);
        Serial.println("Reverse");
      }
    }
    
    while(pre_diff + stepSpeed < diff)
    {
      if (pre_diff > 0)
      {
        analogWrite(LPWM_Output, pre_diff);
        analogWrite(RPWM_Output, 0);
        Serial.print("Move forward: ");
      }
      else
      {
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, -pre_diff);
        Serial.print("Reverse: ");
      }
      pre_diff += stepSpeed;
      Serial.println(pre_diff);
    }
    
    while(pre_diff - stepSpeed > diff)
    {
      if (pre_diff > 0)
      {
        analogWrite(LPWM_Output, pre_diff);
        analogWrite(RPWM_Output, 0);
        Serial.print("move forward: ");
      }
      else
      {
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, -pre_diff);
        Serial.print("reverse: ");

      }
      Serial.println(pre_diff);
    
      pre_diff -= stepSpeed;

    }
    pre_diff = diff;
    //another motor
    int sensorValue1 = analogRead(SENSOR_PIN1);
    int diff1 = (sensorValue1 - 512) / 2;

    if (diff1 == pre_diff1 && (diff1 > 10 || diff1 < -10))
    {
      Serial.print("diff1: ");
      Serial.println(diff1);
      if (diff1 > 0)
      {
        analogWrite(LPWM_Output, diff1);
        analogWrite(RPWM_Output, 0);
        Serial.println("Move forward");
      }
      else
      {
        if (diff1 < -255)
          diff1 = -255;
        analogWrite(LPWM_Output1, 0);
        analogWrite(RPWM_Output1, -diff1);
        Serial.println("Reverse");
      }
    }
    
    while(pre_diff1 + stepSpeed < diff1)
    {
      if (pre_diff1 > 0)
      {
        analogWrite(LPWM_Output1, pre_diff1);
        analogWrite(RPWM_Output1, 0);
        Serial.print("Move forward: ");
      }
      else
      {
        analogWrite(LPWM_Output1, 0);
        analogWrite(RPWM_Output1, -pre_diff1);
        Serial.print("Reverse: ");
      }
      pre_diff1 += stepSpeed;
      Serial.println(pre_diff1);
    }
    
    while(pre_diff1 - stepSpeed > diff1)
    {
      if (pre_diff1 > 0)
      {
        analogWrite(LPWM_Output1, pre_diff1);
        analogWrite(RPWM_Output1, 0);
        Serial.print("move forward: ");
      }
      else
      {
        analogWrite(LPWM_Output1, 0);
        analogWrite(RPWM_Output1, -pre_diff1);
        Serial.print("reverse: ");

      }
      Serial.println(pre_diff1);
    
      pre_diff1 -= stepSpeed;

    }
    pre_diff1 = diff1;
}
