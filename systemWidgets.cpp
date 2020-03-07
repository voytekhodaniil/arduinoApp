#include "screen.h"

#include "systemScreens.h"
#include "systemWidgets.h"
#include <WString.h>
#include <Arduino.h>

/*Line*/

void Line::Print(int position,bool AtCursor)  {
  display.setCursor(2, position * 16 + 2);
  if (AtCursor)
    display.setTextColor(WHITE);
  else {
    display.fillRect(0, position * 16, 128, 16, WHITE);
    display.setTextColor(BLACK);
  }
  display.print(Data[0]);
}



/*  /*TRIGGER*/


Trigger::Trigger() {
  DataSize = 2;
	Data = new String[2];
  Data[1]="N";
  };
Trigger::Trigger(Screen *parent, String string): Widget(parent, string) {

  DataSize = 2;
	String bf = Data[0];
	Data = new String[2];
	Data[0] = bf;
	Data[1] = "N";
	Serial.println(" Debug : trigger end" +Data[0]);

  };

void Trigger::ButtonPress(char button) {
	Serial.println(" Debug : trigger buttonpress start"+String(button));

	if (button == '5')
	
		
		if (Data[1] == "N")
		{
			Data[1] = "Y";
			Serial.println(" Debug : trigger buttonpress Y");

		}
		else {Data[1] = "N"; 	Serial.println(" Debug : trigger buttonpress N");}

}

void Trigger::Print(int position,bool AtCursor)  {
	Serial.println(" Debug : treeger print start"+Data[0]);

  display.setCursor(2, position * 16 + 2);
  if (AtCursor) {
    display.drawRect(0, position * 16, 128, 15, WHITE);
    display.setTextColor(WHITE);
    display.print(Data[0]);
  }
  else {
    display.fillRect(0,  position * 16, 64,  15, WHITE);
    display.drawRect(0, position * 16, 128, 15, WHITE);
    display.setTextColor(BLACK);
    display.print(Data[0]);
  }
  display.drawLine(64, position * 16 + 2, 64, position * 16 + 11, WHITE);
  if (Data[1]=="N") {
    display.fillRect(64, position * 16 + 2, 96, 11, BLACK);
    display.setCursor(65, position * 16 + 4);
    display.setTextColor(WHITE);
    display.print("NO");
    display.fillRect(96, position * 16 + 2, 125, 11, WHITE);
    display.setCursor(97, position * 16 + 4);
    display.setTextColor(BLACK);
    display.print("YES");
  }
  else {
    display.fillRect(64, position * 16 + 2, 96, 11, WHITE);
    display.setCursor(65, position * 16 + 4);
    display.setTextColor(BLACK);
    display.print("NO");
    display.fillRect(96, position * 16 + 2, 125, 11, BLACK);
    display.setCursor(97, position * 16 + 4);
    display.setTextColor(WHITE);
    display.print("YES");
  }
	Serial.println(" Debug : treeger print end");
}






TextOpener::TextOpener(Screen* parent, String string)
	: Widget(parent, string) {
		Child = new TextView(this);
	}
void TextOpener::Print(int position,bool AtCursor)  {
	Serial.println(" Debug : textopener print start" + Data[0]);
  display.setCursor(2, position * 16 + 2);
  if (AtCursor) {
    display.setTextColor(WHITE);
  }
  else {
    display.fillRect(0, position * 16, 128, 16, WHITE);
    display.setTextColor(BLACK);
  }
  display.print(Data[0]);
	Serial.println(" Debug : textopener print end");

}
void TextOpener::ButtonPress(char button) {
	Serial.println(" Debug : textopenerwidget buttonpress start");

  if (button == '5') {
    Parent->WidgetOpened = 1;
	  Serial.println(" Debug : textopenerwidget child opened");

  }
}

void TextOpener::WidgetOverPrint() {
  //child->print();
}












void TextWidget::Print(int position,bool AtCursor) {
	Serial.println(" Debug : TextWidget print start");

  int pos = position/10-(position - position/10*10 );
  String dispTo = Data[0].substring(pos*21,pos*21+8*21);


  display.fillRect(0,0, 128,64, WHITE);  
    display.setCursor(0,0);
    display.setTextColor(BLACK);
  
  display.print(dispTo);
      display.fillRect(0,(position%10)*8, 128,8, INVERSE);
	Serial.println(" Debug : TextWidget print end");

}
