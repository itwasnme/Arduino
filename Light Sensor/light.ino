int ledPin = 9;    // output to LED. Use any PWM-enabled pin (marked ~)
int sensorPin = A0;   // voltage input. Use any ADC pin (starts with A)
int sensorValue = 0;  // stores value from ADC
int on = 0;

void setup()      
{
   Serial.begin(115200);    // Opens serial port, Baud Rate 115200 bps
   pinMode(ledPin, OUTPUT);    
   
}

void loop()    
{


  
   int sensorValue = analogRead (sensorPin);   // reads the sensor

                                                // returns 0-1023  
   int minValue = 800;     // sensor value you consider to be minimum
   int maxValue = 1023;    // sensor value you consider to be maximum

   int constrainedValue = constrain(sensorValue, minValue, maxValue);

                            // clips values < minValue or > maxvalue
   int lightValue = map (constrainedValue, minValue, maxValue, 0, 255);

                            // remaps the value to new range (0-255)
   //analogWrite(ledPin, lightValue);    
   Serial.println(lightValue);   // Prints the value via the serial port


   if(sensorValue>800){
    if(on == 0){
      on = 1;
      digitalWrite(ledPin, HIGH);
    }else{
      on = 0;
      digitalWrite(ledPin, LOW);
    }
   } 

    delay(20);    
}  
