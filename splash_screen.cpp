#include "splash_screen.h"

//score
//how to play game
//team detail
int NUM_ROUNDS = 32;
Fl_Window win1(1000,1000, "first");
//buttton
Fl_Button start(150,350,75,75,"start");
//box
Fl_Box name(50,50,100,200,"OUTSMART THE COMPUTER!");
Fl_Box teamm(60,180,80,80,"Team number: 26");
Fl_Box teamn(180,200,100,200,"Team members:\n Scott Tran, Cesar Villanueva-Vazquez, Haozhen Yang, Everett Yang.");
//---------------winexplain----------------------------
Fl_Window wine(1000,1000, "window explain");
//button
Fl_Button starte(150,350,75,75,"start");
//box explain
Fl_Box explain(100,10,100,200,"Explain");
Fl_Box ed(120,60,300,200,"First of all, the game will ask user the Difficulty of the game. Then user will make certain of choice to compare the ramdom choice which computer make and get score.");

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

void start_callback(Fl_Widget* , void *) {
	win1.hide();
	wine.show();
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
	NUM_ROUNDS = NUM_ROUNDS * 3;
	num_rounds();
	
}
void l4_callback(Fl_Widget* , void *) {
	win2.hide();
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 4;
	num_rounds();
	
}
void l5_callback(Fl_Widget* , void *) {
	win2.hide();
	win.show();
	NUM_ROUNDS = NUM_ROUNDS * 5;
	num_rounds();
}



