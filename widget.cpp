#include "widget.h"
#include "screen.h"
#include <Arduino.h>

Widget:: Widget() {Parent = new Screen;}
Widget:: Widget(Screen* parent, String string) {
	Serial.println(" Debug : widget constructor start "+string+String(DataSize));

  Parent = parent;

	  Serial.println(" Debug : widget constructor new data created " + string);

  Data = new String[1];
  Data[0]=string;
  DataSize =1;

	
  Serial.println(" Debug : widget constructor end " + Data[0]);

}
Screen* Widget::GetScreen(char button){
	Serial.println(" Debug : widget child reeturned");

  return Child->GetScreen(button);
}

/*
void WIDGET::setWidgetStatus(bool b) {
  this->WidgetStatus = b;
}
bool WIDGET::getWidgetStatus() {
  return WidgetStatus;
}
bool WIDGET::getWidgetOver() {
  return WidgetOver;
}
bool WIDGET::getChecked() {
  return Checked;
}
String WIDGET::getWidgetString() {
  return WidgetString;
}
void WIDGET::setChecked(bool b) {
  this->Checked = b;
}
void WIDGET::WidgetOverPrint() {}
void WIDGET::setWidgetOver(bool b) {
  this->WidgetOver = b;
  parent->re = 1;
}
void WIDGET::ButtonPress(char b) {
  if (getWidgetOver()) {
    this->child->ButtonPress(b);

  }
  else ButtonPressRaw(b);
}

bool WIDGET::print(int wh) {
  if (getWidgetOver())
    WidgetOverPrint();
  else PrintRaw(wh);

}*/
