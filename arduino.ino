#include <ESP8266WiFi.h>
#include <Web3.h>
#include <ArduinoJson.h>

// WiFi credentials
const char* ssid = "Abhay";         // Replace with your WiFi SSID
const char* password = "TheTechBestAb"; // Replace with your WiFi password

// Web3 provider and smart contract details
const char* provider_url = "http://127.0.0.1:8545"; // URL of the Web3 provider (e.g., Hardhat local network)
const char* contract_address = "0x5FbDB2315678afecb367f032d93F642f64180aa3"; // Replace with your smart contract address

Web3 web3(provider_url); // Create a Web3 object to interact with the blockchain
String relayEvent = "0xd44f21f38e3fa8a907a0f65bf3458e8d743d84c2d4ad8f4539e1c0b2170411b2b"; // Keccak-256 hash of the RelayToggled event signature

// Relay pins configuration
int relay1Pin = D1; // GPIO pin connected to Relay 1
int relay2Pin = D2; // GPIO pin connected to Relay 2

void setup() {
  Serial.begin(115200); // Start serial communication for debugging
  pinMode(relay1Pin, OUTPUT); // Set Relay 1 pin as output
  pinMode(relay2Pin, OUTPUT); // Set Relay 2 pin as output
  
  // Connect to WiFi
  WiFi.begin(ssid, password); // Start WiFi connection
  while (WiFi.status() != WL_CONNECTED) { // Wait until connected
    delay(500); // Wait half a second before checking again
    Serial.println("Connecting to WiFi..."); // Print connection status
  }
  Serial.println("Connected to WiFi"); // Print when connected

  // Initialize relays
  digitalWrite(relay1Pin, LOW); // Set Relay 1 to OFF (LOW)
  digitalWrite(relay2Pin, LOW); // Set Relay 2 to OFF (LOW)
}

void loop() {
  // Retrieve and print logs from the smart contract
  String result = web3.getLogs(contract_address, relayEvent); // Get logs for the specific event
  Serial.println(result); // Print the result to the serial monitor

  // Parse the JSON result
  StaticJsonDocument<1024> doc; // Create a JSON document to hold the parsed data
  deserializeJson(doc, result); // Deserialize the JSON result into the document
  
  // Process each log entry
  for (JsonObject log : doc["result"].as<JsonArray>()) { // Iterate through each log entry
    int relayNumber = log["topics"][1]; // Extract relay number from the log entry
    bool newState = log["topics"][2]; // Extract new state from the log entry

    // Update relay state based on the log entry
    if (relayNumber == 1) {
      digitalWrite(relay1Pin, newState ? HIGH : LOW); // Set Relay 1 state
    } else if (relayNumber == 2) {
      digitalWrite(relay2Pin, newState ? HIGH : LOW); // Set Relay 2 state
    }
  }

  delay(5000); // Wait for 5 seconds before checking for new logs again
}
