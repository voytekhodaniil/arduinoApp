#include "screen.h"
#include "widget.h"
#include "disp.h"
#include <Arduino.h>
/**/

Screen::Screen() {};



 void Screen::Print() {
	 Serial.println(" Debug : Screen print start");
  for (int a = 0; a < min((int)ScreenSize,(int)ArraySize); a++)
    Widgets[ArrayPos - ScreenPos + a]->Print(a,(a==ScreenPos)?1:0);
	 Serial.println(" Debug : Screen print end");
}
void Screen::Move(bool vector) {   // false - up, true - down
  if (!vector) {
    if (ScreenPos < min(ArraySize-1,ScreenSize-1)) {
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
  Screen* Screen::GetScreen(char button) {
	  Serial.println(" Debug :  get screen " + String(button) + " " + String(Parent->Parent->WidgetOpened)) ;
  if (WidgetOpened) {
	 Serial.println(" Debug :  widget's screen returned" );
    return Widgets[ArrayPos]->GetScreen(button);  
	 
  }
  else {
	  bool PArentWidgetOPenedStatus =     Parent->Parent->WidgetOpened;
	  
    ButtonPress(button);
	  if (WidgetOpened)
	  {Serial.println(" Debug : clicked and widget screen returned"); return Widgets[ArrayPos]->GetScreen(button);
	  }
	  if (!Parent->Parent->WidgetOpened&&PArentWidgetOPenedStatus)
	  {
		  Parent->Parent->WidgetOpened = 0;
		  return Parent->Parent->GetScreen(' ');
	  }
	  Serial.println(" Debug :  this screen returned "+String(Parent->Parent->WidgetOpened));
    return this;
  }
}
