# TelegramNotify
The TelegramNotify library simplifies the process of sending notifications from Arduino and ESP boards using the Telegram Bot API. With easy-to-use functions, developers can integrate Telegram notifications seamlessly into their projects, enabling real-time alerts, status updates, and more. Whether it's monitoring sensor data, receiving alerts from IoT devices, or interacting with users via Telegram, this library provides a versatile solution for communication with minimal setup required.

## Getting started

### Creating telegram Bot
Before you can start working with this library, you will need to create Telegram bot. To do that, follow the following instructions

1. Create new telegram bot and get the token
    Open [Telegram messenger](https://web.telegram.org/), sign in to your account or create a new one.

    Enter @Botfather in the search tab and choose this bot (Official Telegram bots have a blue checkmark beside their name.)

    [![@Botfather](https://github.com/t0mer/voicy/blob/main/screenshots/scr1-min.png?raw=true "@Botfather")](https://github.com/t0mer/voicy/blob/main/screenshots/scr1-min.png?raw=true "@Botfather")

    Click “Start” to activate BotFather bot.

    [![@start](https://github.com/t0mer/voicy/blob/main/screenshots/scr2-min.png?raw=true "@start")](https://github.com/t0mer/voicy/blob/main/screenshots/scr1-min.png?raw=true "@start")

    In response, you receive a list of commands to manage bots.
    Choose or type the /newbot command and send it.

    [![@newbot](https://github.com/t0mer/voicy/blob/main/screenshots/scr3-min.png?raw=true "@newbot")](https://github.com/t0mer/voicy/blob/main/screenshots/scr3-min.png?raw=true "@newbot")

    Choose a name for your bot — your subscribers will see it in the conversation. And choose a username for your bot — the bot can be found by its username in searches. The username must be unique and end with the word “bot.”

    [![@username](https://github.com/t0mer/voicy/blob/main/screenshots/scr4-min.png?raw=true "@username")](https://github.com/t0mer/voicy/blob/main/screenshots/scr4-min.png?raw=true "@username")

    After you choose a suitable name for your bot — the bot is created. You will receive a message with a link to your bot t.me/<bot_username>, recommendations to set up a profile picture, description, and a list of commands to manage your new bot.

    [![@bot_username](https://github.com/t0mer/voicy/blob/main/screenshots/scr5-min.png?raw=true "@bot_username")](https://github.com/t0mer/voicy/blob/main/screenshots/scr5-min.png?raw=true "@bot_username")


### Install the library

To use the TelegramNotify library in your Arduino projects, follow these steps:

1. Download the latest release of the TelegramNotify library from the [GitHub releases page](https://github.com/t0mer/TelegramNotify/releases).
2. Extract the downloaded ZIP file.
3. Move the extracted folder to the `libraries` directory in your Arduino sketchbook.
4. Restart the Arduino IDE.


## Usage
```c
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
```
Make sure to replace *botToken* and *chatId* with your own.