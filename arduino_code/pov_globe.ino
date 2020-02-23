//**************************************************************//
//  Name    : shiftOutCode, Predefined Dual Array Style         //
//  Author  : Carlyn Maw, Tom Igoe                              //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
// 
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

//holders for infromation you're going to pass to shifting function
byte dataRED;
byte dataGREEN;
byte dataBLUE;
byte dataArrayRED[70];
byte dataArrayGREEN[70];
byte dataArrayBLUE[70];

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);

  //Arduino doesn't seem to have a way to write binary straight into the code 
  //so these values are in HEX.  Decimal would have been fine, too. 
dataArrayBLUE[0]=0x0;
dataArrayBLUE[1]=0x14;
dataArrayBLUE[2]=0x1E;
dataArrayBLUE[3]=0x1C;
dataArrayBLUE[4]=0x1E;
dataArrayBLUE[5]=0xF;
dataArrayBLUE[6]=0x1F;
dataArrayBLUE[7]=0x1F;
dataArrayBLUE[8]=0x1F;
dataArrayBLUE[9]=0xF;
dataArrayBLUE[10]=0x7;
dataArrayBLUE[11]=0xF;
dataArrayBLUE[12]=0xF;
dataArrayBLUE[13]=0xF;
dataArrayBLUE[14]=0x7;
dataArrayBLUE[15]=0x3;
dataArrayBLUE[16]=0x7;
dataArrayBLUE[17]=0xC;
dataArrayBLUE[18]=0x1C;
dataArrayBLUE[19]=0x18;
dataArrayBLUE[20]=0xC0;
dataArrayBLUE[21]=0xC0;
dataArrayBLUE[22]=0xF0;
dataArrayBLUE[23]=0xF0;
dataArrayBLUE[24]=0x60;
dataArrayBLUE[25]=0xC0;
dataArrayBLUE[26]=0x0;
dataArrayBLUE[27]=0x0;
dataArrayBLUE[28]=0x0;
dataArrayBLUE[29]=0x2;
dataArrayBLUE[30]=0x6;
dataArrayBLUE[31]=0x1C;
dataArrayBLUE[32]=0x9;
dataArrayBLUE[33]=0x3;
dataArrayBLUE[34]=0x77;
dataArrayBLUE[35]=0xEE;
dataArrayBLUE[36]=0xEF;
dataArrayBLUE[37]=0x5E;
dataArrayBLUE[38]=0x3F;
dataArrayBLUE[39]=0x3F;
dataArrayBLUE[40]=0x3F;
dataArrayBLUE[41]=0x7F;
dataArrayBLUE[42]=0x7F;
dataArrayBLUE[43]=0xFF;
dataArrayBLUE[44]=0x7F;
dataArrayBLUE[45]=0x3F;
dataArrayBLUE[46]=0xFF;
dataArrayBLUE[47]=0xFF;
dataArrayBLUE[48]=0xFF;
dataArrayBLUE[49]=0xFF;
dataArrayBLUE[50]=0xBF;
dataArrayBLUE[51]=0x7F;
dataArrayBLUE[52]=0x7F;
dataArrayBLUE[53]=0x7F;
dataArrayBLUE[54]=0xFF;
dataArrayBLUE[55]=0xFF;
dataArrayBLUE[56]=0xFF;
dataArrayBLUE[57]=0xFF;
dataArrayBLUE[58]=0xFF;
dataArrayBLUE[59]=0x7F;
dataArrayBLUE[60]=0x7F;
dataArrayBLUE[61]=0x7F;
dataArrayBLUE[62]=0x3F;
dataArrayBLUE[63]=0x7F;
dataArrayBLUE[64]=0x7F;
dataArrayBLUE[65]=0x7B;
dataArrayBLUE[66]=0x70;
dataArrayBLUE[67]=0x78;
dataArrayBLUE[68]=0x30;
dataArrayBLUE[69]=0x0;
dataArrayRED[0]=0x0;
dataArrayRED[1]=0x0;
dataArrayRED[2]=0x0;
dataArrayRED[3]=0x0;
dataArrayRED[4]=0x0;
dataArrayRED[5]=0xC0;
dataArrayRED[6]=0xF8;
dataArrayRED[7]=0xF4;
dataArrayRED[8]=0xF8;
dataArrayRED[9]=0xFC;
dataArrayRED[10]=0xFE;
dataArrayRED[11]=0xEE;
dataArrayRED[12]=0xC3;
dataArrayRED[13]=0xC1;
dataArrayRED[14]=0xC1;
dataArrayRED[15]=0xF1;
dataArrayRED[16]=0x3;
dataArrayRED[17]=0x3;
dataArrayRED[18]=0x3;
dataArrayRED[19]=0x3;
dataArrayRED[20]=0x1;
dataArrayRED[21]=0x0;
dataArrayRED[22]=0x0;
dataArrayRED[23]=0x0;
dataArrayRED[24]=0x0;
dataArrayRED[25]=0x0;
dataArrayRED[26]=0x0;
dataArrayRED[27]=0x0;
dataArrayRED[28]=0x0;
dataArrayRED[29]=0x0;
dataArrayRED[30]=0xE;
dataArrayRED[31]=0x1F;
dataArrayRED[32]=0x3F;
dataArrayRED[33]=0x3E;
dataArrayRED[34]=0x3F;
dataArrayRED[35]=0x3F;
dataArrayRED[36]=0x1F;
dataArrayRED[37]=0x9F;
dataArrayRED[38]=0x1F;
dataArrayRED[39]=0x9F;
dataArrayRED[40]=0x8F;
dataArrayRED[41]=0xF;
dataArrayRED[42]=0x6;
dataArrayRED[43]=0xC0;
dataArrayRED[44]=0xE0;
dataArrayRED[45]=0xC0;
dataArrayRED[46]=0x80;
dataArrayRED[47]=0xC0;
dataArrayRED[48]=0xC0;
dataArrayRED[49]=0xE0;
dataArrayRED[50]=0xF0;
dataArrayRED[51]=0xE0;
dataArrayRED[52]=0xF8;
dataArrayRED[53]=0xFE;
dataArrayRED[54]=0xFE;
dataArrayRED[55]=0xFC;
dataArrayRED[56]=0xF0;
dataArrayRED[57]=0xC3;
dataArrayRED[58]=0x80;
dataArrayRED[59]=0x80;
dataArrayRED[60]=0xE0;
dataArrayRED[61]=0xF8;
dataArrayRED[62]=0xFC;
dataArrayRED[63]=0xF8;
dataArrayRED[64]=0xC8;
dataArrayRED[65]=0x83;
dataArrayRED[66]=0x1;
dataArrayRED[67]=0x10;
dataArrayRED[68]=0xE0;
dataArrayRED[69]=0x0;
dataArrayGREEN[0]=0x0;
dataArrayGREEN[1]=0x0;
dataArrayGREEN[2]=0x0;
dataArrayGREEN[3]=0x0;
dataArrayGREEN[4]=0x0;
dataArrayGREEN[5]=0x0;
dataArrayGREEN[6]=0x0;
dataArrayGREEN[7]=0x0;
dataArrayGREEN[8]=0x0;
dataArrayGREEN[9]=0x0;
dataArrayGREEN[10]=0x0;
dataArrayGREEN[11]=0x0;
dataArrayGREEN[12]=0x0;
dataArrayGREEN[13]=0x0;
dataArrayGREEN[14]=0x80;
dataArrayGREEN[15]=0xC0;
dataArrayGREEN[16]=0xE0;
dataArrayGREEN[17]=0xFC;
dataArrayGREEN[18]=0xFE;
dataArrayGREEN[19]=0xFF;
dataArrayGREEN[20]=0xF8;
dataArrayGREEN[21]=0xF0;
dataArrayGREEN[22]=0x0;
dataArrayGREEN[23]=0x0;
dataArrayGREEN[24]=0x0;
dataArrayGREEN[25]=0x0;
dataArrayGREEN[26]=0x0;
dataArrayGREEN[27]=0x0;
dataArrayGREEN[28]=0x0;
dataArrayGREEN[29]=0x0;
dataArrayGREEN[30]=0x0;
dataArrayGREEN[31]=0x0;
dataArrayGREEN[32]=0x0;
dataArrayGREEN[33]=0x0;
dataArrayGREEN[34]=0x80;
dataArrayGREEN[35]=0xF8;
dataArrayGREEN[36]=0xFC;
dataArrayGREEN[37]=0xFE;
dataArrayGREEN[38]=0xFE;
dataArrayGREEN[39]=0xFC;
dataArrayGREEN[40]=0xF0;
dataArrayGREEN[41]=0x0;
dataArrayGREEN[42]=0x0;
dataArrayGREEN[43]=0x0;
dataArrayGREEN[44]=0x0;
dataArrayGREEN[45]=0x0;
dataArrayGREEN[46]=0x0;
dataArrayGREEN[47]=0x0;
dataArrayGREEN[48]=0x0;
dataArrayGREEN[49]=0x0;
dataArrayGREEN[50]=0x0;
dataArrayGREEN[51]=0x0;
dataArrayGREEN[52]=0x0;
dataArrayGREEN[53]=0x0;
dataArrayGREEN[54]=0x0;
dataArrayGREEN[55]=0x0;
dataArrayGREEN[56]=0x0;
dataArrayGREEN[57]=0x0;
dataArrayGREEN[58]=0x0;
dataArrayGREEN[59]=0x0;
dataArrayGREEN[60]=0x3;
dataArrayGREEN[61]=0xF;
dataArrayGREEN[62]=0x1E;
dataArrayGREEN[63]=0x1E;
dataArrayGREEN[64]=0x3F;
dataArrayGREEN[65]=0x1F;
dataArrayGREEN[66]=0xBE;
dataArrayGREEN[67]=0x9C;
dataArrayGREEN[68]=0x0;
dataArrayGREEN[69]=0x0;



  //function that blinks all the LEDs
  //gets passed the number of blinks and the pause time
  blinkAll_3Bytes(2,100); 
}

void loop() {


  for (int j = 0; j < 70; j++) {
    //load the light sequence you want from array
    dataBLUE = dataArrayBLUE[j];
    dataRED = dataArrayRED[j];
    dataGREEN = dataArrayGREEN[j];

    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, 0);
    //move 'em out
    shiftOut(dataPin, clockPin, dataBLUE);
    shiftOut(dataPin, clockPin, dataRED);   
    shiftOut(dataPin, clockPin, dataGREEN);

    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latchPin, 1);
    delay(1);
  }
}



// the heart of the program
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

  //for each bit in the byte myDataOutï¿½
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
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


//blinks the whole register based on the number of times you want to 
//blink "n" and the pause between them "d"
//starts with a moment of darkness to make sure the first blink
//has its full visual effect.
void blinkAll_3Bytes(int n, int d) {
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  digitalWrite(latchPin, 1);
  delay(200);
  for (int x = 0; x < n; x++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, 255);
    shiftOut(dataPin, clockPin, 255);
    shiftOut(dataPin, clockPin, 255);
    digitalWrite(latchPin, 1);
    delay(d);
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, 0);
    shiftOut(dataPin, clockPin, 0);
    shiftOut(dataPin, clockPin, 0);
    digitalWrite(latchPin, 1);
    delay(d);
  }
}

