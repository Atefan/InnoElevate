#include "queue.h"

int findUp(char mask) {
    for (int i = 0; i < 8; i++) 
        if ((mask & (1 << i)) != 0) 
            return i;
    return -1;
}

int findDown(char mask) {
    for (int i = 8; i; i--) 
        if ((mask & (1 << (i-1))) != 0) 
            return i;
    return -1;
}

int queue::get_next_floor(int cur_f, bool is_upping)
{
		if (is_upping == true)
    {
			building >>= cur_f;
		  unsigned long index;

		  if (index = findUp(building)!= -1 )
			  return index;
		  else
      {
			  building <<= 7 - cur_f;
        is_upping = !is_upping;
        return findDown(building);
      }
    }
    else
    {
      building <<= 7 - cur_f;
		  unsigned long index;

		  if (index = findDown(building)!= -1 )
			  return index;
		  else
      {
			  building >>= cur_f;
        is_upping = !is_upping;
        return findUp(building);
      }
    }
}

void queue::add(int f)
{
	building |= 1 << f;
}

void queue::remove(int floor)
{
	building &= ~(1 << floor);
}

bool queue::is_empty() { return !(building & ((1 << num_floors)-1)); }




