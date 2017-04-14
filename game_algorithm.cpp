#include "game_algorithm.h"

//---------------------------------------- callbacks-----------------------

void blue_callback(Fl_Widget* , void *) {

	Fl::add_timeout(0.0, button_time);	
	choices[3][0] = 1;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 1) { choices[i][0] += 1; }
	}
}

void red_callback(Fl_Widget* , void*) {

	Fl::add_timeout(0.0, button_time);	
	choices[3][0] = 2;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 2) { choices[i][0] += 1; }
	}
}

void white_callback(Fl_Widget*, void*) {

	Fl::add_timeout(0.0, button_time);	
	choices[3][0] = 3;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 3) { choices[i][0] += 1; }
	}
}

void time(Fl_Widget*, void*) {

	if (time_right.label() != label) {time_right.label(label);}

	//std::cout<<int{time_right.value()}<<std::endl;
	time_right.deactivate();
	//value is set to one to distinguish what invoked timer callback
	time_right.value(1);
	Fl::add_timeout(0.0, timer);	
	
}

void button_time(void*)
{
	red.deactivate(); white.deactivate(); blue.deactivate();

	if (NUM_ROUNDS != 0) time_right.activate();

	Fl::remove_timeout(timer);
}	

void timer(void*) {
	  static int time = 5;
	  if (time_right.value() == 1) { time = 5; time_right.value(0); }

	  blue.activate(); red.activate(); white.activate();

	  show_countdown(time);	  
	  time -= 1;
	  
	  if(time < 0) {
		//if times up
		Fl::remove_timeout(timer);

		time_left.label("Time's up! No points! Next move?");

		red.deactivate(); white.deactivate(); blue.deactivate();

		time_right.activate();
		NUM_ROUNDS = NUM_ROUNDS - 1;
		
		time = 5;
	  }
	  else {	
		Fl::repeat_timeout(1.0 , timer);
      } 
}

//---------------------------------------- game logic-----------------------

void show_countdown(int time)
{
	std::stringstream tt;
	tt << "Time left: " << time << " seconds";
	std::string temp = tt.str();
	const char* cstr = temp.c_str();
	time_left.copy_label(cstr);
}

void update_score(double points, double percent_correct)
{
	//use stringstream to format scoreboard
	std::stringstream ss;
	ss << "Points: " << points;
	std::string temp = ss.str();
	const char* cstr = temp.c_str();
	score.copy_label(cstr);
	ss.str(std::string());
	ss.clear();
	
	ss << "Percent computer correct:\n\t" << percent_correct << '%';
	temp = ss.str();	
	cstr = temp.c_str();
	comp_right.copy_label(cstr);
	ss.str(std::string());
	ss.clear();
}

void show_result()
{
	NUM_ROUNDS -= 1;
	static double points;
	static double comp_correct;
	static double comp_correct_per;
	double total_choices = choices[0][0] + choices[1][0] + choices[2][0];
	int prediction = ai_predict(total_choices);
	std::cout << "Prediction: " << prediction << '\n' << std::endl;
	if (choices[3][0] == prediction)
	{
		box.label("Computer guessed right:\n no points!");
		comp_correct += 1;
		comp_correct_per = comp_correct/(total_choices + 1) * 100;
	}
	else
	{
		box.label("You outsmarted the computer:\n 10 points");
		points += 10;
	}

	update_score(points, comp_correct_per);
	game_over();
}

void game_over()
{
	//finish the game if num rounds is 0 
	
	if (NUM_ROUNDS == 0)
	{
		time_right.deactivate();
		red.deactivate();
		white.deactivate();
		blue.deactivate();
	}
}

int ai_predict(double total_choices)
{			
	srand(time(NULL));
	double p1, p2, p3;
	double val = (double)rand() / RAND_MAX;

	//sorting algorithm
	std::sort(choices.begin(), choices.end() - 1, [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });

	if (total_choices == 0)
	{
		p1 = (1/3.0); p2 = (1/3.0); p3 = (1/3.0);
	}
	else
	{
		p1 = choices[0][0]/total_choices;
		p2 = choices[1][0]/total_choices; 
		p3 = choices[2][0]/total_choices;	
	}

	std::cout << "Prediction value: " << val << std::endl;
	std::cout << "p1 p2 p3: " << p1 << ' ' <<  p2 << ' ' << p3 << std::endl;
	
	if (val < p1)
		return choices[0][1];
	else if (val < p1 + p2)
		return choices[1][1];		
	else 
		return choices[2][1];
}


//--------------------------------TestMain-------------------------------------------

int main()
{
	blue.callback(blue_callback);
	red.callback(red_callback);
        white.callback(white_callback);

	red.deactivate();
	white.deactivate();
	blue.deactivate();

	time_right.callback(time);
	box.box(FL_UP_BOX);
	win.show();
	return Fl::run();
}
