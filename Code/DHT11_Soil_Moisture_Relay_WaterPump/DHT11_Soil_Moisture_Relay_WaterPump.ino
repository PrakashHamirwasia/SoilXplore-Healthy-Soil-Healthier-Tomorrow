#include "DHT.h"

#define DHTPIN 4         // GPIO pin where the DHT11 data line is connected
#define DHTTYPE DHT11    // DHT11 sensor
#define SOIL_SENSOR_PIN 13
#define RELAY_PIN 12     // GPIO pin connected to relay module

DHT dht(DHTPIN, DHTTYPE);
int soil;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // assuming HIGH = OFF, LOW = ON for most relay modules

  Serial.println("DHT11 and Soil Moisture Monitoring");
}

void loop() {
  delay(2000);

  // 🌡️ Read temperature
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  // 🌱 Read soil moisture
  soil = analogRead(SOIL_SENSOR_PIN);
  Serial.println(String("Analog reading is: ") + soil);

  // 💧 Map to % moisture (adjust 4095 and 1825 based on your sensor calibration)
  soil = map(soil, 4095, 1825, 0, 100);
  soil = constrain(soil, 0, 100); // just in case of out-of-range values
  Serial.println(String("Soil Moisture (%): ") + soil);

  // 🔌 Control water pump via relay
  if (soil < 50) {
    Serial.println("Soil is dry. Turning ON pump.");
    digitalWrite(RELAY_PIN, LOW);  // Turn ON pump (active LOW)
  } else {
    Serial.println("Soil is moist. Turning OFF pump.");
    digitalWrite(RELAY_PIN, HIGH); // Turn OFF pump
  }

  delay(3000);
}
