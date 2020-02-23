// four_74HC595_daisy_test
// four 74HC95 shift registers each controlling 8 leds
// leds blink in up and down spiral along the pyramid
// this one by Floris Wouterlood
// based on a script by stevenar
// public domain
// so use it freely and have fun
// June 27, 2018

  
  int datapin = 11;
  int latchpin = 8;
  int clockpin = 12;
  boolean registers[32];
  int delaytimer = 100;

void setup(){
   pinMode (datapin,OUTPUT);
   pinMode (latchpin,OUTPUT);
   pinMode (clockpin,OUTPUT);
   writereg();
}

void loop(){

   spiral_up();
   delay(500);
   spiral_down();
   delay(500);
      
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

   
// ==============  SPIRAL_UP ========================

void spiral_up (){

   for (int i=0; i<31; i++){  
      registers[(i)] = HIGH;
      writereg();
      delay(delaytimer);
      registers[(i)] = LOW;
      writereg();
      delay(delaytimer);
  }
}
  
// ==============  SPIRAL_DOWN =======================

void spiral_down (){
  
   for (int i = 31; i>=0; i--){   
      registers[(i)] = HIGH;
      delay(delaytimer);
      writereg();
      registers[(i)] = LOW;
      delay(delaytimer);
      writereg();     
   }
}



