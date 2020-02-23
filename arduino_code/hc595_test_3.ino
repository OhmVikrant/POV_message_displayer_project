//Pin connected to ST_CP of 74HC595
int latchPin = 8;

//Pin connected to SH_CP of 74HC595
int clockPin = 12;

//Pin connected to DS of 74HC595
int dataPin = 11;

// Number of digits attached
int const numberOfRegisters = 3;

// Numbers mapped on our seven segment display
byte one = 0b00010010;
byte two = 0b01100111;
byte three = 0b01110110;
byte four = 0b11010010;
byte five = 0b11110100;
byte six = 0b11110101;
byte seven = 0b00010110;
byte eight = 0b11110111;
byte nine = 0b11110110;
byte zero = 0b10110111;
byte test = 0b10000000;
byte empty = 0b00000000;
byte numbers[] = {zero,one,two,three,four,five,six,seven,eight,nine};

// Internal Vars
byte data;
byte dataBuffer[numberOfRegisters];

void setup() {
  // put your setup code here, to run once:
  
  addToBuffer(123);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void addToBuffer(int digit){
  // clear buffer
  memset(dataBuffer, 0, sizeof(dataBuffer));

  int c = 0;
  while( digit > 0 ){
    byte b = numbers[digit % 10]; // modulus 10 of our input
    dataBuffer[c] = b;
    digit /= 10;
    c++;
  }
  
  writeBuffer();
}

void writeBuffer(){
  digitalWrite(latchPin, 0);
  
  for (int a = sizeof(dataBuffer) - 1; a >= 0  ; a--) {
    shiftOut(dataPin, clockPin, dataBuffer[a]);
  }
  
  digitalWrite(latchPin, 1);
}


void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=0; i<=7; i++)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
digitalWrite(myClockPin, 0);
}
