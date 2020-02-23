// blink_32_led_test
// four 74HC95 shift registers each controlling 8 leds
// all leds on pyramid blink simultaneously
// by Floris Wouterlood
// public domain
// so use it freely and have fun
// June 27, 2018


int datapin = 11;   
int latchpin = 8;  
int clockpin = 12;
                  
#define n_pins 32                           // declare the total number of 74HC595 pins here
boolean registers [n_pins];             
  

void setup(){
       
  pinMode (datapin, OUTPUT); 
  pinMode (latchpin, OUTPUT); 
  pinMode (clockpin, OUTPUT); 

  clearRegisters();                         // reset all register pins
  writeRegisters();
}               


void loop(){

   for (int i=0; i<n_pins; i++){  
      setRegisterPin(i, HIGH);
   }
   
   writeRegisters();
   delay(500);
   clearRegisters();
   delay(500);

}

// ====================== subroutines ====================================

void clearRegisters(){                      // set all register pins to LOW

   for(int i = (n_pins-1); i >=  0; i--){ 
       registers[i] = LOW;
   }
   writeRegisters();
} 


void writeRegisters(){                      // set and display registers

   digitalWrite(latchpin, LOW);
   for(int i = (n_pins-1); i >=  0; i--){
       digitalWrite(clockpin, LOW);
       int val = registers[i];
       digitalWrite(datapin, val);
       digitalWrite(clockpin, HIGH);
  }

  digitalWrite(latchpin, HIGH);
}


void setRegisterPin(int index, int value){  // set an individual pin HIGH or LOW

  registers[index] = value;
}

