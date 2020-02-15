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
  
  //widgets[0]= new Trigger(this,"Do you like?");
   // widgets[1] = new ButtonOpener(this,"Click ME");
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
/*TextView::TextView(WIDGET * p) {
  //Serial.println("\t\t\tCREATED");
  parent = p;
  
  widgets = new WIDGET* [0];
  //widgets[0]=new TextWidget(this,"Hello, this is wery long string, that will be able to use in real life.\n I love it because you can easelly Print MUCH text that is BrIlIaNt. So I think for easy copy righting text it will be fun. Anyway it is  better than use paper. Also it will be better to use in scool and others teaching institutions.(Yeah insititutu too). GoDbYe");
  //setArraySize(ceil(widgets[0]->getWidgetString().length()/12));
  screenHeigh= 10;
}

void TextView::ButtonPressRaw   (char b) {
//  Serial.println("TestUser bpr^");
  if (b == '4') {
    parent->setWidgetOver(0);
  //  println("Widget over stop");
  }

//  if (!widgets[getArrayPos()]->getWidgetOver()) {
  //  display.clearDisplay();
 //   widgets[getArrayPos()]->setChecked(0);
 //   if (b == '2')move(0);
  //  if (b == '8')move(1);
  //  widgets[getArrayPos()]->setChecked(1);
//  }

//  widgets[getArrayPos()]->ButtonPress(b);
 // Serial.println("In array: " + String(getArrayPos()) + " on screen:  " + String(getScreenPos()));
 // print();
}*/
 
