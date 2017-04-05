#include "game_algorithm.h"

//---------------------------------------- callbacks-----------------------

void blue_callback(Fl_Widget* , void *) {

	choices[3][0] = 1;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 1) { choices[i][0] += 1; }
	}
}

void red_callback(Fl_Widget* , void*) {

	choices[3][0] = 2;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 2) { choices[i][0] += 1; }
	}
}

void white_callback(Fl_Widget*, void*) {

	choices[3][0] = 3;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 3) { choices[i][0] += 1; }
	}
}

//---------------------------------------- game logic-----------------------

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
	game_over(total_choices);
}

void game_over(double total_choices)
{
	//finish the game if total choices equal number of rounds
	if (total_choices == NUM_ROUNDS - 1)
	{
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


//--------------------------------Test Main---------------------------------------------

int main()
{
	
	blue.callback(blue_callback);
	red.callback(red_callback);
	white.callback(white_callback);
	box.box(FL_UP_BOX);
	win.show();
	return Fl::run();
}
