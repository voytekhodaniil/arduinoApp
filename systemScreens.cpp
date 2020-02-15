#include "systemWidgets.h"
#include "systemScreens.h"
#include "disp.h"
#include <Arduino.h>
#include <WString.h>


TextView::TextView(WIDGET * p) {
  //Serial.println("\t\t\tCREATED");
  parent = p;
  setArraySize(1);
  widgets = new WIDGET* [getArraySize()];
    
    widgets[0] = new TextWidget(this, "Hello, this is wery long string, that will be able to use in real life.\n I love it because you can easelly Print MUCH text that is BrIlIaNt. So I think for easy copy righting text it will be fun. Anyway it is  better than use paper. Also it will be better to use in scool and others teaching institutions.(Yeah insititutu too). GoDbYe Hello, this is wery long string, that will be able to use in real life.\n I love it because you can easelly Print MUCH text that is BrIlIaNt. So I think for easy copy righting text it will be fun. Anyway it is  better than use paper. Also it will be better to use in scool and others teaching institutions.(Yeah insititutu too). GoDbYe");
    screenHeigh= 8;
    setArraySize(widgets[0]->getWidgetString().length()/20);
  
  
}

void TextView::ButtonPressRaw   (char b) {

  if (b == '4') 
    parent->setWidgetOver(0);
 
 
    display.clearDisplay();

    if (b == '2')move(0);
    if (b == '8')move(1);
    



  widgets[0]->ButtonPress(b);
  print();
}
    void TextView::print(){
      widgets[0]->print(getArrayPos()*10+getScreenPos());
    }

void TextView::ButtonPress(char b) {
ButtonPressRaw(b);
}
