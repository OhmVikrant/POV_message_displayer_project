//**************************************************************//
//  Name    : shiftOutCode, Predefined Dual Array Style         //
//  Author  : Carlyn Maw, Tom Igoe                              //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//****************************************************************//

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
dataArrayBLUE[0]=0xBD;
dataArrayBLUE[1]=0xBD;
dataArrayBLUE[2]=0xBD;
dataArrayBLUE[3]=0x81;
dataArrayBLUE[4]=0xBD;
dataArrayBLUE[5]=0xBD;
dataArrayBLUE[6]=0xBD;
dataArrayBLUE[7]=0xBD;
dataArrayBLUE[8]=0xBC;
dataArrayBLUE[9]=0xBD;
dataArrayBLUE[10]=0xBD;
dataArrayBLUE[11]=0xBD;
dataArrayBLUE[12]=0xBD;
dataArrayBLUE[13]=0x81;
dataArrayBLUE[14]=0xBD;
dataArrayBLUE[15]=0xBD;
dataArrayBLUE[16]=0xBD;
dataArrayBLUE[17]=0xBD;
dataArrayBLUE[18]=0xBC;
dataArrayBLUE[19]=0xBD;
dataArrayBLUE[20]=0xBD;
dataArrayBLUE[21]=0xBD;
dataArrayBLUE[22]=0xBD;
dataArrayBLUE[23]=0x81;
dataArrayBLUE[24]=0xBD;
dataArrayBLUE[25]=0xBD;
dataArrayBLUE[26]=0xBD;
dataArrayBLUE[27]=0xBD;
dataArrayBLUE[28]=0xBC;
dataArrayBLUE[29]=0xBD;
dataArrayBLUE[30]=0xBD;
dataArrayBLUE[31]=0xBD;
dataArrayBLUE[32]=0xBD;
dataArrayBLUE[33]=0x81;
dataArrayBLUE[34]=0xBD;
dataArrayBLUE[35]=0xBD;
dataArrayBLUE[36]=0xBD;
dataArrayBLUE[37]=0xBD;
dataArrayBLUE[38]=0xBC;
dataArrayBLUE[39]=0xBD;
dataArrayBLUE[40]=0xBD;
dataArrayBLUE[41]=0xBD;
dataArrayBLUE[42]=0xBD;
dataArrayBLUE[43]=0x80;
dataArrayBLUE[44]=0x9F;
dataArrayBLUE[45]=0xB1;
dataArrayBLUE[46]=0xE0;
dataArrayBLUE[47]=0xC4;
dataArrayBLUE[48]=0xCA;
dataArrayBLUE[49]=0xC4;
dataArrayBLUE[50]=0xE0;
dataArrayBLUE[51]=0xB1;
dataArrayBLUE[52]=0x9F;
dataArrayBLUE[53]=0x80;
dataArrayBLUE[54]=0xBD;
dataArrayBLUE[55]=0xBD;
dataArrayBLUE[56]=0xBD;
dataArrayBLUE[57]=0xBD;
dataArrayBLUE[58]=0xBC;
dataArrayBLUE[59]=0xBD;
dataArrayBLUE[60]=0xBD;
dataArrayBLUE[61]=0xBD;
dataArrayBLUE[62]=0xBD;
dataArrayBLUE[63]=0x81;
dataArrayBLUE[64]=0xBD;
dataArrayBLUE[65]=0xBD;
dataArrayBLUE[66]=0xBD;
dataArrayBLUE[67]=0xBD;
dataArrayBLUE[68]=0xBC;
dataArrayBLUE[69]=0xBD;
dataArrayRED[0]=0xE7;
dataArrayRED[1]=0xE7;
dataArrayRED[2]=0xE7;
dataArrayRED[3]=0xE7;
dataArrayRED[4]=0xE7;
dataArrayRED[5]=0xE7;
dataArrayRED[6]=0xE7;
dataArrayRED[7]=0xE7;
dataArrayRED[8]=0x0;
dataArrayRED[9]=0xE7;
dataArrayRED[10]=0xE7;
dataArrayRED[11]=0xE7;
dataArrayRED[12]=0xE7;
dataArrayRED[13]=0xE7;
dataArrayRED[14]=0xE7;
dataArrayRED[15]=0xE7;
dataArrayRED[16]=0xE7;
dataArrayRED[17]=0xE7;
dataArrayRED[18]=0x0;
dataArrayRED[19]=0xE7;
dataArrayRED[20]=0xE7;
dataArrayRED[21]=0xE7;
dataArrayRED[22]=0xE7;
dataArrayRED[23]=0xE7;
dataArrayRED[24]=0xE7;
dataArrayRED[25]=0xE7;
dataArrayRED[26]=0xE7;
dataArrayRED[27]=0xE7;
dataArrayRED[28]=0x0;
dataArrayRED[29]=0xE7;
dataArrayRED[30]=0xE7;
dataArrayRED[31]=0xE7;
dataArrayRED[32]=0xE7;
dataArrayRED[33]=0xE7;
dataArrayRED[34]=0xE7;
dataArrayRED[35]=0xE7;
dataArrayRED[36]=0xE7;
dataArrayRED[37]=0xE7;
dataArrayRED[38]=0x0;
dataArrayRED[39]=0xE7;
dataArrayRED[40]=0xE7;
dataArrayRED[41]=0xE7;
dataArrayRED[42]=0xE7;
dataArrayRED[43]=0x67;
dataArrayRED[44]=0x27;
dataArrayRED[45]=0xA7;
dataArrayRED[46]=0xE7;
dataArrayRED[47]=0x67;
dataArrayRED[48]=0x60;
dataArrayRED[49]=0x67;
dataArrayRED[50]=0xE7;
dataArrayRED[51]=0xA7;
dataArrayRED[52]=0x27;
dataArrayRED[53]=0x67;
dataArrayRED[54]=0xE7;
dataArrayRED[55]=0xE7;
dataArrayRED[56]=0xE7;
dataArrayRED[57]=0xE7;
dataArrayRED[58]=0x0;
dataArrayRED[59]=0xE7;
dataArrayRED[60]=0xE7;
dataArrayRED[61]=0xE7;
dataArrayRED[62]=0xE7;
dataArrayRED[63]=0xE7;
dataArrayRED[64]=0xE7;
dataArrayRED[65]=0xE7;
dataArrayRED[66]=0xE7;
dataArrayRED[67]=0xE7;
dataArrayRED[68]=0x0;
dataArrayRED[69]=0xE7;
dataArrayGREEN[0]=0xBD;
dataArrayGREEN[1]=0xBD;
dataArrayGREEN[2]=0xBD;
dataArrayGREEN[3]=0x81;
dataArrayGREEN[4]=0xBD;
dataArrayGREEN[5]=0xBD;
dataArrayGREEN[6]=0xBD;
dataArrayGREEN[7]=0xBD;
dataArrayGREEN[8]=0x3D;
dataArrayGREEN[9]=0xBD;
dataArrayGREEN[10]=0xBD;
dataArrayGREEN[11]=0xBD;
dataArrayGREEN[12]=0xBD;
dataArrayGREEN[13]=0x81;
dataArrayGREEN[14]=0xBD;
dataArrayGREEN[15]=0xBD;
dataArrayGREEN[16]=0xBD;
dataArrayGREEN[17]=0xBD;
dataArrayGREEN[18]=0x3D;
dataArrayGREEN[19]=0xBD;
dataArrayGREEN[20]=0xBD;
dataArrayGREEN[21]=0xBD;
dataArrayGREEN[22]=0xBD;
dataArrayGREEN[23]=0x81;
dataArrayGREEN[24]=0xBD;
dataArrayGREEN[25]=0xBD;
dataArrayGREEN[26]=0xBD;
dataArrayGREEN[27]=0xBD;
dataArrayGREEN[28]=0x3D;
dataArrayGREEN[29]=0xBD;
dataArrayGREEN[30]=0xBD;
dataArrayGREEN[31]=0xBD;
dataArrayGREEN[32]=0xBD;
dataArrayGREEN[33]=0x81;
dataArrayGREEN[34]=0xBD;
dataArrayGREEN[35]=0xBD;
dataArrayGREEN[36]=0xBD;
dataArrayGREEN[37]=0xBD;
dataArrayGREEN[38]=0x3D;
dataArrayGREEN[39]=0xBD;
dataArrayGREEN[40]=0xBD;
dataArrayGREEN[41]=0xBD;
dataArrayGREEN[42]=0xBD;
dataArrayGREEN[43]=0x81;
dataArrayGREEN[44]=0xBD;
dataArrayGREEN[45]=0xBD;
dataArrayGREEN[46]=0xBD;
dataArrayGREEN[47]=0xBD;
dataArrayGREEN[48]=0x3D;
dataArrayGREEN[49]=0xBD;
dataArrayGREEN[50]=0xBD;
dataArrayGREEN[51]=0xBD;
dataArrayGREEN[52]=0xBD;
dataArrayGREEN[53]=0x81;
dataArrayGREEN[54]=0xBD;
dataArrayGREEN[55]=0xBD;
dataArrayGREEN[56]=0xBD;
dataArrayGREEN[57]=0xBD;
dataArrayGREEN[58]=0x3D;
dataArrayGREEN[59]=0xBD;
dataArrayGREEN[60]=0xBD;
dataArrayGREEN[61]=0xBD;
dataArrayGREEN[62]=0xBD;
dataArrayGREEN[63]=0x81;
dataArrayGREEN[64]=0xBD;
dataArrayGREEN[65]=0xBD;
dataArrayGREEN[66]=0xBD;
dataArrayGREEN[67]=0xBD;
dataArrayGREEN[68]=0x3D;
dataArrayGREEN[69]=0xBD;


  //function that blinks all the LEDs
  //gets passed the number of blinks and the pause time
  blinkAll_3Bytes(2,100); 
}

void loop() {


  for (int j = 0; j < 70; j++) {
    //load the light sequence you want from array
    
    dataRED = dataArrayRED[j];
    dataGREEN = dataArrayGREEN[j];
    dataBLUE = dataArrayBLUE[j];

    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, 0);
    //move 'em out
    
    shiftOut(dataPin, clockPin, dataGREEN);   
    shiftOut(dataPin, clockPin, dataRED);
    shiftOut(dataPin, clockPin, dataBLUE);

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
