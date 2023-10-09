#include "ICM_20948.h"

ICM_20948_I2C myICM; // IMU Object

const int numItems = 100;    // number of samples to average
float accX[numItems];       // array to store samples
int idx = 0;                // index to store a sample to the array
int ledPin = 9;

void setup() {
 pinMode(ledPin, OUTPUT);
 Serial.begin(115200);
 Wire.begin();
 Wire.setClock(400000);
 myICM.begin( Wire, 1);
}

void loop() {
 if ( myICM.dataReady() ) {
   myICM.getAGMT();              

   float ax = myICM.accX();

   if (idx < numItems - 1)
     idx ++;
   else
     idx = 0;

   accX[idx] = ax;       // add the sensor reading to the array

   float xSum = 0;
   for (int i = 0; i < numItems; i++)   // calculate the sum
   {
     xSum += accX[i];
   }
   float xAvg = xSum/numItems;   // calculate the average

   Serial.print(ax);      // raw acceleration
   Serial.print(", ");
   Serial.println(xAvg);  // filtered acceleration

   int minValue = -800;
   int maxValue = 800;

   int constrainedValue = constrain(xAvg, minValue, maxValue);
   int lightValue = map(constrainedValue, minValue, maxValue, 0, 255);

   if (xAvg > -30 && xAvg < 30){
    digitalWrite(ledPin, HIGH);
   }
   else if (xAvg < -850 || xAvg > 700){
    digitalWrite(ledPin, LOW); 
   }
   else{
    if (xAvg > 0){
      analogWrite(ledPin, 255-lightValue);
    }else if (xAvg < 0){
      analogWrite(ledPin, lightValue);
    }
   }
 }
   delay(10);
}
