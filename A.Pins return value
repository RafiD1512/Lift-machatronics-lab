int Open=A3;
int Close=A4;
int Door=A0;
int Car=A1;   //floor call buttons, inside lift
int Lift=A2;  //Landing call buttons, outside up/down

void setup() {
pinMode(Open,INPUT);
pinMode(Close,INPUT);
pinMode(Door,INPUT);
pinMode(Car,INPUT);
pinMode(Lift,INPUT);
Serial.begin(9600);
}
void loop() {
int openState=analogRead(Open);
int closeState=analogRead(Close);
int doorState=analogRead(Door);
int carState=analogRead(Car);
int liftState=analogRead(Lift);

Serial.print("Door: ");
Serial.print(doorState);
Serial.print("  Car: ");
Serial.print(carState);
Serial.print("  Lift: ");
Serial.print(liftState);
Serial.print("  Open: ");
Serial.print(openState);
Serial.print("  Close: ");
Serial.println(closeState);
delay(500);
}
