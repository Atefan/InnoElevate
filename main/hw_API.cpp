#include "hw_API.h"
#include <Arduino.h>

hw::hw(int n_floors, float* calc, int speed, int _1, int _2, int tr, int echo) :trig(tr), echo(echo), n_floors(n_floors), arr(calc), speed(speed), _1(_1), _2(_2),cur_f(0)
{
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

void hw::go_to(int targeted_floor)
{
  bool is_upping = is_going_up( targeted_floor);
  
	if (is_upping)
		move_M_up(global);
	else
    move_M_down(global);
	
  bool finished_res = false;
  do
	{
		delay(5);
    float every_dist = get_distance();
    Serial.print("dist = ");
    Serial.println(every_dist);
    finished_res = finished(targeted_floor, every_dist, is_upping);
	}while (!finished_res);
  cur_f = targeted_floor;
  stop();
}

bool hw::finished(int target, float dist, bool is_uping)
{
  Serial.print("target hight = ");
  Serial.print(arr[target]);
  Serial.print("\tcurrent dist = ");
  Serial.print(dist);
  Serial.print("\tis_uping = ");
  Serial.print(is_uping);
  if(is_uping)
    return dist>=arr[target];
  else
    return dist<=arr[target];
}

bool hw::is_going_up(int targeted_floor)
{
  float dist = get_distance();
	return arr[targeted_floor] > dist;
}

void hw::stop()
{
  
	digitalWrite(LED_BUILTIN, LOW);
	analogWrite(speed, 0);
}


float hw::get_distance()
{
  static float prev = 0;
  static int cnt = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  float duration = pulseIn(echo, HIGH);
  float res = (duration / 2) / 29.1;
  if(res > 30)
      res = 0;
  if(cnt >= 3)
      cnt = 0;
  if(cnt++ != 2 && (prev < res - 1.5 || prev > res + 1.5))
  {
      Serial.print(cnt);
      Serial.println("\tin delete!!!");
      res = prev;
  }
  else
  {
    prev = res;
    Serial.println("NOT in delete!!!");
  }

  for(int i=0;i<n_floors;i++)
    if(res<arr[i] && res > arr[i+1])
      cur_f = 0;
	return res;
}

void hw::move_M_up(int value)
{
	digitalWrite(LED_BUILTIN, HIGH);
	digitalWrite(_1, HIGH);
	digitalWrite(_2, LOW);
	analogWrite(speed, value);
}
void hw::move_M_down(int value)
{
	digitalWrite(LED_BUILTIN, HIGH);
	digitalWrite(_1, LOW);
	digitalWrite(_2, HIGH);
	analogWrite(speed, value);
}


