# Joystick Macropad

<img width="1090" height="513" alt="cover" src="https://github.com/user-attachments/assets/89da439a-0d87-4d7b-be77-0b0f64c99743" />


This is a 2x3 macropad + a joystick. (created so i can play more pc games and also for the hackclub program half-life!)

It can be plugged straight into your computer (maybe with an adapter if you need it?) and used as a keyboard/joystick however you wish!

It uses an adafruit feather 328p (which is compatible with the arduino IDE , so you can in fact use an arduino with the same code, but you will have to edit the footprint), this was just a cheaper option. The joystick provides analog input to two analog pins on the board and a digital input for whether the joystick is pressed down. The keys use a row / column setup, with a digital GPIO pin used for each row and column, actually saving a (wow 1 whole) pin over wiring each key to a pin. The code to check a key works by setting a row to HIGH, then checking each column to see which pin is active.

schematic:
<img width="943" height="531" alt="schematic" src="https://github.com/user-attachments/assets/1b687d3c-8b77-4e3a-99ab-1b50c13ffbc9" />

the routing (also the cover image bc my computer cant load it in 3d):
<img width="1090" height="513" alt="cover" src="https://github.com/user-attachments/assets/fa362028-0a05-4711-94c3-b99ed616ab0c" />



The case for this project is available [here](https://github.com/insert-joke-here/JoyMacropadCase).
