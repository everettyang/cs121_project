#include "splash_screen.h"

//score
//how to play game
//team detail
int width = 1000;
int height = 1000;
int NUM_ROUNDS = 32;
Fl_Window win1(width,height, "Outsmart the Computer");
//buttton
Fl_Box background(0,0,width,height);
Fl_Box animation(999,100,200,100);
Fl_Box animation1(999,100,200,100);

Fl_JPEG_Image bg("materials/white.jpg");
Fl_GIF_Image image("materials/naruto1.gif");
Fl_GIF_Image image1("materials/naruto2.gif");

Fl_Button start(450,350,75,75,"START");
//box
Fl_Box name(450,50,100,200,"OUTSMART THE COMPUTER!");
Fl_Box teamm(450,180,80,80,"Team number: 26");
Fl_Box teamn(450,200,100,200,"Team members:\n Scott Tran, Cesar Villanueva-Vazquez, Haozhen Yang, Everett Yang.");
//---------------winexplain----------------------------
Fl_Window wine(width,height, "Instructions");
//button
Fl_Button starte(450,700,75,75,"Next");
//box explain
Fl_Box explain(100,0,50,50,"INSTRUCTIONS:");
Fl_Box ed(FL_UP_BOX, 100,100,500,200, "First, the game will ask the user to select the difficulty. \n The computer will try to guess the user's choice. \nIf the computer guesses wrong then the user gets 10 points.\n The number of rounds vary based on difficulty.\n In the end, the user will be shown how his/her score ranks among the top 5 scores.");

//--------------win2-----------------------
Fl_Window win2(width,height, "Select Difficulty");
Fl_Box bg1(0,0,width,height);
Fl_JPEG_Image im1("materials/Konoha.jpg");
//box
Fl_Box difficulty(450,10,100,200,"Which level would you like to play?");
//button1
Fl_Button l1(300,450,75,75,"Level 1");
//button2
Fl_Button l2(400,450,75,75,"Level 2");
//button3
Fl_Button l3(500,450,75,75,"Level 3");
//button4
Fl_Button l4(600,450,75,75,"Level 4");
//button5
Fl_Button l5(700,450,75,75,"Level 5");

void animate_helper(int x, int y)
{
if (animation.changed() == 0)
{
	//std::cout << "2" << std::endl;
	animation1.hide();
	animation.set_changed();
	animation.position(x,y);
	animation.show();
}
else
{
	//std::cout << "1" << std::endl;
	animation.hide();
	animation1.position(x,y);
	animation1.show();
	animation.clear_changed();
}

}

void animate(void *)
{
	static int x = width, y = 100; 

	if (!(x < -176) && !(y > height)) { x -= 40;} 	
	else if (x < -176) {y += 100; x = width;
			if (y > height) y = 100;}

	animate_helper(x, y);

	Fl::repeat_timeout(.1, animate);
}

void start_callback(Fl_Widget* , void *) {
	win1.hide();
	wine.show();
	Fl::remove_timeout(animate);
}

void starte_callback(Fl_Widget* , void *) {
	wine.hide();
	win2.show();
	
}

void l1_callback(Fl_Widget* , void *) {
	win2.hide();
	scoreboard.show();
	NUM_ROUNDS = NUM_ROUNDS * 1;
	num_rounds();
	
}

void l2_callback(Fl_Widget* , void *) {
	win2.hide();
	scoreboard.show();
	NUM_ROUNDS = NUM_ROUNDS * 2;
	num_rounds();
	
}
	
void l3_callback(Fl_Widget* , void *) {
	win2.hide();
	scoreboard.show();
	NUM_ROUNDS = NUM_ROUNDS * 4;
	num_rounds();
	
}
void l4_callback(Fl_Widget* , void *) {
	win2.hide();
	scoreboard.show();
	NUM_ROUNDS = NUM_ROUNDS * 8;
	num_rounds();
	
}
void l5_callback(Fl_Widget* , void *) {
	win2.hide();
	scoreboard.show();
	NUM_ROUNDS = NUM_ROUNDS * 16;
	num_rounds();
}

