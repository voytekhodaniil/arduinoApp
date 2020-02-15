#include "screen.h"
#include "widget.h"
#include "disp.h"
#include <Arduino.h>
/**/

SCREEN::SCREEN() {};


void SCREEN::setArrayPos(unsigned int pos) {
  ArrayPos = pos;
}
unsigned int SCREEN::getArrayPos() {
  return ArrayPos;
}
void SCREEN::setScreenPos(unsigned int pos) {
  ScreenPos = pos;
}
unsigned int SCREEN::getScreenPos() {
  return ScreenPos;
}
void SCREEN::setArraySize(unsigned int pos) {
  ArraySize = pos;
}
unsigned int SCREEN::getArraySize() {
  return ArraySize;
}
 void SCREEN::print() {
  display.clearDisplay();
  for (int a = 0; a < min(4,(int)ArraySize); a++)
    widgets[ArrayPos - ScreenPos + a]->print(a);
  display.display();
}
void SCREEN::move(bool v) {   // false - up, true - down
  if (!v) {
    if (ScreenPos < min(ArraySize-1,screenHeigh)) {
      ScreenPos++;
      ArrayPos++;
    }
    else {
      if (ArrayPos + 1 < ArraySize) {
        ArrayPos++;
      }
    }
  }
  else {
    if (ScreenPos > 0) {
      ScreenPos--;
      ArrayPos--;
    }
    else {
      if (ArrayPos > 0) {
        ArrayPos--;
      }
    }
  }
}
 void SCREEN::ButtonPress(char b) {
  if (widgets[getArrayPos()]->getWidgetOver()) {
    widgets[getArrayPos()]->ButtonPress(b);
    if (re)
      print();
  }
  else {
    ButtonPressRaw(b);
  }
}
