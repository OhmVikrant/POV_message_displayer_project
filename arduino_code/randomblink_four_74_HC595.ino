// randomblink_nn
// four 74HC95 shift registers each controlling 8 leds
// leds blink in random fashion
// by Floris Wouterlood
//
// public domain
// so use it freely and have fun
// June 27, 2018

  
  int datapin = 11;
  int latchpin = 8;
  int clockpin = 12;
  boolean registers[32];
  int delaytimer = 100;
  long randNumber;
  int randompin; 

void setup(){

   pinMode (datapin,OUTPUT);
   pinMode (latchpin,OUTPUT);  
   pinMode (clockpin,OUTPUT);
   writereg();
   randomSeed (analogRead(0));  
} 

void loop(){

   randompin = random (1, 32);  
   do_the_random ();
 
}
    
// ==============  subroutines =====================

void writereg(){
  
   digitalWrite(latchpin, LOW);
   for (int i = 31; i>=0; i--){  
       digitalWrite(clockpin, LOW);
       digitalWrite(datapin, registers[i] );
       digitalWrite(clockpin, HIGH);
   } 
   digitalWrite(latchpin, HIGH);
}

void do_the_random (){

      registers[(randompin)] = HIGH;
      delay(delaytimer);
      writereg();
      registers[(randompin)] = LOW;
      delay(delaytimer);
      writereg();     
}


