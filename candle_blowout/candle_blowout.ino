// Donna Dietz
// June 2019
// Adjusted from code found at Elegoo

// Plays Happy Birthday. Makes you blow out the candle (or make other noises).
// Need: Breadboard, Nano, Cable, Computer.
// LED, resistor, speaker, sound sensor.
// Led13 as well as pin2 are the candle(s).  ((Short side of LED towards ground.)
// Speaker is on pin8  (Connect to D8 and GND.)
// Outputs from "blue" sound sensor are: Ground to Ground. VCC to 5V. OUT to A0.
// 220 resistor from D2 to any unused zone on the other side of the breadboard (like A5)
// then from there to GND.

// www.elegoo.com
// 2018.10.24

#include "pitches.h"

int  sensorAnalogPin = A0;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
//int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  Led13 = 13;              // Define LED port; this is the LED built in to the Arduino (labled L)
                              
int stillLit=1;  //Candle/s may be lit.
int countBlows=0;
                              
// notes in the melody:
int melody[] = {
  NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5,
  NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5,
  NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_F5, NOTE_E5, NOTE_D5, 
  NOTE_AS5, 0, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_F5 
  };
int duration[] = {
  325, 75, 100, 500,500,500,1000,325,75, 100,500,500,500,1000, 200,50,250, 500, 500, 500, 500, 3000, 500, 50, 350, 800, 800, 1000, 2500
};  


void setup()
{
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  //pinMode(sensorDigitalPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(Led13,OUTPUT);            // Define LED13 as an output port  (NOT using the digital cutoff info!)
  pinMode(2,OUTPUT);  //Candle
  digitalWrite(2,HIGH); //Turn it on

  for (int thisNote = 0; thisNote < 29; thisNote++) //29 for full song
  {
  // pin8 output the voice
  tone(8, melody[thisNote], 2000);
  delay(duration[thisNote]);
  }
}

void loop(){
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0
  Serial.println(analogValue); // Send the analog value to the serial transmit interface
  if(analogValue<70 && stillLit)      // When the Sound Sensor hears very little sound, ignore.
  {
    digitalWrite(Led13,HIGH);
    digitalWrite(2,HIGH);
  }
  else if(analogValue<1400 && stillLit)  // When Sound Sensor hears some sound, flicker.
  {
    digitalWrite(Led13,LOW);
    digitalWrite(2,LOW);
    countBlows=countBlows+1;
    if (countBlows > 125){
      stillLit=0;
    }
    
  }
  else                                 // When Sound Sensor hears a louder sound, blow out.
  {                                    // The problem is with the "blue" sound sensor,
    stillLit=0;                        // it's too sensitive, so just count to 125.
    digitalWrite(2,LOW);
    digitalWrite(Led13,LOW);
  }
  
  delay(10);                  // Slight pause so that we don't overwhelm the serial interface
}
