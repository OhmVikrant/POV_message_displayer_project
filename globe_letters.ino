long delayTime = 1;
long charBreak = 4;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;







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








void setup()
{

   pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);




  
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



 
}






int a[] = {1, 6, 26, 6, 1};
int e[] = {31, 21, 21, 17, 0};
int i[] = {0, 17, 31, 17, 0};
int r[] = {31, 20, 22, 9, 0};
int s[] = {8, 21, 21, 2, 0};







void displayLine(int line)
{
  int myline;
  myline = line;
  if (myline>=16) {digitalWrite(LED1, HIGH); myline-=16;} else {digitalWrite(LED1, LOW);}
  if (myline>=8)  {digitalWrite(LED2, HIGH); myline-=8;}  else {digitalWrite(LED2, LOW);}
  if (myline>=4)  {digitalWrite(LED3, HIGH); myline-=4;}  else {digitalWrite(LED3, LOW);}
  if (myline>=2)  {digitalWrite(LED4, HIGH); myline-=2;}  else {digitalWrite(LED4, LOW);}
  if (myline>=1)  {digitalWrite(LED5, HIGH); myline-=1;}  else {digitalWrite(LED5, LOW);}
}





void set1DArray(int a[5],int b[5])
{
  for (int m=0; m<5; m++)
  {
    a[m]=b[m];
  }
}

void set2DArray (int a[5][5],int b[5][5])
{
  for (int m=0;m<5;m++)
  {
    for (int n=0;n<5;n++)
    {
      a[m][n]=b[m][n];
    }
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










int counter [5][5] ={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
int counterDefault [5][5] ={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
unsigned long prevmillis=0;
unsigned long initialtime=0;
int charBreakFlag[5]={0,0,0,0,0};
int charBreakFlagDefault[5]={0,0,0,0,0};
int switchFlagaTor=0;
int switchFlagrToi=0;
int switchFlagiToe=0;
int switchFlageTos=0;
int j=0;








void loop()
{
  
unsigned long currentmillis = millis();
unsigned long finaltime = millis();


if (counter[0][0]==0)
  {
      displayLine(a[0]);
  
      counter[0][0]=counter[0][0]+1;
      prevmillis= currentmillis;
  }

else if (counter[0][1]==0)
{
  if (currentmillis-prevmillis>=delayTime )
  {
    displayLine(a[1]);
    counter[0][1]=counter[0][1]+1;
    prevmillis=currentmillis;
  }
    
}
  
else if (counter[0][2]==0)
{
  if (currentmillis-prevmillis>=delayTime )
  {
    displayLine(a[2]);
    counter[0][2]=counter[0][2]+1;
    prevmillis=currentmillis;
  }
    
}


else if (counter[0][3]==0)
{
  if (currentmillis-prevmillis>=delayTime )
  {
    displayLine(a[3]);
    counter[0][3]=counter[0][3]+1;
    prevmillis=currentmillis;
  }
    
}


else if (counter[0][4]==0)
{
  if (currentmillis-prevmillis>=delayTime )
  {
    displayLine(a[4]);
    counter[0][4]=counter[0][4]+1;
    prevmillis=currentmillis;
  }
    
}

else if (charBreakFlag[0]==0)
{
    if (currentmillis-prevmillis>=delayTime)
    {
      displayLine(0);
      charBreakFlag[0]++;
      prevmillis=currentmillis;
    }
}

else
{
  if ( switchFlagaTor==0 )
  {
    if (currentmillis-prevmillis>=charBreak)
    {
    
    
      displayLine(r[0]);
      counter[1][0]++;
      switchFlagaTor++;
      prevmillis=currentmillis;
    
    }
  
  }
  else if (counter[1][1]==0 ) 
  {
    if (currentmillis-prevmillis>=delayTime)
    {
      displayLine(r[1]);
      counter[1][1]++;
      prevmillis=currentmillis;
    }
    
  }

  else if (counter[1][2]==0) 
  {
    if (currentmillis-prevmillis>=delayTime)
    {
      displayLine(r[2]);
      counter[1][2]++;
      prevmillis=currentmillis;
    }
    
  }


  else if (counter[1][3]==0) 
  {
    if (currentmillis-prevmillis>=delayTime)
    {
      displayLine(r[3]);
      counter[1][3]++;
      prevmillis=currentmillis;
    }
    
  }


  else if (counter[1][4]==0) 
  {
    if (currentmillis-prevmillis>=delayTime)
    {
      displayLine(r[4]);
      counter[1][4]++;
      prevmillis=currentmillis;
    }
    
  }
  else if (charBreakFlag[1]==0)
  {
    if (currentmillis-prevmillis>=delayTime)
    {
      displayLine(0);
      charBreakFlag[1]++;
      prevmillis=currentmillis;
      
    }
  }
  else
  {
    if (switchFlagrToi==0)
    {
       if (currentmillis-prevmillis>=charBreak)
       {
    
    
        displayLine(i[0]);
        counter[2][0]++;
        switchFlagrToi++;
        prevmillis=currentmillis;
    
       }
    }

    else if (counter[2][1]==0 ) 
    {
    
      if (currentmillis-prevmillis>=delayTime)
      {
        displayLine(i[1]);
        counter[2][1]++;
        prevmillis=currentmillis;
      }
    
    }

    else if (counter[2][2]==0) 
    {
      if (currentmillis-prevmillis>=delayTime)
      {
        displayLine(i[2]);
        counter[2][2]++;
        prevmillis=currentmillis;
      }
    
    }


    else if (counter[2][3]==0) 
    {
      if (currentmillis-prevmillis>=delayTime)
      {
        displayLine(i[3]);
        counter[2][3]++;
        prevmillis=currentmillis;
      }
    
    }


    else if (counter[2][4]==0) 
    {
      if (currentmillis-prevmillis>=delayTime)
      {
        displayLine(i[4]);
        counter[2][4]++;
        prevmillis=currentmillis;
      }
    
    }

    else if (charBreakFlag[2]==0)
    {
      if (currentmillis-prevmillis>=delayTime)
      {
        displayLine(0);
        charBreakFlag[2]++;
        prevmillis=currentmillis;
      
      }
    }

    else
    {
      if (switchFlagiToe==0)
      {
        if (currentmillis-prevmillis>=charBreak)
        {
          displayLine(e[0]);
          counter[3][0]++;
          switchFlagiToe++;
          prevmillis=currentmillis;
        }
      }

      else if (counter[3][1]==0 ) 
      {
    
        if (currentmillis-prevmillis>=delayTime)
        {
          displayLine(e[1]);
          counter[3][1]++;
          prevmillis=currentmillis;
        }
    
      }

      else if (counter[3][2]==0) 
      {
        if (currentmillis-prevmillis>=delayTime)
        {
          displayLine(e[2]);
          counter[3][2]++;
          prevmillis=currentmillis;
        }
    
      }


      else if (counter[3][3]==0) 
      {
        if (currentmillis-prevmillis>=delayTime)
        {
          displayLine(e[3]);
          counter[3][3]++;
          prevmillis=currentmillis;
        }
    
      }


      else if (counter[3][4]==0) 
      {
        if (currentmillis-prevmillis>=delayTime)
        {
          displayLine(e[4]);
          counter[3][4]++;
          prevmillis=currentmillis;
        }
    
      }

      else if (charBreakFlag[3]==0)
      {
        if (currentmillis-prevmillis>=delayTime)
        {
          displayLine(0);
          charBreakFlag[3]++;
          prevmillis=currentmillis;
      
        }
      }

      else
      {
        if (switchFlageTos==0)
        {
          if (currentmillis-prevmillis>=charBreak)
          {
            displayLine(s[0]);
            switchFlageTos++;
            counter[4][0]++;
            prevmillis=currentmillis;
          }
        }

        else if (counter[4][1]==0 ) 
        {
    
          if (currentmillis-prevmillis>=delayTime)
          {
            displayLine(s[1]);
            counter[4][1]++;
            prevmillis=currentmillis;
          }
    
        }

        else if (counter[4][2]==0) 
        {
          if (currentmillis-prevmillis>=delayTime)
          {
            displayLine(s[2]);
            counter[4][2]++;
            prevmillis=currentmillis;
          }
    
        }


        else if (counter[4][3]==0) 
        {
          if (currentmillis-prevmillis>=delayTime)
          {
            displayLine(s[3]);
            counter[4][3]++;
            prevmillis=currentmillis;
          }
    
        }


        else if (counter[4][4]==0) 
        {
          if (currentmillis-prevmillis>=delayTime)
          {
            displayLine(s[4]);
            counter[4][4]++;
            prevmillis=currentmillis;
          }
    
        }
        

        else if (charBreakFlag[4]==0)
        {
          if (currentmillis-prevmillis>=delayTime)
          {
            displayLine(0);
            charBreakFlag[4]++;
            prevmillis=currentmillis;
      
          }
        }

        else
        {
          if (currentmillis-prevmillis>=25)
          {
            set2DArray(counter,counterDefault);
            set1DArray(charBreakFlag,charBreakFlagDefault);
            switchFlagaTor=0;
            switchFlagrToi=0;
            switchFlagiToe=0;
            switchFlageTos=0;
            currentmillis=prevmillis;
          }
          
        }
     }
     
    }

  }
}

if (j>=70)
{
  if (finaltime-initialtime>=25)
  {
     j=0;
     initialtime=finaltime;
  }
}


else if (finaltime-initialtime>=1.9)
{
  //load the light sequence you want from array
    dataBLUE = dataArrayBLUE[j];
    dataRED = dataArrayRED[j];
    dataGREEN = dataArrayGREEN[j];

    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, 0);
    //move 'em out
    shiftOut(dataPin, clockPin, dataGREEN);
    
    shiftOut(dataPin, clockPin, dataRED);   
    shiftOut(dataPin, clockPin, dataBLUE);

    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latchPin, 1);
    j++;
    initialtime=finaltime;
}

}
