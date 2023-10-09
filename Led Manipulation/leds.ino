int redPin = 11;                // output pin number to Red pin of the LED
int greenPin = 10;              // output pin number to Green pin
int bluePin = 9;                // output pin number to Blue pin

void setup()                    // this runs once, when the sketch starts
{
 pinMode(redPin, OUTPUT);      // sets the pin as output pin
 pinMode(greenPin, OUTPUT);    // sets the pin as output pin
 pinMode(bluePin, OUTPUT);     // sets the pin as output pin
}
void loop()                     // this runs over and over again forever
{
 int value = 0;
 for (int i = 0; i < 255; i++)
 {
   analogWrite(bluePin, i); // Outputs analog value i on redPin using PWM.
                           // value range: 0 ~ 255 (0: off, 255: fully on)
   delay(10); // waits 10 ms
 }
  for (int i = 0; i < 255; i++)
 {
   analogWrite(bluePin, 255-i); // Outputs analog value i on redPin using PWM.
                           // value range: 0 ~ 255 (0: off, 255: fully on)
   analogWrite(redPin, i);
   delay(10); // waits 10 ms
 }
   for (int i = 0; i < 255; i++)
 {
   analogWrite(redPin, 255-i); // Outputs analog value i on redPin using PWM.
                           // value range: 0 ~ 255 (0: off, 255: fully on)
   analogWrite(greenPin, i);
   delay(10); // waits 10 ms
 }
  for (int i = 0; i < 255; i++)
 {
   analogWrite(greenPin, 255-i); // Outputs analog value i on redPin using PWM.
                           // value range: 0 ~ 255 (0: off, 255: fully on)
   delay(10); // waits 10 ms
   digitalWrite(greenPin, LOW);
 }
}
