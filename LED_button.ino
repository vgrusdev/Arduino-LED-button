/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
int ledOn = 11;
int ledOff = 12;
int buttonPin = 10;
int lastButton;
int buttonState;

void pressButton (int Pin) {
  digitalWrite (Pin, LOW);
  delay (150);
  digitalWrite (Pin, HIGH);
  delay (150);
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledOn, OUTPUT);     
  pinMode(ledOff, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  digitalWrite(ledOn, HIGH);
  digitalWrite(ledOff, HIGH);
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    pressButton(ledOff);
  } else {
    pressButton(ledOn);
  }
  lastButton = buttonState;
  
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButton) {
    if (buttonState == HIGH) {
      pressButton(ledOff);
    } else {
      pressButton(ledOn);
    }
    lastButton = buttonState;
    delay(300);
  }
  delay(10);
}
