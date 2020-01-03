
#include "screen.h"
#include "widget.h"
#include "disp.h"
#include "systemWidgets.cpp"

/* ESSENTIAL GRAPHIC ELEMENTS
 * WIDGET  -  ELEMENT OF SCREEN
 * SCREEN  - MAIN ELEMENT
*/

 
   class Text : public SCREEN{
    void ButtonPress   (char b){
    if(!widgets[getArrayPos()]->getWidgetOver()){
    widgets[getArrayPos()]->setChecked(0);
    if(b=='2')move(0);
    if(b=='8')move(1);
    widgets[getArrayPos()]->setChecked(1);}
    else widgets[getArrayPos()]->WidgetOverPrint();
    widgets[getArrayPos()]->ButtonPress(b);
    Serial.println("In array: "+String(getArrayPos())+" on screen:  "+String(getScreenPos()));  
    print();   
    }
    } ;
   class TextView: public WIDGET{

    void ButtonPress(char b){
      
      }
    };
   
    
  class MainWindow :public SCREEN{
    public:
    MainWindow(){
      setArraySize(10);
      widgets = new WIDGET* [getArraySize()];
      for(int a=0;a<4;a++){
        widgets[a] = new Line(this,"Hello num "+String(a));
       // widgets[a].str = "Hello num "+String(a);
      }
      for(int a=4;a<9;a++){
        widgets[a] = new Line(this,"Hello my num is"+String(a));
       // widgets[a].str = "Hello num "+String(a);
      }
      widgets[9]= new Trigger(this,"Do you like?");
    }
    
    void ButtonPress   (char b){
    if(!widgets[getArrayPos()]->getWidgetOver()){
    widgets[getArrayPos()]->setChecked(0);
    if(b=='2')move(0);
    if(b=='8')move(1);
    widgets[getArrayPos()]->setChecked(1);}
    else widgets[getArrayPos()]->WidgetOverPrint();
    widgets[getArrayPos()]->ButtonPress(b);
    Serial.println("In array: "+String(getArrayPos())+" on screen:  "+String(getScreenPos()));  
    print();   
    }
    
    };
  SCREEN *mw = new MainWindow();
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println("Started"); 
  display.clearDisplay();
  mw->print();
  display.display();
}

void loop() {
  if(Serial.available()){
    display.clearDisplay();
  char BUTTON = Serial.read();  
 mw->ButtonPress(BUTTON);  
 display.display();
  
  }

}
