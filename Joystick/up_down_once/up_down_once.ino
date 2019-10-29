int SENSOR_PIN = 0; // center pin of the potentiometer
int SENSOR_PIN1 = 1; // center pin of the potentiometer
int RPWM_Output = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
int RPWM_Output1 = 9; // Arduino PWM output pin 9; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output1 = 10; // Arduino PWM output pin 10; connect to IBT-2 pin 2 (LPWM)
int pre_diff = 0;
int pre_diff1 = 0;

#define SWITCH 2 //  Arduino PWM output pin 2; 
#define F_Output 7 // Arduino PWM output pin 7; connect to IBT-2 pin 1 (RPWM)
#define B_Output 8 // Arduino PWM output pin 8; connect to IBT-2 pin 2 (LPWM)

int mf = 0;
int mb = 0;
int sw = 0;

int pre_sw = 0;
int distance = 800;
int delta = 0;
unsigned long c_time;
unsigned long s_time;

void setup() {
    pinMode(SWITCH, INPUT);
    digitalWrite(SWITCH, HIGH);
    Serial.begin(9600);

}

void loop() {
    //spray
    int turn = digitalRead(SWITCH); //turn is normally 1

    if (turn == 0 && sw == 0) //sw is pressed
    {
        Serial.print(" pre_sw: ");
        Serial.println(pre_sw);

        if (pre_sw == 0) {
            sw = 1;
            mf = 255;
            mb = 0;
            Serial.print("Turn on");
        } else if (pre_sw == 1) {
            sw = -1;
            mf = 0;
            mb = 255;
            Serial.println("Turn off");
        } else
            pre_sw = 0;
        delay(150);
        //     delta = c_time - s_time;
        delta = 0;
        s_time = millis();
        while (delta < distance && sw != 0) {
            analogWrite(F_Output, mf);
            analogWrite(B_Output, mb);
            c_time = millis();

            delta = c_time - s_time;
            //      Serial.print("Detla");
            Serial.println(delta);
        }
    }
    if (sw != 0) {
        pre_sw = sw;
        mf = 0;
        mb = 0;
        sw = 0;
    }
    analogWrite(F_Output, mf);
    analogWrite(B_Output, mb);

    //moving up & down
    int stepSpeed = 2;
    int sensorValue = analogRead(SENSOR_PIN);
    int diff = (sensorValue - 512) / 2;

    if (diff == pre_diff && (diff > 10 || diff < -10)) {
        Serial.print("diff: ");
        Serial.println(diff);
        if (diff > 0) {
            analogWrite(LPWM_Output, diff);
            analogWrite(RPWM_Output, 0);
            analogWrite(LPWM_Output1, diff);
            analogWrite(RPWM_Output1, 0);
            Serial.println("Move forward");
        } else {
            if (diff < -255)
                diff = -255;
            analogWrite(LPWM_Output, 0);
            analogWrite(RPWM_Output, -diff);
            analogWrite(LPWM_Output1, 0);
            analogWrite(RPWM_Output1, -diff);
            Serial.println("Reverse");
        }
    }

    while (pre_diff + stepSpeed < diff) {
        if (pre_diff > 0) {
            analogWrite(LPWM_Output, pre_diff);
            analogWrite(RPWM_Output, 0);
            analogWrite(LPWM_Output1, pre_diff);
            analogWrite(RPWM_Output1, 0);
            Serial.print("Move forward: ");
        } else {
            analogWrite(LPWM_Output, 0);
            analogWrite(RPWM_Output, -pre_diff);
            analogWrite(LPWM_Output1, 0);
            analogWrite(RPWM_Output1, -pre_diff);
            Serial.print("Reverse: ");
        }
        pre_diff += stepSpeed;
        Serial.println(pre_diff);
    }

    while (pre_diff - stepSpeed > diff) {
        if (pre_diff > 0) {
            analogWrite(LPWM_Output, pre_diff);
            analogWrite(RPWM_Output, 0);
            analogWrite(LPWM_Output1, pre_diff);
            analogWrite(RPWM_Output1, 0);
            Serial.print("move forward: ");
        } else {
            analogWrite(LPWM_Output, 0);
            analogWrite(RPWM_Output, -pre_diff);
            analogWrite(LPWM_Output1, 0);
            analogWrite(RPWM_Output1, -pre_diff);
            Serial.print("reverse: ");

        }
        Serial.println(pre_diff);

        pre_diff -= stepSpeed;

    }
    pre_diff = diff;

}
