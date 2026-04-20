#include <Servo.h>

Servo servos[5];
int flexPins[] = {A1, A2, A3, A4, A5};
int servoPins[] = {2, 3, 4, 11, 6}; 
float restVal[] = {351.0, 356.0, 348.0, 341.0, 314.0}; 
float bentVal[] = {343.0, 349.0, 343.0, 332.0, 301.0}; 

float currentAngle[5];
float smoothing = 0.05;

void setup() {
  analogReference(EXTERNAL); 
  Serial.begin(9600);
  
  for(int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  for(int i = 0; i < 5; i++) {
    int raw = analogRead(flexPins[i]);
    
    float targetAngle = map(raw, bentVal[i], restVal[i], 180, 0);
    targetAngle = constrain(targetAngle, 0, 180);
    currentAngle[i] = (targetAngle * smoothing) + (currentAngle[i] * (1.0 - smoothing));
    servos[i].write((int)currentAngle[i]);
  }
  delay(20);
}