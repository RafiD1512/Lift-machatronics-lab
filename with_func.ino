int dig1=8;
int dig2=9;
int dig3=2;

int MSD=0;
int Middle=0;
int LSD=0;

const int buttonPin = A2; // Define the analog pin connected to the button
int buttonState = 0; // Variable to store the button stat
  
int floorPos(int x, int y, int z){
  LSD=digitalRead(dig1);
  Middle=digitalRead(dig2);
  MSD=digitalRead(dig3);
  
  int floorReg=(LSD)+(Middle<<1)+(MSD<<2);
  return floorReg;
}

int CallLift(

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dig1,INPUT);
  pinMode(dig2,INPUT);
  pinMode(dig3,INPUT);
  Serial.begin(9600);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

int liftPosition = floorPos(dig1,dig2,dig3);
Serial.println(sensor);
delay(1000);
}
