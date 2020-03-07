#ifndef SYS_WIDGETS
#define SYS_WIDGETS
#include "widget.h"
#include "disp.h"

class Widget;
class Line: public Widget {
  public:

    Line(Screen* parent, String string) : Widget(parent,string) {};
    void Print(int position,bool AtCursor);

};


class Trigger: public Widget {
  public:

	Trigger(Screen* parent, String string) ;
 Trigger(); 
    void ButtonPress(char button);

    void Print(int position,bool AtCursor) ;
};

class TextOpener: public Widget {
  public:

	TextOpener(Screen* parent, String string);

    virtual void Print(int position,bool AtCursor) ;
    void ButtonPress(char button);
    virtual void WidgetOverPrint();
};

class TextWidget: public Widget {
  public:

	TextWidget(Screen* parent, String string)
		: Widget(parent, string) {};

    virtual void Print(int position,bool AtCursor);
    void ButtonPress(char buton){}
};
#endif
