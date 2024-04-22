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
float arr[] = { 3, 6.5, 14, 20 ,100};
hw elev(NUM_BUTTONS/2, arr, SPEED_PIN, DIR_1, DIR_2, TR, ECHO);

void blink_led()
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN,LOW);
  delay(300);
}

int next_floor = 0;

void f1() {  calc.add(0);next_floor = 0;Serial.print("(finished 0)building = ");Serial.println(calc.building - 0);blink_led(); }
void f2() {  calc.add(1);next_floor = 1;Serial.print("(finished 1)building = ");Serial.println(calc.building - 0);blink_led(); }
void f3() {  calc.add(2);next_floor = 2;Serial.print("(finished 2)building = ");Serial.println(calc.building - 0);blink_led(); }
void f4() {  calc.add(3);next_floor = 3;Serial.print("(finished 3)building = ");Serial.println(calc.building - 0);blink_led(); }

void setup() {
	Serial.begin(9600);
  delay(1000);
  
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
  Serial.println("Starting setup");
  
  elev.move_M_up(global);
  delay(5000);
  elev.stop();

  Serial.println("Ending Setup\n\n Starting loop!\n");
}

void loop()
{
  // for(int base = 250; base > 70 ;base-=10)
  // {
  //   Serial.println(base);
  //   elev.move_M_up(base);
  //   delay(1000);
  // }
  
  
  // Serial.println(elev.get_distance());
  // delay(100);
  Serial.println("Checking if empty...");  
	while (calc.is_empty())
  {
   Serial.print("empty--->");
   Serial.println(elev.get_distance());
   delay(10);
  }
  Serial.println("not empty");
  Serial.print("current floor = ");
  Serial.print(elev.cur_f);

	//next_floor = calc.get_next_floor(elev.cur_f, next_floor);
  Serial.print("next floor = ");
  Serial.println(next_floor);

  if(next_floor!=-1)
  {
    elev.go_to(next_floor);
    calc.remove(next_floor);
  }
  Serial.println(calc.building);
	
}
