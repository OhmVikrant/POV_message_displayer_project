/*
  Testing Shift Register 74HC595N
  Shifting 1 from Q0 to Q7 and over again
 */
// 1 LED LIGHTS UP AT A TIME & THEN GOES OFF. NEXT LED LIGHTS UP.
int shcp = 12;  // Connect shift register clock input to pin 12
int stcp = 8; // Connect storage register latch input to pin 8
int ds   = 11;  // Connect serial data input to pin 11

int shcp_count = 0; // A counter for the shift register clock
int ds_state = 0;   // Equals to 1 if the Serial Input received 1

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(shcp, OUTPUT);
  pinMode(stcp, OUTPUT);
  pinMode(ds, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(shcp, !digitalRead(shcp)); // Tick the shift register clock
  shcp_count += 1;

  // Set all variables to the initial state
  // after the sequence is finished
  if (shcp_count == 20) {
    shcp_count = 0;
    ds_state = 0;
  }

  // Let the Shift Register Clock tick once (LOW -> HIGH, HIGH -> LOW)
  // before writing to the serial input;
  if ((shcp_count == 2) && ds_state == 0) {
    digitalWrite(ds, HIGH);
    ds_state = 1;
  } else {
    digitalWrite(ds, LOW);
  }

  // Tick Storage Register Clock if Serial Input received data
  if (ds_state == 1 && shcp_count > 2) {
    digitalWrite(stcp, !digitalRead(stcp));
  }
  delay(500);
}
