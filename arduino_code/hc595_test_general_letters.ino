// DOESN'T WORK FOR >3 REGISTERS

int SER_Pin = 11;   //pin 14 on the 75HC595
int RCLK_Pin = 8;  //pin 12 on the 75HC595
int SRCLK_Pin = 12; //pin 11 on the 75HC595
int delayTime = 0.8;//_______________________________________________________________________________________
int charBreak = 2.1;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;


//How many of the shift registers - change this
#define number_of_74hc595s 3

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

void setup(){
  pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);


  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
  writeRegisters();
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

int a[] = {1, 6, 26, 6, 1};
int b[] = {31, 21, 21, 10, 0};
int c2[] = {14, 17, 17, 10, 0};
int d[] = {31, 17, 17, 14, 0};
int e[] = {31, 21, 21, 17, 0};
int f[] = {31, 20, 20, 16, 0};
int g[] = {14, 17, 19, 10, 0};
int h[] = {31, 4, 4, 4, 31};
int i[] = {0, 17, 31, 17, 0};
int j[] = {0, 17, 30, 16, 0};
int k[] = {31, 4, 10, 17, 0};
int l[] = {31, 1, 1, 1, 0};
int m[] = {31, 12, 3, 12, 31};
int n[] = {31, 12, 3, 31, 0};
int o[] = {14, 17, 17, 14, 0};
int p[] = {31, 20, 20, 8, 0};
int q[] = {14, 17, 19, 14, 2};
int r[] = {31, 20, 22, 9, 0};
int s[] = {8, 21, 21, 2, 0};
int t[] = {16, 16, 31, 16, 16};
int u[] = {30, 1, 1, 30, 0};
int v[] = {24, 6, 1, 6, 24};
int w[] = {28, 3, 12, 3, 28};
int x[] = {17, 10, 4, 10, 17};
int y[] = {17, 10, 4, 8, 16};
int z[] = {19, 21, 21, 25, 0};

int eos[] = {0, 1, 0, 0, 0};
int excl[] = {0, 29, 0, 0, 0};
int ques[] = {8, 19, 20, 8, 0};

void displayLine(int line){
int myline;
myline = line;
if (myline>=16) {digitalWrite(LED1, HIGH); myline-=16;} else {digitalWrite(LED1, LOW);}
if (myline>=8)  {digitalWrite(LED2, HIGH); myline-=8;}  else {digitalWrite(LED2, LOW);}
if (myline>=4)  {digitalWrite(LED3, HIGH); myline-=4;}  else {digitalWrite(LED3, LOW);}
if (myline>=2)  {digitalWrite(LED4, HIGH); myline-=2;}  else {digitalWrite(LED4, LOW);}
if (myline>=1)  {digitalWrite(LED5, HIGH); myline-=1;}  else {digitalWrite(LED5, LOW);}
}

void displayChar(char c){
if (c == 'a'){for (int i = 0; i <5; i++){displayLine(a[i]);delay(delayTime);}displayLine(0);}
if (c == 'b'){for (int i = 0; i <5; i++){displayLine(b[i]);delay(delayTime);}displayLine(0);}
if (c == 'c'){for (int i = 0; i <5; i++){displayLine(c2[i]);delay(delayTime);}displayLine(0);}// REVIEW REVIEW REVIEW REVIEW REVIEW REVIEW REVIEW REVIEW REVIEW 'c2'
if (c == 'd'){for (int i = 0; i <5; i++){displayLine(d[i]);delay(delayTime);}displayLine(0);}
if (c == 'e'){for (int i = 0; i <5; i++){displayLine(e[i]);delay(delayTime);}displayLine(0);}
if (c == 'f'){for (int i = 0; i <5; i++){displayLine(f[i]);delay(delayTime);}displayLine(0);}
if (c == 'g'){for (int i = 0; i <5; i++){displayLine(g[i]);delay(delayTime);}displayLine(0);}
if (c == 'h'){for (int i = 0; i <5; i++){displayLine(h[i]);delay(delayTime);}displayLine(0);}
if (c == 'i'){for (int it = 0; it <5; it++){displayLine(i[it]);delay(delayTime);}displayLine(0);}
if (c == 'j'){for (int i = 0; i <5; i++){displayLine(j[i]);delay(delayTime);}displayLine(0);}
if (c == 'k'){for (int i = 0; i <5; i++){displayLine(k[i]);delay(delayTime);}displayLine(0);}
if (c == 'l'){for (int i = 0; i <5; i++){displayLine(l[i]);delay(delayTime);}displayLine(0);}
if (c == 'm'){for (int i = 0; i <5; i++){displayLine(m[i]);delay(delayTime);}displayLine(0);}
if (c == 'n'){for (int i = 0; i <5; i++){displayLine(n[i]);delay(delayTime);}displayLine(0);}
if (c == 'o'){for (int i = 0; i <5; i++){displayLine(o[i]);delay(delayTime);}displayLine(0);}
if (c == 'p'){for (int i = 0; i <5; i++){displayLine(p[i]);delay(delayTime);}displayLine(0);}
if (c == 'q'){for (int i = 0; i <5; i++){displayLine(q[i]);delay(delayTime);}displayLine(0);}
if (c == 'r'){for (int i = 0; i <5; i++){displayLine(r[i]);delay(delayTime);}displayLine(0);}
if (c == 's'){for (int i = 0; i <5; i++){displayLine(s[i]);delay(delayTime);}displayLine(0);}
if (c == 't'){for (int i = 0; i <5; i++){displayLine(t[i]);delay(delayTime);}displayLine(0);}
if (c == 'u'){for (int i = 0; i <5; i++){displayLine(u[i]);delay(delayTime);}displayLine(0);}
if (c == 'v'){for (int i = 0; i <5; i++){displayLine(v[i]);delay(delayTime);}displayLine(0);}
if (c == 'w'){for (int i = 0; i <5; i++){displayLine(w[i]);delay(delayTime);}displayLine(0);}
if (c == 'x'){for (int i = 0; i <5; i++){displayLine(x[i]);delay(delayTime);}displayLine(0);}
if (c == 'y'){for (int i = 0; i <5; i++){displayLine(y[i]);delay(delayTime);}displayLine(0);}
if (c == 'z'){for (int i = 0; i <5; i++){displayLine(z[i]);delay(delayTime);}displayLine(0);}
if (c == '!'){for (int i = 0; i <5; i++){displayLine(excl[i]);delay(delayTime);}displayLine(0);}
if (c == '?'){for (int i = 0; i <5; i++){displayLine(ques[i]);delay(delayTime);}displayLine(0);}
if (c == '.'){for (int i = 0; i <5; i++){displayLine(eos[i]);delay(delayTime);}displayLine(0);}
delay(charBreak);
}

void displayString(char* s){
for (int i = 0; i<=strlen(s); i++){
displayChar(s[i]);
}
}
//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}


void loop(){
  displayString("hello world");
  setRegisterPin(0, LOW);
  setRegisterPin(1, HIGH);
  setRegisterPin(2, LOW);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, LOW);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, LOW);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, LOW);
  setRegisterPin(9, HIGH);
  setRegisterPin(10, LOW);
  setRegisterPin(11, HIGH);
  setRegisterPin(12, LOW);
  setRegisterPin(13, HIGH);
  setRegisterPin(14, LOW);
  setRegisterPin(15, HIGH);
  setRegisterPin(16, LOW);
  setRegisterPin(17, HIGH);
  setRegisterPin(18, LOW);
  setRegisterPin(19, HIGH);
  setRegisterPin(20, LOW);
  setRegisterPin(21, HIGH);
  setRegisterPin(22, LOW);
  setRegisterPin(23, HIGH);
  writeRegisters();
  delay(500);
  clearRegisters();
  setRegisterPin(0, HIGH);
  setRegisterPin(1, LOW);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, LOW);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, LOW);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, LOW);
  setRegisterPin(8, HIGH);
  setRegisterPin(9, LOW);
  setRegisterPin(10, HIGH);
  setRegisterPin(11, LOW);
  setRegisterPin(12, HIGH);
  setRegisterPin(13, LOW);
  setRegisterPin(14, HIGH);
  setRegisterPin(15, LOW);
  setRegisterPin(16, HIGH);
  setRegisterPin(17, LOW);
  setRegisterPin(18, HIGH);
  setRegisterPin(19, LOW);
  setRegisterPin(20, HIGH);
  setRegisterPin(21, LOW);
  setRegisterPin(22, HIGH);
  setRegisterPin(23, LOW);
  writeRegisters();
  delay(500);
  clearRegisters();
}
