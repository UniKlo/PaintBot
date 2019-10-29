
#define SWITCH 2 //  Arduino PWM output pin 2; 
#define F_Output 7 // Arduino PWM output pin 7; connect to IBT-2 pin 1 (RPWM)
#define B_Output 8 // Arduino PWM output pin 8; connect to IBT-2 pin 2 (LPWM)

int mf = 0;
int mb = 0;
int sw = 0;

int pre_sw = 0;
int distance = 1000;
unsigned long c_time;
unsigned long s_time;

void setup() {
  pinMode(SWITCH, INPUT);
  digitalWrite(SWITCH, HIGH);
  Serial.begin(9600);

}

void loop() {   
    int turn = digitalRead(SWITCH); //turn is normally 1
    c_time = millis();
//    Serial.print("c_time: ");
//    Serial.print(c_time);
//    Serial.print(" s_time: ");
//    Serial.println(s_time);
    if (turn == 0 && sw == 0) //sw is pressed
    {
      Serial.print(" pressed? ");
      Serial.print(turn);
      Serial.print(" pre_sw: ");
      Serial.println(pre_sw);
      s_time = millis();
      if (pre_sw == 0)
      {
          sw = 1;
          mf = 255;
          mb = 0; 
          Serial.println("Turn on");
      }
      else if (pre_sw == 1)
      {
          sw = -1;
          mf = 0;
          mb = 255;
          Serial.println("Turn off");
      }       
      else
        pre_sw = 0;
      delay(150);
    }

    analogWrite(F_Output, mf);
    analogWrite(B_Output, mb);

    if (c_time - s_time > distance && sw != 0)
    {
      pre_sw = sw;
      mf = 0;
      mb = 0;
      sw = 0;
    }
}
