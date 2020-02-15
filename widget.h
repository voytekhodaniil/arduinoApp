#pragma once
#ifndef WIDGET_H
#define WIDGET_H



#include <WString.h>

class SCREEN;
class WIDGET {
  protected:

    int stringLenth = 13;
    bool Checked = 0;              //Is now cursor on widget
    bool WidgetOver = 0;           //Is widget overrwrite scren    exmp: opened new Screen
    bool WidgetStatus = 0;         //Some bool   data about widget exmp: isTriggered
    String WidgetString = "NOT_WORK((";         //Some String data about widget exmp: onWidget Text

  public:

    SCREEN* parent ;
    SCREEN* child;
    WIDGET();
    WIDGET(SCREEN* p, String s);
    virtual void WidgetOverPrint();
    void ButtonPress(char b);
     bool print(int wh);

    //Setters-Getters
    virtual void setWidgetString(String str) {
      this->WidgetString = str;
      if ( this->WidgetString.length() > stringLenth)this->WidgetString.remove(stringLenth);
    }
    String getWidgetString();
    void setWidgetStatus(bool b);
    bool getWidgetStatus();
    bool getWidgetOver();
    void setWidgetOver(bool b);
    bool getChecked();
    void setChecked(bool b);
    virtual void PrintRaw(int wh) {};
    virtual void ButtonPressRaw(char b) {};

};
#endif
