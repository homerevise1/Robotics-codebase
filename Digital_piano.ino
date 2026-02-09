#include "pitches.h"

#define BUZZER_PIN 8

// Button pins for each piano key
int buttonPins[13] = {
  2,   // C4
  3,   // C#4
  4,   // D4
  5,   // D#4
  6,   // E4
  7,   // F4
  9,   // F#4
  10,  // G4
  11,  // G#4
  12,  // A4
  13,  // A#4
  A0,  // B4
  A1   // C5
};

// Notes exactly as in the image
int notes[13] = {
  NOTE_C4,
  NOTE_CS4,
  NOTE_D4,
  NOTE_DS4,
  NOTE_E4,
  NOTE_F4,
  NOTE_FS4,
  NOTE_G4,
  NOTE_GS4,
  NOTE_A4,
  NOTE_AS4,
  NOTE_B4,
  NOTE_C5
};

void setup() {
  for (int i = 0; i < 13; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  bool keyPressed = false;

  for (int i = 0; i < 13; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      tone(BUZZER_PIN, notes[i]);
      keyPressed = true;
      break;   // play only one key at a time
    }
  }

  if (!keyPressed) {
    noTone(BUZZER_PIN);
  }
}
