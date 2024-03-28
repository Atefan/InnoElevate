#include "queue.h"
#include "hw_API.h"
#include "PinChangeInterrupt.h"

#define SPEED_PIN 2
#define DIR_1 3
#define DIR_2 4
#define TR 5
#define ECHO 6

int buttons[] = { A0, A1, A2, A3, A4 };
pack calc(5, buttons);
int arr[] = { 1, 2, 3, 4, 5 };
hw elev(5, arr, SPEED_PIN, DIR_1, DIR_2, TR, ECHO);

void f1() {  calc.add(0);Serial.print("(finished 0)building = ");Serial.println(calc.building - 0); }
void f2() {  calc.add(1);Serial.print("(finished 1)building = ");Serial.println(calc.building - 0); }
void f3() {  calc.add(2);Serial.print("(finished 2)building = ");Serial.println(calc.building - 0); }
void f4() {  calc.add(3);Serial.print("(finished 3)building = ");Serial.println(calc.building - 0); }
void f5() {  calc.add(4);Serial.print("(finished 4)building = ");Serial.println(calc.building - 0); }

void setup() {
	Serial.begin(9600);
	for (int i = 0; i < 5; i++)
		pinMode(buttons[i], INPUT_PULLUP);
	
	pinMode(LED_BUILTIN, OUTPUT);

	attachPCINT(digitalPinToPCINT(buttons[0]), f1, CHANGE);
	attachPCINT(digitalPinToPCINT(buttons[1]), f2, CHANGE);
	attachPCINT(digitalPinToPCINT(buttons[2]), f3, CHANGE);
	attachPCINT(digitalPinToPCINT(buttons[3]), f4, CHANGE);
	attachPCINT(digitalPinToPCINT(buttons[4]), f5, CHANGE);
}

void loop()
{
  Serial.println("Checking if empty...");
	while (calc.is_empty())
  {
   Serial.print("empty--->");
   Serial.println(calc.building - 0);
   delay(1000);
  }
  Serial.println("not empty");

	int next = calc.get_next_floor(elev.cur_f);

  if(next!=-1)
  {
    elev.go_to(next, elev.cur_f);
    calc.remove(elev.cur_f);
  }
  Serial.println(calc.building);
	
}
