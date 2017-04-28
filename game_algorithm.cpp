#include "splash_screen.h"

//---------------------------------------- Definitions-----------------------
std::vector< std::vector<int> > choices{{0,1},{0,2},{0,3},{0}};
const char* label = "Next round";

Fl_Window win(width,height, "Guessing Game");
/********************************************/
Fl_Box background2(0,0,width,height);
/********************************************/
Fl_Box rounds(700,130,300,50);
/********************************************/
Fl_JPEG_Image p4bg("images/normal_naruto1.jpg");
/********************************************/
Fl_Button time_right(415,350,150,75,"START");
Fl_Box time_left(700,0,300,100,"Time left");
/***********Blue button**************/
Fl_Button blue(300,450,100,155,"Kunai");
Fl_JPEG_Image image4("images/kunaiOpt.jpg");
/***********white button**************/	
Fl_Button white(425,450,100,100, "Shuriken");
Fl_JPEG_Image image3("images/shurikenImg.jpg");
/***********red button**************/	
Fl_Button red(550,450,100,155, "Explodin Note");
Fl_JPEG_Image image2("images/expNote.jpg");
/********************************************/
Fl_Box box(50,50,400,50,"Choose an option");
Fl_Box score(820,200,100,100,"Points: 0");
Fl_Box comp_right(800,50,100,100,"Percent computer correct:\n\t0%");
Fl_Button continue_game(100,100, 100,100, "Play again?");

//---------------------------------------- callbacks----------------------
//animates the splash screen with an image of naruto running in the background
void backImage(){
	animation.image(image);
	animation1.image(image1);
	animation1.hide();
	animation.set_changed();
	background.image(bg);
	background2.image(p4bg);
	Fl::add_timeout(.05, animate);	
	
}

// callback function that allows the user to pick a choice once the blue button has been pressed
void blue_callback(Fl_Widget* , void *) {

	Fl::add_timeout(0.0, button_time);	
	choices[3][0] = 1;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 1) { choices[i][0] += 1; }
	}
}

// callback function that allows the user to pick a choice once the red button has been pressed
void red_callback(Fl_Widget* , void*) {

	Fl::add_timeout(0.0, button_time);	
	choices[3][0] = 2;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 2) { choices[i][0] += 1; }
	}
}

// callback function that allows the user to pick a choice once the white button has been pressed
void white_callback(Fl_Widget*, void*) {

	Fl::add_timeout(0.0, button_time);	
	choices[3][0] = 3;
	show_result();
	for (int i = 0; i < 3; ++i)
	{
		if (choices[i][1] == 3) { choices[i][0] += 1; }
	}
}
// callback funtion that allows only allows the user only 5 seconds to make a button choice once the timer button has been clicked
void time(Fl_Widget*, void*) {
	
	if (time_right.label() != label) {time_right.label(label);}
	time_right.deactivate();
	//value is set to one to distinguish what invoked timer callback
	time_right.value(1);
	Fl::add_timeout(0.0, timer);	
	
}
//  button to call the timer callback and reactivates the red, white, and blue buttons for the user to choose.
void button_time(void*)
{
	red.deactivate(); white.deactivate(); blue.deactivate();

	if (NUM_ROUNDS != 0) time_right.activate();

	Fl::remove_timeout(timer);
}	
// the timer function that counts down from 5 seconds until the user clicks on one of the choices or runs out of time.
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

		red.deactivate(); white.deactivate(); blue.deactivate();  //reactivate the buttons 

		time_right.activate();                                    // calls the timer function
		NUM_ROUNDS = NUM_ROUNDS - 1;
		game_over();
		num_rounds();

		
		time = 5;
	  }
	  else {	
		Fl::repeat_timeout(1.0 , timer);
      } 
}
// once the number of rounds has reached 0 this callback function takes the player to the final score screen
void continue_button(Fl_Widget*, void*) {
		score_to_file();
		win.hide();
		std::cout << 1 << std::endl;
		finalscore.show();
		finalscore.init_scores();
}
//---------------------------------------- game logic-----------------------
// this updates the timer box label to show the user the amount of time they have left
void show_countdown(int time)
{
	std::stringstream tt;
	tt << "Time left: " << time << " seconds";
	std::string temp = tt.str();
	const char* cstr = temp.c_str();
	time_left.copy_label(cstr);
}
// this updates the score to show player the number of points they have won and the percentage the computer has guessed correct
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
// this prints out the number of rounds are left in the game.
void num_rounds()
{
	std::stringstream ss;
	ss << "Number of rounds left: " << NUM_ROUNDS;
	std::string temp = ss.str();
	const char* cstr = temp.c_str();
	rounds.copy_label(cstr);
}
// this prints out to the screen whether the computer guessed right and calls update_score to show the number of points the player has and how many times the computer guesses correctly.
void show_result()
{
	NUM_ROUNDS -= 1;
	num_rounds();
	static double comp_correct;
	static double comp_correct_per;
	double total_choices = choices[0][0] + choices[1][0] + choices[2][0];   //gives the number of choices the user has made so far.
	int prediction = ai_predict(total_choices);                             // calls the ai_predict function to check how many times the computer has made correct guesses
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
//writes the player's final score to the score file.
void score_to_file()
{

	std::string newInput = std::to_string(points);
	std::ofstream file2(score_file, std::ios::app | std::ios::binary);
	file2 << newInput << std::endl;
	file2.close();
		
}
// once the number of rounds is over, all the buttons are deactivated and the continue_game button is activated to take the player to the final score screen
void game_over()
{
	//finish the game if num rounds is 0 
	
	if (NUM_ROUNDS <= 0)
	{
		time_right.deactivate();
		red.deactivate();
		white.deactivate();
		blue.deactivate();
		continue_game.activate();
	}
}
// by taking a random number the ai_prediction function makes a "random" guess of the user's choice. If the user chooses one choice more often the function will use
int ai_predict(double total_choices)
{			
	srand(time(NULL));
	double p1, p2, p3;
	double val = (double)rand() / RAND_MAX;

	//sorting algorithm
	std::sort(choices.begin(), choices.end() - 1, [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
    
	// calculates the percentage of the number of times the player has picked a value
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

	// this returns the game's prediction of the player's choice
	if (val < p1)
		return choices[0][1];
	else if (val < p1 + p2)
		return choices[1][1];		
	else 
		return choices[2][1];
}
