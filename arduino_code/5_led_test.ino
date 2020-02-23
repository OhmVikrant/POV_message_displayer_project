int ledPins[] ={2,3,4,5,6};

void setup()
{
  for(int i = 0; i < 5; i++)
  {
    pinMode(ledPins[i],OUTPUT);
  
  }
}

void loop()
{
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(ledPins[i], HIGH);   // Turn on the LED
    delay(1000);              // Wait for one second
    digitalWrite(ledPins[i], LOW);    // Turn off the LED
    delay(1000);              //Wait one second
   }
            
}
