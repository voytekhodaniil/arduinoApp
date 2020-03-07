#ifndef SYS_SCREENS
#define SYS_SCREENS
#include "screen.h"


class TextView :public Screen{
    public:
    TextView(Widget * parent);   
    void ButtonPress  (char b);  
    void Print();
    };
    #endif
