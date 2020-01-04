#ifndef SYS_SCREENS
#define SYS_SCREENS
#include "screen.h"


class TEST :public SCREEN{
    public:
    TEST(WIDGET * p);   
    void ButtonPressRaw   (char b);  
    };
    #endif
