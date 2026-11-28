const int DoorDir = 4; // Direction
const int DoorPwm = 6; // Speed              
const int DoorOpenSensor = A3;     
const int DoorClosedSensor = A4;
unsigned long doorTimer = 0; // this is for milli() 
int doorState = 3;           // 0=closed  1=opening  2=open  3=closing, kept it at 3 so its closes when its powered on and then whenever goes to a floor itll stay open once i do the rest of the code


void doorControl(){
int Open = analogRead(DoorOpenSensor);
int Closed = analogRead(DoorClosedSensor);

if (doorState==1){ // opening
  digitalWrite(DoorDir, HIGH);
    analogWrite(DoorPwm, 255);
    if ((Open > 150 && Open < 170)  { // used cuz delay() stops all programs from running in the duration, including any buttons pressed during the delay, while 
// milli doesnt, it allows background processes to still run 
      analogWrite(DoorPwm, 0);
      doorState=2;
    }
  }

  if (doorState==2){ // open
  analogWrite(DoorPwm,0);
  }

  if (doorState==3){ //closing
   digitalWrite(DoorDir, LOW);
    analogWrite(DoorPwm, 255);
    if ((Closed > 150 && Closed < 170)  {
      analogWrite(DoorPwm, 0);
      doorState = 0;
    }
  }
}
