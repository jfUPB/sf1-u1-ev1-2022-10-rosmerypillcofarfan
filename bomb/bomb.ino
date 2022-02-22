#include "SSD1306Wire.h"

#define BOMB_OUT 25
#define LED_COUNT 26
#define UP_BTN 13
#define DOWN_BTN 32
#define ARM_BTN 33

// Selecciona uno según tu display.
SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_128_32);
//SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_64_48);

void task() {
  enum class BombStates {INIT, CONFIG, ARMED};
  static BombStates bombState =  BombStates::INIT;
  static uint8_t counter = 20;


  switch (bombState) {
    case BombStates::INIT: {

        // inicializar los puertos de los leds y pulsadores

        display.init();
        display.setContrast(255);
        display.clear();
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_16);

        display.clear();
        display.drawString(10, 20, String(counter));
        display.display();

        bombState = BombStates::CONFIG;

        break;
      }

    case BombStates::CONFIG: {
        break;
      }

    case BombStates::ARMED: {
        break;
      }

    default: {
        break;
      }
  }

}

void setup() {
  task();
}

void loop() {
  task();
}
