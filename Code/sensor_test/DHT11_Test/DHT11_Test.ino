#include "DHT.h"

#define DHTPIN 4         // GPIO pin connected to DHT11
#define DHTTYPE DHT11    // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT11 Temperature & Humidity Sensor Test");
}

void loop() {
  delay(2000); // Wait between readings

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("❌ Failed to read from DHT sensor!");
    return;
  }

  Serial.print("🌡️ Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("💧 Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
