// Donna Dietz
// June 2019

// Wire the speaker between D8 and GND (ground). 
// If using 9V, wire red to VIN and black to GND (there are two GND pins). 

int myTones[]={220, 262, 294, 349, 392};

void setup(){
   // I'm not putting anything here!
}

void loop(){
    randomSeed(analogRead(0));
    int tonetoring = random(0,5);
    int mult=random(1,5);
    tone(8, mult*myTones[tonetoring], 700);
    delay(random(100,2000));
}
