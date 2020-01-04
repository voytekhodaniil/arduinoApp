#include "widget.h"
#include "screen.h"
#include <Arduino.h>

WIDGET:: WIDGET() {}
WIDGET:: WIDGET(SCREEN* p, String s) {
  parent = p;
  setWidgetString("12321");
}



void WIDGET::setWidgetStatus(bool b) {
  this->WidgetStatus = b;
}
bool WIDGET::getWidgetStatus() {
  return WidgetStatus;
}
bool WIDGET::getWidgetOver() {
  return WidgetOver;
}
bool WIDGET::getChecked() {
  return Checked;
}
String WIDGET::getWidgetString() {
  return WidgetString;
}
void WIDGET::setChecked(bool b) {
  this->Checked = b;
}
void WIDGET::WidgetOverPrint() {}
void WIDGET::setWidgetOver(bool b) {
  this->WidgetOver = b;
  parent->re = 1;
}
void WIDGET::ButtonPress(char b) {
  if (getWidgetOver()) {
    // Serial.println("SEND TO NEXT NESTED SCREEN");
    this->child->ButtonPress(b);

  }
  else ButtonPressRaw(b);
}

bool WIDGET::print(int wh) {
  if (getWidgetOver())
    WidgetOverPrint();
  else PrintRaw(wh);

}
