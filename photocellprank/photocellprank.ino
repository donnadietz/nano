// Donna Dietz
// June 2019
// Adjusted from code found at adafruit.com

//Connections: pin11 to 220 resistor to LED (long side) to 10K reisitor to photocell to 5v power.
//at join between photocell and 10K resistor, connect to A0
//at join between short side of LED and 10K, go to ground.
//speaker from 8 to Ground

/* Photocell simple testing sketch. 
https://learn.adafruit.com/photocells/arduino-code 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
Connect LED from pin 11 through a resistor to ground 
For more information see http://learn.adafruit.com/photocells */
 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading

  //photocellReading can range from 0 to 1023.
  //analogWrite uses 0 to 255
  
  
  if (photocellReading > 200)
   {
    //analogWrite(LEDpin, 0);  // turn off
    delay(10);
   }
  else
  {
    //analogWrite(LEDpin, 250); // turn on
    if (random(0,22) > 17){
      tone(8,1760,5);
    }
    else{
      //tone(8,440,5);
    }
    delay(100);
  }
 
}
