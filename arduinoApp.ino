
#include "disp.h"
#include "screen.h"
#include "widget.h"
#include "systemWidgets.h"

/* ESSENTIAL GRAPHIC ELEMENTS
   WIDGET  -  ELEMENT OF SCREEN
   SCREEN  - MAIN ELEMENT
*/





class MainWindow : public SCREEN {
  public:
    MainWindow() {
      Serial.begin(115200);
      setArraySize(5);
      widgets = new WIDGET* [getArraySize()];

      for (int a = 0; a < 5; a++) 
        widgets[a] = new Line(this, "Hello num " + String(a));
        // widgets[a].str = "Hello num "+String(a);
      
      widgets[0] = new Trigger(this, "Do you like?");
      widgets[1] = new TextOpener(this, "Click ME");                                      // -----ERORRS HERE

    }

    void ButtonPressRaw   (char b) {
      // Serial.println("Screen");
      widgets[getArrayPos()]->setChecked(0);
      if (b == '2')move(0);
      if (b == '8')move(1);
      widgets[getArrayPos()]->setChecked(1);
      widgets[getArrayPos()]->ButtonPress(b);
      print();
      if (re) {
        //Serial.println("Need Reprint");
        re = 0;
        ButtonPress(' ');
      }
    }

};
//
SCREEN *mw = new MainWindow();
void setup() {


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.println("Started");
  display.clearDisplay();
  mw->print();
  display.display();
}

void loop() {
  if (Serial.available()) {
    display.clearDisplay();
    char BUTTON = Serial.read();
    Serial.println("Button clicked - " + BUTTON);
    mw->ButtonPress(BUTTON);
    display.display();

   
  }

}
