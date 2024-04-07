#include "TelegramNotify.h"

TelegramNotify::TelegramNotify(const char* botToken, const char* chatId)
{
  _botToken = String(botToken);
  _chatId = String(chatId);
}

String TelegramNotify::sendMessage(const char* message)
{
  HTTPClient http;
  http.begin("https://api.telegram.org/bot" + _botToken + "/sendMessage");
  http.addHeader("Content-Type", "application/json");

  DynamicJsonDocument doc(1024);
  doc["chat_id"] = _chatId;
  doc["text"] = String(message);
  
  String requestBody;
  serializeJson(doc, requestBody);

  int httpResponseCode = http.POST(requestBody);
  String response;

  if (httpResponseCode > 0) {
    response = http.getString();
  } else {
    response = "Error on sending POST: " + String(httpResponseCode);
  }

  http.end();
  return response;
}
