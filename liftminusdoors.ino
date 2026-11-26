int dig1 = 8;
int dig2 = 9;
int dig3 = 2;

int MSD = 0;
int Middle = 0;
int LSD = 0;
int Position = 0;

const int buttonPin = A2; // Analog pin connected to the buttons
int buttonState = 0;      // Stores which button is pressed (0 = none)
const int inside = A1;
int insideState = 0;
// Reads the button pin and works out which button is pressed
int readButton(int pin) {
  int sensorValue = analogRead(pin);  // Read the analog value from the button pin
  delay(100);                         // Optional delay to debounce the button

  if (sensorValue >= 170 && sensorValue < 300) {
    buttonState = 1;
  }
  if (sensorValue >= 300 && sensorValue < 600) {
    buttonState = 4;
  }
  if (sensorValue >= 600) {
    buttonState = 7;
  }
  if (sensorValue <= 100) {
    buttonState = 0;
  }

 // Test print: voltage read for the pressed button
  Serial.println("desired floor is:");
  Serial.print(buttonState);  // Test print: button number
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
  if (floorReg == 4) {
    digitalWrite(14, HIGH);
    digitalWrite(15, LOW);
    Position = 2;
  }
  if (floorReg == 7) {
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
    // stop motor completely
    //insert door code
  }
  else if (requested < current) {
    Serial.print("go down");
    // MOTOR DOWN 
    //if current=destination-1
    //set motor speed to 1/2
    
  }
  else if (requested > current) {
    Serial.print("go up");
    //motor up
  }
}
int insideButtons(int a){
int insideValue = analogRead(a);
Serial.println(insideValue);
//318 510 695
  if (insideValue >= 300 && insideValue < 500) {
    insideState = 1;
  }
  if (insideValue >= 500 && insideValue < 600) {
    insideState = 4;
  }
  if (insideValue >= 600) {
    insideState = 7;
  }
  if (insideValue <= 300) {
    insideState = 0;
    return insideState;
  }
}

void Passenger(int destination,int current){       // tells lift where to go after inside buttons pressed
  if (destination == current) {
    Serial.print(" open door");
    // stop motor completely
    //insert door code
  }
  else if (destination < current) {
    Serial.print("go down");
    // MOTOR DOWN 
    //if current=destination-1
    //set motor speed to 1/2
  }
  else if (destination > current) {
    Serial.print("go up");
    //motor up
    
  }
}




void setup() {
  Serial.begin(9600);
  pinMode(dig1, INPUT);
  pinMode(dig2, INPUT);
  pinMode(dig3, INPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
}

void loop() {
  int RequestedPosition = readButton(buttonPin);
  delay(500);

  int floorReg = floorPos(dig1, dig2, dig3);
  int liftposition = setPosition(floorReg);
  liftAction(RequestedPosition,floorReg);
  int GointTo = insideButtons(inside);
  Passenger(GointTo,floorReg);
  Serial.println(floorReg);  // Test print: floor reading as a decimal
  delay(1000);
}
  // lift direction is 7
  // lift speed is 5
  // door speed 6
  //door direction is 4
  //A1
