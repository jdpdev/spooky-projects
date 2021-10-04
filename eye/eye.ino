#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define ROUND_EYES

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
byte x = 3;
byte y = 3;
byte targetX = 1;
byte targetY = 3;

byte minX = 1;
byte maxX = 5;
byte minY = 2;
byte maxY = 5;
unsigned long nextEyeMove = 0;

byte lid = 0;
byte lidDirection = 0;
unsigned long nextBlink = 1000;
unsigned long nextBlinkStep = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);
  matrix.setBrightness(0);
  matrix.blinkRate(0);
}

void loop() {
  stepPupil();
  stepEyelid();
  
  drawEyes();
  drawPupil(x, y);
  drawEyelid();
  matrix.writeDisplay();

  delay(125);
}

void stepPupil() {
  if (millis() < nextEyeMove) {
    return;
  }
  
  byte nextX = movePupilTo(x, targetX);
  byte nextY = movePupilTo(y, targetY);

  if (nextX == x && nextY == y) {
    targetX = random(minX, maxX);
    targetY = random(minY, maxY);

    nextEyeMove = millis() + random(1000, 5000);
  }

  x = nextX;
  y = nextY;
}

void drawEyes() {
#ifdef ROUND_EYES
  matrix.fillScreen(LED_OFF);
  matrix.fillRoundRect(0, 0, 8, 8, 3, LED_ON);
#else
  matrix.fillScreen(LED_ON);
#endif
}

byte movePupilTo(byte from, byte to) {
  if (from == to) {
    return to;
  }

  if (from > to) {
    return from - 1;
  }

  return from + 1;
}

void drawPupil(byte x, byte y) {
  matrix.fillRect(x, y, 3, 3, LED_OFF);
  matrix.drawPixel(x + 1, y + 1, LED_ON);
}

void stepEyelid() {
  if (millis() < nextBlink) return;
  //if (millis() < nextBlinkStep) return;

  if (lid >= 7) {
    lidDirection = -2;
  }

  lid += lidDirection;

  if (lid <= 0) {
    nextBlink = millis() + random(3000, 5000);
    lidDirection = 2;
    lid = 0;
  }
}

void drawEyelid() {
  if (lid == 0) return;
  
  matrix.fillRect(0, 0, 8, lid, LED_OFF);
}
