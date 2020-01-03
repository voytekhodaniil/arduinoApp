#include "screen.h"
#include "widget.h"
#include "disp.h"
/*
 *LineDisplay widget
 *Element in Screen which just show text
 constructor:
      LineDisplay(SCREEN* p,String s) -  p-parent of widget; s-onWidget String
 fun:
    void print(int wh) - draw widget at wh num on string
    **  see widget.h  **
*/
class Line: public WIDGET{
    public:

    Line(){};
    Line(SCREEN* p,String s){
      parent = p;
      setWidgetString(s);
      }
      void print(int wh)  {
        display.setCursor(2, wh*16+2);
        if(getChecked()){

          display.setTextColor(WHITE);
        }
        else{
          display.fillRect(0, wh*16, 128, 16, WHITE);
          display.setTextColor(BLACK);
        }
        display.print(getWidgetString());
      }
    };

    /*
   *Trigger widget
   *Element in Screen which can change his status 
   constructor:
        Trigger(SCREEN* p,String s) -  p-parent of widget; s-onWidget String
   fun:
      void print(int wh) - draw widget at wh num on string
      void ButtonPress(char b) - on '5' change status
      
      **  see widget.h  **
  */
    
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
       virtual void setWidgetString(String str){
        this->WidgetString = str;
        if( this->WidgetString.length()>10)
          this->WidgetString.remove(10);
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
