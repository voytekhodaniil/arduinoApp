#ifndef SCREEN_H
#define SCREEN_H
#include <WString.h>

class WIDGET;
class SCREEN{
 protected:
  
  WIDGET* parent;
  String attr;
  bool check;
  unsigned int ArrayPos=0;  // Position of current widget in array index
  unsigned int ScreenPos=0;    // Position of current widget on screen pos
  unsigned int ArraySize=0;
  unsigned int screenHeigh =3;
  
 public:
 bool re=0;
  WIDGET** widgets;
  SCREEN();
  SCREEN(WIDGET* p);
 virtual  void ButtonPress(char b);
  virtual void ButtonPressRaw(char b){};
  virtual void print();  
  void move(bool v);
  
  void setArrayPos(unsigned int pos);
  unsigned int getArrayPos();
  void setScreenPos(unsigned int pos);
  unsigned int getScreenPos();
  void setArraySize(unsigned int pos);
  unsigned int getArraySize();
  };
  
  #endif
