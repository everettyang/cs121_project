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
Fl_Window wine(1000,1000, "window explain");
//button
Fl_Button starte(450,350,75,75,"START");
//box explain
Fl_Box explain(250,10,100,200,"How to play:");
Fl_Box ed(350,60,300,200,"First of all, the game will ask user the Difficulty of the game. Then user will make certain of choice to compare the ramdom choice which computer make and get score.");

//--------------win2-----------------------
Fl_Window win2(1000,1000, "second");
//box
Fl_Box difficulty(100,10,100,200,"Which level would you like to play?");
//button1
Fl_Button l1(20,150,75,75,"Level 1");
Fl_Box dl1(20,230,75,200,"The top five scores are\n");


//button2
Fl_Button l2(100,150,75,75,"Level 2");
Fl_Box dl2(100,230,75,200,"The top five scores are\n");
//button3
Fl_Button l3(180,150,75,75,"Level 3");
Fl_Box dl3(180,230,75,200,"The top five scores are\n");
//button4
Fl_Button l4(260,150,75,75,"Level 4");
Fl_Box dl4(260,230,75,200,"The top five scores are\n");
//button5
Fl_Button l5(340,150,75,75,"Level 5");
Fl_Box dl5(340,230,75,200,"The top five scores are\n");

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
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 1;
	num_rounds();
	
}

void l2_callback(Fl_Widget* , void *) {
	win2.hide();
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 2;
	num_rounds();
	
}
	
void l3_callback(Fl_Widget* , void *) {
	win2.hide();
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 4;
	num_rounds();
	
}
void l4_callback(Fl_Widget* , void *) {
	win2.hide();
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 8;
	num_rounds();
	
}
void l5_callback(Fl_Widget* , void *) {
	win2.hide();
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 16;
	num_rounds();
}

