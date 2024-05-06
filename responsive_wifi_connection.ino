#include <WiFi.h>

const char* ssid = "OPPO A1K";  //"Your Network SSID";
const char* password =  "66769712"; //"Your Network Password";
const int maxAttempts = 30;  // Maximum number of connection attempts
const int delayBetweenAttempts = 1000; // Delay between connection attempts in milliseconds
const int ledwifi = 15;

void setup() {
  Serial.begin(115200);
  pinMode(ledwifi, OUTPUT);
  digitalWrite(ledwifi, LOW);

  // Connect to Wi-Fi
  connectToWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connection lost! Reconnecting...");
    digitalWrite(ledwifi, LOW); // Turn off LED indicating WiFi connection
    connectToWiFi(); // Attempt to reconnect
  }
  // Your code logic here
}

void connectToWiFi() {
  Serial.println();
  Serial.print("Connecting to Wi-Fi network: ");
  Serial.println(ssid);

  int attemptCount = 0;

  while (WiFi.status() != WL_CONNECTED && attemptCount < maxAttempts) {
    WiFi.begin(ssid, password);
    delay(delayBetweenAttempts);
    attemptCount++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("Wi-Fi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(ledwifi, HIGH); // Turn on LED indicating WiFi connection
  } else {
    Serial.println("");
    Serial.println("Failed to connect to Wi-Fi. Please check your credentials or network.");
    digitalWrite(ledwifi, LOW); // Turn off LED indicating WiFi connection
  }
}
