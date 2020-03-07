#ifndef SCREEN_H
#define SCREEN_H
#include <WString.h>

class Widget;
class Screen{
 protected:
  
  Widget* Parent;
  
  
  
 public:
 
unsigned int ArrayPos=0;  // Position of current widget in array index
  unsigned int ScreenPos=0;    // Position of current widget on screen pos
  unsigned int ArraySize=0;
  unsigned int ScreenSize =4;


 
bool WidgetOpened=0;
  Widget** Widgets;
  Screen();
  Screen(Widget* parent);

  virtual void Print();  
  void Move(bool vector);
  virtual Screen* GetScreen(char button) ;
  virtual void ButtonPress(char button){};
  };
  
  #endif
