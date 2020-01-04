#ifndef SYS_WIDGETS
#define SYS_WIDGETS
#include "widget.h"
#include "disp.h"

/*
  LineDisplay widget
  Element in Screen which just show text
  constructor:
      LineDisplay(SCREEN* p,String s) -  p-parent of widget; s-onWidget String
  fun:
    void print(int wh) - draw widget at wh num on string
    **  see widget.h  **
*/
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

/*
  Trigger widget
  Element in Screen which can change his status
  constructor:
    Trigger(SCREEN* p,String s) -  p-parent of widget; s-onWidget String
  fun:
  void print(int wh) - draw widget at wh num on string
  void ButtonPress(char b) - on '5' change status

  **  see widget.h  **
*/

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

class ButtonOpener: public WIDGET {
  public:

    ButtonOpener() {};

    ButtonOpener(SCREEN* p, String s);

    virtual void PrintRaw(int wh) ;
    void ButtonPressRaw(char b);
    virtual void WidgetOverPrint();
};
#endif
