#define RELAY_PIN 12  // GPIO pin connected to relay module

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Turn OFF pump initially (active LOW)
  Serial.println("Relay (Water Pump) Test Started");
}

void loop() {
  Serial.println("🔌 Turning ON Pump...");
  digitalWrite(RELAY_PIN, LOW); // Turn ON pump (relay active LOW)
  delay(5000);                  // Pump ON for 5 seconds

  Serial.println("🛑 Turning OFF Pump...");
  digitalWrite(RELAY_PIN, HIGH); // Turn OFF pump
  delay(5000);                   // Pump OFF for 5 seconds
}
