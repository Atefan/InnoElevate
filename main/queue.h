#pragma once

struct queue
{
	int* out_buttons;
	char building=0;
	int num_floors;
	bool up;
	queue(int num_floors, int * buttons):out_buttons (buttons), num_floors(num_floors) { building = 0; up= true;	}
	void add(int f);
	void remove(int floor);
	bool is_empty();
	int get_next_floor(int cur_f);
};