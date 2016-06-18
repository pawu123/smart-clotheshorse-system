#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define HUM_WET_THRESHOLD 80
#define HUM_DRY_THRESHOLD 79
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial HC08(8,9); //8:rx 9:tx
int flag;
void setup() {
   Serial.begin(9600); 
   HC08.begin(9600); 
   dht.begin();
}
void loop() {
      // Wait a few seconds between measurements.
    delay(2000);
    float h = dht.readHumidity();
    // Check if any reads failed and exit early (to try again).
    if (isnan(h)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    if(h > HUM_WET_THRESHOLD){
        HC08.println("W");
    }else if(h < HUM_DRY_THRESHOLD){
        HC08.println("D");
    }
}


