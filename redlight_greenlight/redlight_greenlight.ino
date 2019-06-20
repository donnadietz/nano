// Donna Dietz
// June 2019


// Need: Breadboard, Nano, Cable, Computer.
// Two LEDs, resistor.
// Connect 220 resistor from Ground (GND) to empty column. 
// To the same empty column, connect the red and green LEDs, short side.
// Connect long sides of LEDs to D2 (red), D3 (green)
// Connect speaker between pin8 and Ground (Leave out if silence is desired!)
// To power away from computer:
// 9V battery: Connect red to VIN and black to Ground (GND)

 
void setup()
{
  int blinks;
  
  pinMode(2,OUTPUT);  //Lamp  (Red)
  digitalWrite(2,HIGH); //Turn it on
  pinMode(3,OUTPUT);  // Other lamp (Green)
  digitalWrite(3,HIGH);  //Turn it on as well
  tone(8, 500, 3000);
  delay(3000);

  randomSeed(analogRead(0));
  blinks = random(3,10);
  
  for (int i=0; i < blinks; i++){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  delay(300);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(800);
  }


}


void loop(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  int nextLight;  
  nextLight = random(2,4);

  if (nextLight==2)
  {
    tone(8,250,600);
  }
  else
  {
    tone(8,1000,600);
  }
  for (int i=0; i < 3 ; i++){
    digitalWrite(nextLight, HIGH);
    delay(50);
    digitalWrite(nextLight, LOW);
    delay(50);
    }
   
   int waitTime;  
   waitTime=random(15,75);
   digitalWrite(nextLight, HIGH);
   delay(waitTime*100); 
  
  delay(10);                  // Slight pause so that we don't overwhelm the serial interface
}
