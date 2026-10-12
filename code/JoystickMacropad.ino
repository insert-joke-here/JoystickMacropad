/*
*/

#include <Keyboard.h>

const byte ROWS = 2;
const byte COLS = 3;

const byte ROW_PINS[ROWS] = {2, 3};//placeholders
const byte COL_PINS[COLS] = {4, 5, 6};//placeholders

// Keys sent to the computer
const char keymap[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'}
};

const unsigned long keyTime = 20;

bool keyState[ROWS][COLS] = {};
bool lastReading[ROWS][COLS] = {};
unsigned long lastChange[ROWS][COLS] = {};

void setup() {
  // Rows are selected one at a time
  for (byte r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  // Columns use internal pull-up resistors
  for (byte c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  scanMatrix();
}

void checkKeys() {
  for (byte r = 0; r < ROWS; r++) {
    // Select this row by pulling it LOW
    digitalWrite(rowPins[r], LOW);
    delay(0.05);

    for (byte c = 0; c < COLS; c++) {
      // LOW means the key is pressed
      bool reading = (digitalRead(colPins[c]) == LOW);

      if (reading != lastReading[r][c]) {
        lastChange[r][c] = millis();
        lastReading[r][c] = reading;
      }

      if (millis() - lastChange[r][c] >= debounceMs) {
        if (reading != keyState[r][c]) {
          keyState[r][c] = reading;

          if (reading) {
            Keyboard.press(keymap[r][c]);
          } else {
            Keyboard.release(keymap[r][c]);
          }
        }
      }
    }

    // Deselect the row
    digitalWrite(rowPins[r], HIGH);
  }
}
