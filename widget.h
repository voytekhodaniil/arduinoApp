#pragma once
#ifndef WIDGET_H
#define WIDGET_H



#include <WString.h>

class Screen;
class Widget {
                     

  public:
      int DataSize =0 ;                       

     String* Data;   
    Screen* Parent ;
    Screen* Child;
    
    Widget();
    Widget(Screen* parent, String string);
    virtual Screen* GetScreen(char button);
    virtual void Print(int pos,bool AtCursor){};
    virtual void ButtonPress(char button){};


};
#endif
