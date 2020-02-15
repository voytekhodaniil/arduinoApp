#ifndef SYS_SCREENS
#define SYS_SCREENS
#include "screen.h"


class TextView :public SCREEN{
    public:
    TextView(WIDGET * p);   
    void ButtonPressRaw   (char b);  
    void print();
    virtual void ButtonPress(char b);
    };
    #endif
