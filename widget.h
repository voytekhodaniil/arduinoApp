#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <WString.h>
class SCREEN;
class WIDGET{
   private:
  
    
    bool Checked=0;
    bool WidgetOver=0;
    bool WidgetStatus=0;
    String WidgetString;

    public:
    
    SCREEN* parent;
    WIDGET();
    
    virtual void WidgetOverPrint();
    virtual void ButtonPress(char b);   
    virtual void print(int wh);
    void setWidgetString(String str);
    String getWidgetString();
    void setWidgetStatus(bool b);
    bool getWidgetStatus();
    bool getWidgetOver();
    bool getChecked();
    void setChecked(bool b);
   
  };
#endif
