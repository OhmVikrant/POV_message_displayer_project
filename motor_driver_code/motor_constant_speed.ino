



/*******************************************************************************
 * IO DEFINITION                                                                *
 *******************************************************************************/

// PWM is connected to pin 3.
const int pinPwm = 3;

// DIR is connected to pin 2.
const int pinDir = 2;



/*******************************************************************************
 * PRIVATE GLOBAL VARIABLES                                                     *
 *******************************************************************************/

// Speed of the motor.
static int iSpeed = 0;

// Acceleration of the motor.
static int iAcc = 1;


/*******************************************************************************
 * FUNCTIONS                                                                    *
 *******************************************************************************/

// The setup routine runs once when you press reset.
void setup() {                
  // Initialize the PWM and DIR pins as digital outputs.
  pinMode(pinPwm, OUTPUT);
  pinMode(pinDir, OUTPUT);
}



// The loop routine runs over and over again forever.
void loop() {
  
  // Control the motor according to the speed value.
  // Positive speed value = CW,
  // Negative speed value = CCW.
   iSpeed += iAcc;
   analogWrite(pinPwm, iSpeed);
    digitalWrite(pinDir, LOW);
  if (iSpeed ==100) {
    iAcc=0;
    
   
  }
  delay(10);
  
  // Increase/Decrease the speed according to the acceleration.
  
  
  // Change the acceleration sign when full speed is reached.
 
  }
  
  
  
