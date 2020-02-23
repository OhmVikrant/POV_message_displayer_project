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
dataArrayBLUE[0]=0xFF;
dataArrayBLUE[1]=0x80;
dataArrayBLUE[2]=0xFF;
dataArrayBLUE[3]=0x80;
dataArrayBLUE[4]=0xFF;
dataArrayBLUE[5]=0x80;
dataArrayBLUE[6]=0xFF;
dataArrayBLUE[7]=0x80;
dataArrayBLUE[8]=0xFF;
dataArrayBLUE[9]=0x80;
dataArrayBLUE[10]=0xFF;
dataArrayBLUE[11]=0x80;
dataArrayBLUE[12]=0xFF;
dataArrayBLUE[13]=0x80;
dataArrayBLUE[14]=0xFF;
dataArrayBLUE[15]=0x80;
dataArrayBLUE[16]=0xFF;
dataArrayBLUE[17]=0x80;
dataArrayBLUE[18]=0xFF;
dataArrayBLUE[19]=0x80;
dataArrayBLUE[20]=0xFF;
dataArrayBLUE[21]=0x80;
dataArrayBLUE[22]=0xFF;
dataArrayBLUE[23]=0x80;
dataArrayBLUE[24]=0xFF;
dataArrayBLUE[25]=0x80;
dataArrayBLUE[26]=0xFF;
dataArrayBLUE[27]=0x80;
dataArrayBLUE[28]=0xFF;
dataArrayBLUE[29]=0x80;
dataArrayBLUE[30]=0xFF;
dataArrayBLUE[31]=0x80;
dataArrayBLUE[32]=0xFF;
dataArrayBLUE[33]=0x80;
dataArrayBLUE[34]=0xFF;
dataArrayBLUE[35]=0x80;
dataArrayBLUE[36]=0xFF;
dataArrayBLUE[37]=0x80;
dataArrayBLUE[38]=0xFF;
dataArrayBLUE[39]=0x80;
dataArrayBLUE[40]=0xFF;
dataArrayBLUE[41]=0x80;
dataArrayBLUE[42]=0xFF;
dataArrayBLUE[43]=0x80;
dataArrayBLUE[44]=0xFF;
dataArrayBLUE[45]=0x80;
dataArrayBLUE[46]=0xFF;
dataArrayBLUE[47]=0x80;
dataArrayBLUE[48]=0xFF;
dataArrayBLUE[49]=0x80;
dataArrayBLUE[50]=0xFF;
dataArrayBLUE[51]=0x80;
dataArrayBLUE[52]=0xFF;
dataArrayBLUE[53]=0x80;
dataArrayBLUE[54]=0xFF;
dataArrayBLUE[55]=0x80;
dataArrayBLUE[56]=0xFF;
dataArrayBLUE[57]=0x80;
dataArrayBLUE[58]=0xFF;
dataArrayBLUE[59]=0x80;
dataArrayBLUE[60]=0xFF;
dataArrayBLUE[61]=0x80;
dataArrayBLUE[62]=0xFF;
dataArrayBLUE[63]=0x80;
dataArrayBLUE[64]=0xFF;
dataArrayBLUE[65]=0x80;
dataArrayBLUE[66]=0xFF;
dataArrayBLUE[67]=0x80;
dataArrayBLUE[68]=0xFF;
dataArrayBLUE[69]=0x80;
dataArrayRED[0]=0xFF;
dataArrayRED[1]=0x81;
dataArrayRED[2]=0xFF;
dataArrayRED[3]=0x81;
dataArrayRED[4]=0xFF;
dataArrayRED[5]=0x81;
dataArrayRED[6]=0xFF;
dataArrayRED[7]=0x81;
dataArrayRED[8]=0xFF;
dataArrayRED[9]=0x81;
dataArrayRED[10]=0xFF;
dataArrayRED[11]=0x81;
dataArrayRED[12]=0xFF;
dataArrayRED[13]=0x81;
dataArrayRED[14]=0xFF;
dataArrayRED[15]=0x81;
dataArrayRED[16]=0xFF;
dataArrayRED[17]=0x81;
dataArrayRED[18]=0xFF;
dataArrayRED[19]=0x81;
dataArrayRED[20]=0xFF;
dataArrayRED[21]=0x81;
dataArrayRED[22]=0xFF;
dataArrayRED[23]=0x81;
dataArrayRED[24]=0xFF;
dataArrayRED[25]=0x81;
dataArrayRED[26]=0xFF;
dataArrayRED[27]=0x81;
dataArrayRED[28]=0xFF;
dataArrayRED[29]=0x81;
dataArrayRED[30]=0xFF;
dataArrayRED[31]=0x81;
dataArrayRED[32]=0xFF;
dataArrayRED[33]=0x81;
dataArrayRED[34]=0xFF;
dataArrayRED[35]=0x81;
dataArrayRED[36]=0xFF;
dataArrayRED[37]=0x81;
dataArrayRED[38]=0xFF;
dataArrayRED[39]=0x81;
dataArrayRED[40]=0xFF;
dataArrayRED[41]=0x81;
dataArrayRED[42]=0xFF;
dataArrayRED[43]=0x81;
dataArrayRED[44]=0xFF;
dataArrayRED[45]=0x81;
dataArrayRED[46]=0xFF;
dataArrayRED[47]=0x81;
dataArrayRED[48]=0xFF;
dataArrayRED[49]=0x81;
dataArrayRED[50]=0xFF;
dataArrayRED[51]=0x81;
dataArrayRED[52]=0xFF;
dataArrayRED[53]=0x81;
dataArrayRED[54]=0xFF;
dataArrayRED[55]=0x81;
dataArrayRED[56]=0xFF;
dataArrayRED[57]=0x81;
dataArrayRED[58]=0xFF;
dataArrayRED[59]=0x81;
dataArrayRED[60]=0xFF;
dataArrayRED[61]=0x81;
dataArrayRED[62]=0xFF;
dataArrayRED[63]=0x81;
dataArrayRED[64]=0xFF;
dataArrayRED[65]=0x81;
dataArrayRED[66]=0xFF;
dataArrayRED[67]=0x81;
dataArrayRED[68]=0xFF;
dataArrayRED[69]=0x81;
dataArrayGREEN[0]=0xFF;
dataArrayGREEN[1]=0x1;
dataArrayGREEN[2]=0xFF;
dataArrayGREEN[3]=0x1;
dataArrayGREEN[4]=0xFF;
dataArrayGREEN[5]=0x1;
dataArrayGREEN[6]=0xFF;
dataArrayGREEN[7]=0x1;
dataArrayGREEN[8]=0xFF;
dataArrayGREEN[9]=0x1;
dataArrayGREEN[10]=0xFF;
dataArrayGREEN[11]=0x1;
dataArrayGREEN[12]=0xFF;
dataArrayGREEN[13]=0x1;
dataArrayGREEN[14]=0xFF;
dataArrayGREEN[15]=0x1;
dataArrayGREEN[16]=0xFF;
dataArrayGREEN[17]=0x1;
dataArrayGREEN[18]=0xFF;
dataArrayGREEN[19]=0x1;
dataArrayGREEN[20]=0xFF;
dataArrayGREEN[21]=0x1;
dataArrayGREEN[22]=0xFF;
dataArrayGREEN[23]=0x1;
dataArrayGREEN[24]=0xFF;
dataArrayGREEN[25]=0x1;
dataArrayGREEN[26]=0xFF;
dataArrayGREEN[27]=0x1;
dataArrayGREEN[28]=0xFF;
dataArrayGREEN[29]=0x1;
dataArrayGREEN[30]=0xFF;
dataArrayGREEN[31]=0x1;
dataArrayGREEN[32]=0xFF;
dataArrayGREEN[33]=0x1;
dataArrayGREEN[34]=0xFF;
dataArrayGREEN[35]=0x1;
dataArrayGREEN[36]=0xFF;
dataArrayGREEN[37]=0x1;
dataArrayGREEN[38]=0xFF;
dataArrayGREEN[39]=0x1;
dataArrayGREEN[40]=0xFF;
dataArrayGREEN[41]=0x1;
dataArrayGREEN[42]=0xFF;
dataArrayGREEN[43]=0x1;
dataArrayGREEN[44]=0xFF;
dataArrayGREEN[45]=0x1;
dataArrayGREEN[46]=0xFF;
dataArrayGREEN[47]=0x1;
dataArrayGREEN[48]=0xFF;
dataArrayGREEN[49]=0x1;
dataArrayGREEN[50]=0xFF;
dataArrayGREEN[51]=0x1;
dataArrayGREEN[52]=0xFF;
dataArrayGREEN[53]=0x1;
dataArrayGREEN[54]=0xFF;
dataArrayGREEN[55]=0x1;
dataArrayGREEN[56]=0xFF;
dataArrayGREEN[57]=0x1;
dataArrayGREEN[58]=0xFF;
dataArrayGREEN[59]=0x1;
dataArrayGREEN[60]=0xFF;
dataArrayGREEN[61]=0x1;
dataArrayGREEN[62]=0xFF;
dataArrayGREEN[63]=0x1;
dataArrayGREEN[64]=0xFF;
dataArrayGREEN[65]=0x1;
dataArrayGREEN[66]=0xFF;
dataArrayGREEN[67]=0x1;
dataArrayGREEN[68]=0xFF;
dataArrayGREEN[69]=0x1;


  


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

