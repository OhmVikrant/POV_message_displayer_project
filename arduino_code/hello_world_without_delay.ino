long delayTime = 1;
long charBreak = 4;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;








void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
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






int counter [5][5] ={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
int counterDefault [5][5] ={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
unsigned long prevmillis=0;
int charBreakFlag[5]={0,0,0,0,0};
int charBreakFlagDefault[5]={0,0,0,0,0};
int switchFlagaTor=0;
int switchFlagrToi=0;
int switchFlagiToe=0;
int switchFlageTos=0;









void loop()
{
  
unsigned long currentmillis = millis();
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
}
