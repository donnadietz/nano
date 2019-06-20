// Donna Dietz
// June 2019

// Wire the speaker between D8 and GND (ground). 
// If using 9V, wire red to VIN and black to GND (there are two GND pins). 

# define C  262
# define F  349
# define G  392
# define A  440


int melody[]{
A, G, F, C, 0,
C, G, A, F, 0,
A, F, G, C, 0,
C, G, A, F, 0
};

int duration = 1000;

void setup(){
  for (int thisNote = 0; thisNote < 20; thisNote++) //20 for full song
  {
  // pin8 output the notes
  tone(8, melody[thisNote], 2000);
  delay(duration);
  }
  randomSeed(analogRead(0));
  int chimes = random(1,13);
  for (int i=0; i<chimes; i++){
    tone(8, C, 2000);
    delay(3000);
  
  }
}

void loop(){
  // I'm not putting anything here!
}
