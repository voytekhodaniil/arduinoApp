#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <WString.h>
class SCREEN;
class WIDGET{
   protected:
  
    
    bool Checked=0;                //Is now cursor on widget 
    bool WidgetOver=0;             //Is widget overrwrite scren    exmp: opened new Screen 
    bool WidgetStatus=0;           //Some bool   data about widget exmp: isTriggered
    String WidgetString;           //Some String data about widget exmp: onWidget Text

    public:
    
    SCREEN* parent;
    WIDGET();
    
    virtual void WidgetOverPrint();
    virtual void ButtonPress(char b);   
    virtual void print(int wh);
    
    //Setters-Getters
    virtual void setWidgetString(String str){this->WidgetString = str;}
    String getWidgetString();
    void setWidgetStatus(bool b);
    bool getWidgetStatus();
    bool getWidgetOver();
    bool getChecked();
    void setChecked(bool b);
   
  };
#endif
