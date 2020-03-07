#include "systemWidgets.h"
#include "systemScreens.h"
#include "disp.h"
#include <Arduino.h>
#include <WString.h>


TextView::TextView(Widget * parent) {
  Parent = parent;
  ArraySize=1;
  Widgets = new Widget* [ArraySize];
    
    Widgets[0] = new TextWidget(this, "Hello, this is wery long string, that will be able to use in real life.\n I love it because you can easelly Print MUCH text that is BrIlIaNt. So I think for easy copy righting text it will be fun. Anyway it is  better than use paper. Also it will be better to use in scool and others teaching institutions.(Yeah insititutu too). GoDbYe Hello, this is wery long string, that will be able to use in real life.\n I love it because you can easelly Print MUCH text that is BrIlIaNt. So I think for easy copy righting text it will be fun. Anyway it is  better than use paper. Also it will be better to use in scool and others teaching institutions.(Yeah insititutu too). GoDbYe");
    ScreenSize= 8;
    ArraySize = Widgets[0]->Data[0].length()/20;
  
  
}

void TextView::ButtonPress   (char button) {
	Serial.println(" Debug : TextView buttonpress start   " + String(Parent->Parent->WidgetOpened ));

  if (button == '4') {
    Parent->Parent->WidgetOpened = 0;
	  
	  return;}
 
 
	if (button == '2'){Move(0); Widgets[0]->ButtonPress(button); }
	else if (button == '8'){Move(1); Widgets[0]->ButtonPress(button); }


 

}
    void TextView::Print(){
      Widgets[0]->Print(ArrayPos*10+ScreenPos,0);
    }
