#pragma once

struct hw
{
public:
	int cur_f;
	hw(int n_floors, int* calc, int speed, int _1, int _2, int tr, int echo);
	void go_to(int floor, int cur_floor);
	float get_distance();

private:
	int speed, _1, _2;
	int trig, echo;
	int n_floors;
	int* arr;


	int update_floor();

	bool finished(int target, int dist);


	void move_M_up();

	void move_M_down();

};