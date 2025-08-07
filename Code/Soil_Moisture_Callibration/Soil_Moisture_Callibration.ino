#define SOIL_SENSOR_PIN 13  // Analog pin for soil sensor

void setup() {
  Serial.begin(115200);
  Serial.println("Soil Moisture Sensor Test");
}

void loop() {
  int rawSoilValue = analogRead(SOIL_SENSOR_PIN);

  // Print raw analog value
  Serial.print("📈 Raw Value: ");
  Serial.println(rawSoilValue);

  // Convert to moisture percentage (adjust based on your calibration)
  int moisturePercent = map(rawSoilValue, 4095, 1825, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("🌱 Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  delay(2000);
}
