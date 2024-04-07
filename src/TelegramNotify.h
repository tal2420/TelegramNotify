#ifndef TelegramNotify_h
#define TelegramNotify_h

#include "Arduino.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

class TelegramNotify
{
  public:
    TelegramNotify(const char* botToken, const char* chatId);
    String sendMessage(const char* message);

  private:
    String _botToken;
    String _chatId;
};

#endif
