#include "esphome.h"

class GateSwitch : public Component, public Switch {
public:
  int phone = 5;
  int lock = 4;
  int led = 16;

  void setup() override {
    pinMode(phone, OUTPUT);
    pinMode(lock, OUTPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
  }

  void write_state(bool state) override {
    if (state) {

      publish_state(state);

      // ESP_LOGD("gate_switch", "write_state START!");

      digitalWrite(led, LOW);
      digitalWrite(phone, HIGH);
      delay(500);
      digitalWrite(led, HIGH);
      digitalWrite(lock, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      digitalWrite(lock, LOW);
      delay(500);
      digitalWrite(led, HIGH);
      digitalWrite(phone, LOW);

      // ESP_LOGD("gate_switch", "write_state DONE!");

      delay(500);
      publish_state(false);

    }
  }
};
