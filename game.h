#ifndef SPLASH_SCREEN
#define SPLASH_SCREEN

#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <time.h>
//---------------win1----------------------------
Fl_Window win1(500,500, "first");
//buttton
bool start_but = true;
void start_callback(Fl_Widget* w , void* start_but);
Fl_Button start(150,350,75,75,"start");
//box
Fl_Box name(50,50,100,200,"The name of game is ");
Fl_Box teamm(60,180,80,80,"The team number is 26");
Fl_Box teamn(80,200,100,200,"The team member is:                   ");

//--------------win2-----------------------
Fl_Window win2(500,500, "second");
//box
Fl_Box diffcult(100,10,100,200,"Which level would you like to play?");
//button1
bool l1_but = true;
void l1_callback(Fl_Widget* w , void* start_but);
Fl_Button l1(20,150,75,75,"Level 1");
//button2
bool l2_but = true;
void l2_callback(Fl_Widget* w , void* start_but);
Fl_Button l2(100,150,75,75,"Level 2");
//button3
bool l3_but = true;
void l3_callback(Fl_Widget* w , void* start_but);
Fl_Button l3(180,150,75,75,"Level 3");
//button4
bool l4_but = true;
void l4_callback(Fl_Widget* w , void* start_but);
Fl_Button l4(260,150,75,75,"Level 4");
//button5
bool l5_but = true;
void l5_callback(Fl_Widget* w , void* start_but);
Fl_Button l5(340,150,75,75,"Level 5");















//--------------win21-----------------------
Fl_Window win21(500,500, "Diffcult 1");

//--------------win22-----------------------
Fl_Window win22(500,500, "Diffcult 2");
//--------------win23-----------------------
Fl_Window win23(500,500, "Diffcult 3");

//--------------win24-----------------------
Fl_Window win24(500,500, "Diffcult 4");
//--------------win25-----------------------
Fl_Window win25(500,500, "Diffcult 5");















#endif //SPLASH_SCREEN