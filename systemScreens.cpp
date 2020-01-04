#include "systemWidgets.h"
#include "systemScreens.h"
#include "disp.h"
#include <Arduino.h>
#include <WString.h>

TEST::TEST(WIDGET * p) {
  //Serial.println("\t\t\tCREATED");
  parent = p;
  setArraySize(5);
  widgets = new WIDGET* [getArraySize()];
  for (int a = 0; a < 5; a++) {
    widgets[a] = new Line(this, "Hello my num is");

  }
  widgets[0]= new Trigger(this,"Do you like?");
   // widgets[1] = new ButtonOpener(this,"Click ME");
}

void TEST::ButtonPressRaw   (char b) {
//  Serial.println("TestUser bpr^");
  if (b == '4') {
    parent->setWidgetOver(0);
  //  println("Widget over stop");
  }

  if (!widgets[getArrayPos()]->getWidgetOver()) {
    display.clearDisplay();
    widgets[getArrayPos()]->setChecked(0);
    if (b == '2')move(0);
    if (b == '8')move(1);
    widgets[getArrayPos()]->setChecked(1);
  }

  widgets[getArrayPos()]->ButtonPress(b);
 // Serial.println("In array: " + String(getArrayPos()) + " on screen:  " + String(getScreenPos()));
  print();
}
