#pragma once
extern int global;
struct hw
{
public:

  int cur_f;
	int n_floors;
	hw(int n_floors, float* calc, int speed, int _1, int _2, int tr, int echo);
	void go_to(int floor);
	float get_distance();

  
	void move_M_up(int );

	void move_M_down(int );
  
	void stop();
	bool is_going_up(int);

private:
	int speed, _1, _2;
	int trig, echo;
	float* arr;


	bool finished(int , float ,bool );



};