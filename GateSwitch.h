#include "esphome.h"

// esp32
#define LED_ON HIGH
#define LED_OFF LOW
// // esp8266
// #define LED_ON LOW
// #define LED_OFF HIGH

class GateSwitch : public Component, public Switch {
public:
  // esp32
  int phone = 25;
  int lock = 26;
  int led = 2;
  // esp8266
  // int phone = 5;
  // int lock = 4;
  // int led = 16;


  void setup() override {
    pinMode(phone, OUTPUT);
    pinMode(lock, OUTPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, LED_OFF);
  }

  void write_state(bool state) override {
    if (state) {

      publish_state(state);

      // ESP_LOGD("gate_switch", "write_state START!");

      digitalWrite(led, LED_ON);
      digitalWrite(phone, HIGH);
      delay(600);
      digitalWrite(led, LED_OFF);
      digitalWrite(lock, HIGH);
      delay(250);
      digitalWrite(led, LED_ON);
      digitalWrite(lock, LOW);
      delay(1250);
      digitalWrite(led, LED_OFF);
      digitalWrite(phone, LOW);

      // ESP_LOGD("gate_switch", "write_state DONE!");

      delay(500);
      publish_state(false);

    }
  }
};
