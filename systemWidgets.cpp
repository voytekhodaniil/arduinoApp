#include "screen.h"
#include "widget.h"
#include "disp.h"
/*
 *Line widget
 *Element in Screen wich
 *
 *
*/
 
  class LineDisplay: public WIDGET{
    public:
    
    LineDisplay(){};
    LineDisplay(SCREEN* p,String s){
      parent = p;
      setWidgetString(s);
      }
      void print(int wh)  {
        display.setCursor(2, wh*16+2);
        if(getChecked()){
          display.drawRect(0, wh*16, 128, 15, WHITE);
          display.setTextColor(WHITE);
        }
        else{
          display.fillRect(0, wh*16, 128, 15, WHITE);
          display.setTextColor(BLACK);
        }
        display.print(getWidgetString());
      }
    };
    class Trigger: public WIDGET{
    public:
    
    Trigger(){};
    Trigger(SCREEN* p,String s){
      parent = p;
      setWidgetString(s);
      }
      void ButtonPress(char b){
        if(b=='5')
           setWidgetStatus(!getWidgetStatus());  
      }
      
      void print(int wh)  {
        display.setCursor(2, wh*16+2);
        if(getChecked()){
          display.drawRect(0, wh*16, 128, 15, WHITE);
          display.setTextColor(WHITE);
           display.print(getWidgetString());         
        }
        else{
          display.fillRect(0,  wh*16, 64,  15, WHITE);
          display.drawRect(0, wh*16, 128, 15, WHITE);
          display.setTextColor(BLACK);
          display.print(getWidgetString());     
        }
         display.drawLine(64,wh*16+2,64,wh*16+11,WHITE);
        if(getWidgetStatus()){
            display.fillRect(64, wh*16+2, 96, 11, BLACK);
            display.setCursor(65, wh*16+4);
            display.setTextColor(WHITE);
            display.print("NO");
            display.fillRect(96, wh*16+2, 125, 11, WHITE);
            display.setCursor(97, wh*16+4);
            display.setTextColor(BLACK);
            display.print("YES");
            }
            else{
            display.fillRect(64, wh*16+2, 96, 11, WHITE);
            display.setCursor(65, wh*16+4);
            display.setTextColor(BLACK);
            display.print("NO");
            display.fillRect(96, wh*16+2, 125, 11, BLACK);
            display.setCursor(97, wh*16+4);
            display.setTextColor(WHITE);
            display.print("YES");
            }
       
      }
    };
