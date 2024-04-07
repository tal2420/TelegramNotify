#include <WiFi.h>
#include <TelegramNotify.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

const char* botToken = "YOUR_BOT_TOKEN";
const char* chatId = "YOUR_CHAT_ID";

TelegramNotify telegramNotify(botToken, chatId);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  String response = telegramNotify.sendMessage("Hello from ESP32!");
  Serial.println(response);
}

void loop() {
  // Nothing here
}