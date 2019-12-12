#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 


#define blueLED 3
#define redLED 4
dht DHT;
void setup()
{Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
   delay(1000);//Wa
}

void loop()
{ DHT.read11(dht_apin);
  /*int reading = analogRead(dht_apin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 10 ;*/
  

   
   
    
    /*Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print(" %  ");*/
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println(" C  ");   

  if ( DHT.temperature>= 21) {
    
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
  }
 /*if (DHT.temperature <= 22 )/*&& DHT.temperature <=30) 
   {
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
 }*/
  /*else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
  }*/

  delay(3000);
}
