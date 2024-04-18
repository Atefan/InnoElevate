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

int pack::get_next_floor(int cur_f)
{
		if (up == true)
    {
			building >>= cur_f;
		  unsigned long index;

		  if (index = findUp(building)!= -1 )
			  return index;
		  else
      {
			  building <<= 7 - cur_f;
        up = !up;
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
        up = !up;
        return findUp(building);
      }
    }
}

void pack::add(int f)
{
	building |= 1 << f;
}

void pack::remove(int floor)
{
	building &= ~(1 << floor);
}

bool pack::is_empty() { return !(building & ((1 << num_floors)-1)); }




