bool door_open =  false; //light gate detects if the door is open or closed
bool door_response = false;
void Opening_door() {
    if (door_response == true && door_open == false) { 
        motor1.run(FORWARD); //will change if the motor code doesn't work like this
    }
    else if (door_open == true){
            door_response = false;
            motor1.run(RELEASE);
            delay(1000);
            motor1.run(FORWARD);
    }
    else if (door_open == false && door_response == false) {
        motor1.run(RELEASE);
    }
}
