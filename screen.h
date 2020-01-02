#ifndef SCREEN_H
#define SCREEN_H
#include <WString.h>
#include "widget.h" 
class SCREEN{
 private:
  
  SCREEN* parent;
  String attr;
  bool check;
  unsigned int ArrayPos=0;  // Position of current widget in array index
  unsigned int ScreenPos=0;    // Position of current widget on screen pos
  unsigned int ArraySize=0;
  
  
 public:
  WIDGET** widgets;
  SCREEN();
  
  virtual void ButtonPress(char b);
  void print();  //error may
  void move(bool v);
  
  void setArrayPos(unsigned int pos);
  unsigned int getArrayPos();
  void setScreenPos(unsigned int pos);
  unsigned int getScreenPos();
  void setArraySize(unsigned int pos);
  unsigned int getArraySize();
  };
  
  #endif
