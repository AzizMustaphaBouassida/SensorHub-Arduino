
#include <Wire.h>
// #include <BH1750.h>
#include <DHT.h>


const int pin_mouvement   = A2;
const int pin_vibration   = A3;
const int pin_temperature = 2;
const int pin_gaz         = A7;

// BH1750 lightMeter;

DHT dht(pin_temperature, DHT22);

void setup() {
  Serial.begin(19200);
  while(!Serial);
  // Wire.begin();
  // lightMeter.begin();
  dht.begin();
  pinMode(pin_mouvement, INPUT);
  pinMode(pin_vibration, INPUT);
  pinMode(pin_temperature, INPUT);
  pinMode(pin_gaz, INPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  char humidity_str[10];
  char temperature_str[10];
  dtostrf(temperature, 6, 2, temperature_str); 
  dtostrf(humidity, 6, 2, humidity_str); 
  //float lux = lightMeter.readLightLevel();


  Serial.print("{\"mouvement\":");
  Serial.print(analogRead(pin_mouvement));
  Serial.print(",\"vibration\":");
  Serial.print(analogRead(pin_vibration));
  Serial.print(",\"temperature\":");
  Serial.print((!isnan(temperature) ? temperature_str : "null"));
  Serial.print(",\"humidity\":");
  Serial.print((!isnan(humidity) ? humidity_str : "null"));
  Serial.print(",\"gaz\":");
  Serial.print(analogRead(pin_gaz));
  // Serial.print(",\"light\":");
  // Serial.print(lux);
  Serial.println("}");
  delay(50);
}
