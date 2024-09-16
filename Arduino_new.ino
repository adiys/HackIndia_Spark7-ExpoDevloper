#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Server URLs
const char* relay1URL = "http://your-server-ip:3000/toggleRelay1";
const char* relay2URL = "http://your-server-ip:3000/toggleRelay2";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("Connected to Wi-Fi");
}

void loop() {
  HTTPClient http;

  // Toggle Relay 1
  http.begin(relay1URL);
  int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("Relay 1 Response: " + payload);
  } else {
    Serial.println("Error: " + String(httpCode));
  }
  http.end();

  delay(10000); // Wait 10 seconds

  // Toggle Relay 2
  http.begin(relay2URL);
  httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("Relay 2 Response: " + payload);
  } else {
    Serial.println("Error: " + String(httpCode));
  }
  http.end();

  delay(10000); // Wait 10 seconds
}
