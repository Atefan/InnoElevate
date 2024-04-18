#include "queue.h"
#include "hw_API.h"
#include "PinChangeInterrupt.h"
#define SPEED_PIN 2
#define DIR_1 3
#define DIR_2 4
#define TR 5
#define ECHO 6
#define NUM_BUTTONS 8

int global =200;

int buttons[] = { A0, A1, A2, A3, 8,9,10,11};
queue calc(NUM_BUTTONS, buttons);
int arr[] = { 3.2, 6.9, 15.3, 28 };
hw elev(NUM_BUTTONS, arr, SPEED_PIN, DIR_1, DIR_2, TR, ECHO);

void blink_led()
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN,LOW);
  delay(300);
}

void f1() {  calc.add(0);Serial.print("(finished 0)building = ");Serial.println(calc.building - 0);blink_led(); }
void f2() {  calc.add(1);Serial.print("(finished 1)building = ");Serial.println(calc.building - 0);blink_led(); }
void f3() {  calc.add(2);Serial.print("(finished 2)building = ");Serial.println(calc.building - 0);blink_led(); }
void f4() {  calc.add(3);Serial.print("(finished 3)building = ");Serial.println(calc.building - 0);blink_led(); }

void setup() {
	Serial.begin(9600);
	for (int i = 0; i < NUM_BUTTONS; i++)
		pinMode(buttons[i], INPUT_PULLUP);
	
	pinMode(LED_BUILTIN, OUTPUT);

	attachPCINT(digitalPinToPCINT(buttons[0]), f1, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[1]), f2, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[2]), f3, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[3]), f4, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[4]), f1, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[5]), f2, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[6]), f3, FALLING );
	attachPCINT(digitalPinToPCINT(buttons[7]), f4, FALLING );
  Serial.println("Starting");
  delay(5000);
}

void loop()
{
  for(int i = 0 ; i<global/10;i++)
  {
    elev.move_M_up(global);
  }delay(1000);
  elev.stop();
  delay(3000);
  elev.move_M_down(global);
  delay(1000);
  elev.stop();
  delay(3000);
  
  Serial.println(elev.get_distance());
  delay(100);
  // Serial.println("Checking if empty...");
	// while (calc.is_empty())
  // {
  //  Serial.print("empty--->");
  //  Serial.println(calc.building - 0);
  //  delay(1000);
  // }
  // Serial.println("not empty");

	// int next = calc.get_next_floor(elev.cur_f);

  // if(next!=-1)
  // {
  //   elev.go_to(next, elev.cur_f);
  //   calc.remove(elev.cur_f);
  // }
  // Serial.println(calc.building);
	
}
