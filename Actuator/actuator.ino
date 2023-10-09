#include <Servo.h>

#include "ICM_20948.h"

ICM_20948_I2C myICM;

Servo myservo;  
int angle = 0;


void setup() {
 Serial.begin(115200);
 Wire.begin();
 Wire.setClock(400000);
 myICM.begin(Wire, 1);
 myservo.attach(9);
}

void loop() {

  // Getting IMU data
 if ( myICM.dataReady() ) {
   myICM.getAGMT();              
   float ax = myICM.accX();
   Serial.println(ax);
   ax = map (ax, -1100, 1100, 180, 0) ;
   myservo.write(ax);
   delay(1000);
 }
}
