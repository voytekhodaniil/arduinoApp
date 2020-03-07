
#include <Arduino.h>
#include <Esp.h>
#include "disp.h"
#include "screen.h"
#include "widget.h"
#include "systemWidgets.h"

/* ESSENTIAL GRAPHIC ELEMENTS
   WIDGET  -  ELEMENT OF SCREEN
   SCREEN  - MAIN ELEMENT
*/





class MainWindow : public Screen {
  public:
    MainWindow() {
	    Parent = new Widget();
	    Serial.println(" Debug : Main window start");
      ArraySize =5;
      Widgets = new Widget* [ArraySize];

	    for (int a = 0; a < 5; a++)
	    {
		    Serial.println(" Debug : widget creating start "+ String (a));

	    
		    Widgets[a] = new Line(this, String("Hello num"));
	    }
      
      
    Widgets[0] = new Trigger(this, "Do you like?");
    Widgets[1] = new TextOpener(this, "Click ME");         
	    Serial.println(" Debug : Main windows end");
    }

    void ButtonPress   (char button) {

      
	    if (button == '2')Move(0);
	    else if (button == '8')Move(1);
	    else{Serial.println(" Debug : Main buttonpress widget char send");Widgets[ArrayPos]->ButtonPress(button); }
    }

};
//
Screen *mw;
void setup() {

	Serial.begin(115200);
	Serial.println(" Debug :started");
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
	display.setCursor(20, 40);
	display.setTextColor(WHITE);
	display.print("Loading...");
  display.display();
	delay(100);
	mw = new MainWindow();
	Serial.println(" Debug : setup ended");

}

void loop() {
  if (Serial.available()) {
    display.clearDisplay();
   char BUTTON = Serial.read();
	  Serial.println(" Debug : loop char resived "+String(BUTTON) );

    mw->GetScreen(BUTTON)->Print();
    display.display();

   
  }

}
