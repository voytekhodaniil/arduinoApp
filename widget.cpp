#include "widget.h"
  
   WIDGET:: WIDGET(){}
   
   void WIDGET::ButtonPress(char b){}   
   void WIDGET::print(int wh){}
   
   void WIDGET::setWidgetStatus(bool b){this->WidgetStatus=b;}
   bool WIDGET::getWidgetStatus(){return WidgetStatus;}
   bool WIDGET::getWidgetOver(){return WidgetOver;}
   bool WIDGET::getChecked(){return Checked;}
 String WIDGET::getWidgetString(){return WidgetString;}
   void WIDGET::setChecked(bool b){this->Checked = b;}
   void WIDGET::WidgetOverPrint(){}

 
