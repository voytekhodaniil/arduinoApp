#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "screen.h"
#include "widget.h"
Adafruit_SSD1306 display(128,64, &Wire);



/* ESSENTIAL GRAPHIC ELEMENTS
 * WIDGET  -  ELEMENT OF SCREEN
 * SCREEN  - MAIN ELEMENT
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
    
  class MainWindow :public SCREEN{
    public:
    MainWindow(){
      setArraySize(10);
      widgets = new WIDGET* [getArraySize()];
      for(int a=0;a<4;a++){
        widgets[a] = new LineDisplay(this,"Hello num "+String(a));
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
