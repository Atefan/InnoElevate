#pragma once

struct queue
{
	int* out_buttons;
	char building=0;
	int num_floors;
	queue(int num_floors, int * buttons):out_buttons (buttons), num_floors(num_floors) { building = 0;}
	void add(int );
	void remove(int );
	bool is_empty();
	int get_next_floor(int , bool);
};