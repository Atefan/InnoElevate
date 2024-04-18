#include "hw_API.h"
#include <Arduino.h>

hw::hw(int n_floors, int* calc, int speed, int _1, int _2, int tr, int echo) :trig(tr), echo(echo), n_floors(n_floors), cur_f(0), arr(calc), speed(speed), _1(_1), _2(_2)
{
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

void hw::go_to(int floor, int cur_floor)
{
	if (floor == cur_floor)
		return;
	if (floor > cur_floor)
		move_M_up();
	else
		move_M_down();
	while (finished(floor, get_distance()))
	{
		delay(5);

		update_floor();
	}
}
int hw::update_floor()
{
	for (int i = 0; i < n_floors; i++)
	{
		int cur_pos = get_distance();
		if (cur_pos < arr[i])
			return i - 1;
		if (cur_pos == arr[n_floors - 1])
			return n_floors - 1;
	}
}


bool hw::finished(int target, int dist)
{
	return dist == arr[target];
}

float hw::get_distance()
{
	digitalWrite(trig, LOW);
	delayMicroseconds(5);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	pinMode(echo, INPUT);
	float duration = pulseIn(echo, HIGH);
	return (duration / 2) / 29.1;
}

void hw::move_M_up()
{
	digitalWrite(_1, HIGH);
	digitalWrite(_2, LOW);
	analogWrite(speed, 255);
}
void hw::move_M_down()
{
	digitalWrite(_1, LOW);
	digitalWrite(_2, HIGH);
	analogWrite(speed, 255);
}


