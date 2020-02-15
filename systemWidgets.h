#ifndef SYS_WIDGETS
#define SYS_WIDGETS
#include "widget.h"
#include "disp.h"

class WIDGET;
class Line: public WIDGET {
  public:

    Line() {};
    Line(SCREEN* p, String s) {
      parent = p;
      setWidgetString(s);
    };
    void PrintRaw(int wh);

};


class Trigger: public WIDGET {
  public:

    Trigger();
    Trigger(SCREEN* p, String s) {
      parent = p;
      setWidgetString(s);
      stringLenth = 9;
    }
    void ButtonPressRaw(char b);

    void PrintRaw(int wh) ;
};

class TextOpener: public WIDGET {
  public:

    TextOpener() {};

    TextOpener(SCREEN* p, String s);

    virtual void PrintRaw(int wh) ;
    void ButtonPressRaw(char b);
    virtual void WidgetOverPrint();
};

class TextWidget: public WIDGET {
  public:

    TextWidget() {};

    TextWidget(SCREEN* p, String s);

    virtual void PrintRaw(int wh) ;
    void ButtonPressRaw(char b){}
    virtual void WidgetOverPrint(){}
};
#endif
