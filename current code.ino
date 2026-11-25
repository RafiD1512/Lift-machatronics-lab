int dig2 = 9;
int dig3 = 2;

int MSD = 0;
int Middle = 0;
int LSD = 0;
int Position = 0;

const int buttonPin = A2; // Analog pin connected to the buttons
int buttonState = 0;      // Stores which button is pressed (0 = none)

bool door_open =  false; //light gate detects if the door is open or closed
bool door_response = false;


// Reads the button pin and works out which button is pressed
int readButton(int pin) {
  int sensorValue = analogRead(pin);  // Read the analog value from the button pin
  delay(100);                         // Optional delay to debounce the button

  if (sensorValue >= 170 && sensorValue < 300) {
    buttonState = 1;
  }
  if (sensorValue >= 300 && sensorValue < 600) {
    buttonState = 2;
  }
  if (sensorValue >= 600) {
    buttonState = 3;
  }
  if (sensorValue <= 100) {
    buttonState = 0;
  }

  Serial.println(sensorValue);  // Test print: voltage read for the pressed button
  Serial.println(buttonState);  // Test print: button number
  return buttonState;
}

// Reads the three floor sensor pins and turns the binary into a decimal number
int floorPos(int x, int y, int z) {
  LSD = digitalRead(x);
  Middle = digitalRead(y);
  MSD = digitalRead(z);

  int floorReg = (LSD) + (Middle << 1) + (MSD << 2);
  return floorReg;
}

// Sets the outputs and the lift position (1, 2 or 3) from the floor reading
int setPosition(int floorReg) {
  if (floorReg == 1) {
    digitalWrite(14, LOW);
    digitalWrite(15, HIGH);
    Position = 1;
  }
  else if (floorReg == 4) {
    digitalWrite(14, HIGH);
    digitalWrite(15, LOW);
    Position = 2;
  }
  else if (floorReg == 7) {
    digitalWrite(14, HIGH);
    digitalWrite(15, HIGH);
    Position = 3;
  }
  return Position;
}

// Compares the requested floor with the lift position and prints what to do
void liftAction(int requested, int current) {
  if (requested == current) {
    Serial.print(" open door");
  }
  else if (requested < current) {
    Serial.print("go down");
  }
  else if (requested > current) {
    Serial.print("go up");
  }
}
