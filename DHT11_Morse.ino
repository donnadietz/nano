//www.elegoo.com
//2018.10.25 (code modified 2019.7.29 by Edwin Robinson for morse code temperature readout)
//speaker wires to: pin D8 and ground
//DHT + to 5v, - to GND
//OUT to pin D2
//9v battery red wire to VIN(Voltage IN), black wire to GND(GrouND).
//If you want humidity, please use the Serial Monitor. the next update will have humidity in morse readout as well as temperature.




#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );



/*
 * Initialize the serial port.
 */
void setup( )
{
  Serial.begin( 9600);
}


/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}

//tone
void beep(int timeofbeep){
tone(8,700);delay(timeofbeep);
noTone(8);
delay(100);}

//morse code
void dah(){beep(300);}
void dit(){beep(100);}

//Now here comes the CW number generator

void morsenumber(int n){if(n!=0){int b=5;if(n>5){n=n-5;
while(n){n--;b--;dah();}
while(b){b--;dit();}
}else{
while(n){n--;b--;dit();}
while(b){b--;dah();}
}}else{dah();dah();dah();dah();dah();}delay(300);}
/*
 * Main program loop.
 */
void loop( )
{
  float temperature;
  float humidity;
  int d1,d2,d3;
  

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " ); 
    temperature = temperature*9/5 +32;
   
    Serial.print( temperature, 0);
    Serial.print( " deg. , H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );

    d1=int(floor(temperature/100));
    if(d1)
      Serial.print(d1);

    temperature=temperature-100*d1;
    d2=int(floor(temperature/10));
    if (d2 or d1)
     {Serial.print(d2);}

    temperature=temperature-10*d2;
    d3=int(floor(temperature));
    Serial.print(d3);

    Serial.println(" degrees!");
    Serial.println(d1);
    Serial.println(d2);
    Serial.println(d3);
 
    if(d1!=0){morsenumber(d1);}
    morsenumber(d2);
    morsenumber(d3);
  delay(3000);}
}
