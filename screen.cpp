#include "screen.h"




  SCREEN::SCREEN(){};

    void SCREEN::ButtonPress(char b){}
    void SCREEN::setArrayPos(unsigned int pos){ArrayPos=pos;}
    unsigned int SCREEN::getArrayPos(){return ArrayPos;}
    void SCREEN::setScreenPos(unsigned int pos){ScreenPos=pos;}
    unsigned int SCREEN::getScreenPos(){return ScreenPos;}
    void SCREEN::setArraySize(unsigned int pos){ArraySize = pos;}
    unsigned int SCREEN::getArraySize(){return ArraySize;}
    void SCREEN::print(){

    for(int a=0;a<4;a++)
      widgets[ArrayPos-ScreenPos+a]->print(a);

    }
  void SCREEN::move(bool v){    // false - up, true - down
     if(!v){
      if(ScreenPos<3){
        ScreenPos++;
        ArrayPos++;
      }
      else{
        if(ArrayPos+1<ArraySize){
          ArrayPos++;
        }
      }
     }
     else{
      if(ScreenPos>0){
        ScreenPos--;
        ArrayPos--;
      }
      else{
        if(ArrayPos>0){
          ArrayPos--;
        }
      }
     }
  }
