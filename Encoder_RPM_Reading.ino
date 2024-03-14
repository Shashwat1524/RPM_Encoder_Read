#include <Encoder.h>

Encoder myEnc(22, 21);
volatile int32_t lastEncoderValue = 0; 
int32_t CPR = 3172;
IntervalTimer speedTimer;
float rpm=0;


void setup() {
  Serial.begin(115200);
  speedTimer.begin(calculateRPM, 100000); //0.1s
}

void loop() {
    
  Serial.printf("RPM: %f \n", rpm);

}

void calculateRPM() {
  int32_t encoderValue = myEnc.read();
  int32_t deltaEncoder = encoderValue - lastEncoderValue;
  lastEncoderValue = encoderValue;
  rpm = (float(deltaEncoder) / CPR) * (60.0 / 0.1); 

}

