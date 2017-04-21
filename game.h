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
Fl_Window win1(1000,1000, "first");
//buttton
bool start_but = true;
void start_callback(Fl_Widget* w , void* start_but);
Fl_Button start(150,350,75,75,"start");
//box
Fl_Box name(50,50,100,200,"The name of game is ");
Fl_Box teamm(60,180,80,80,"The team number is 26");
Fl_Box teamn(180,200,100,200,"The team member is:\n Scott Tran, Cesar Villanueva-Vazquez, Haozhen Yang, Siyan Yang.");
//---------------winexplain----------------------------
Fl_Window wine(1000,1000, "window explain");
//button
bool starte_but = true;
void starte_callback(Fl_Widget* w , void* starte_but);
Fl_Button starte(150,350,75,75,"start");
//box explain
Fl_Box explain(100,10,100,200,"Explain");
Fl_Box ed(120,60,300,200,"First of all, the game will ask user the diffcult of the game. Then user will make certain of choice to compare the ramdom choice which computer make and get score.");



//--------------win2-----------------------
Fl_Window win2(1000,1000, "second");
//box
Fl_Box diffcult(100,10,100,200,"Which level would you like to play?");
//button1
bool l1_but = true;
void l1_callback(Fl_Widget* w , void* start_but);
Fl_Button l1(20,150,75,75,"Level 1");
Fl_Box dl1(20,230,75,200,"The top five score is \n ");




//button2
bool l2_but = true;
void l2_callback(Fl_Widget* w , void* start_but);
Fl_Button l2(100,150,75,75,"Level 2");
Fl_Box dl2(100,230,75,200,"The top five score is \n ");

//button3
bool l3_but = true;
void l3_callback(Fl_Widget* w , void* start_but);
Fl_Button l3(180,150,75,75,"Level 3");
Fl_Box dl3(180,230,75,200,"The top five score is \n ");
//button4
bool l4_but = true;
void l4_callback(Fl_Widget* w , void* start_but);
Fl_Button l4(260,150,75,75,"Level 4");
Fl_Box dl4(260,230,75,200,"The top five score is \n ");
//button5
bool l5_but = true;
void l5_callback(Fl_Widget* w , void* start_but);
Fl_Button l5(340,150,75,75,"Level 5");
Fl_Box dl5(340,230,75,200,"The top five score is \n ");















//--------------win21-----------------------
Fl_Window win21(500,500, "Diffcult 1");
//Fl_Box d1(100,20,100,300,"The top five score is \n ");

//--------------win22-----------------------
Fl_Window win22(500,500, "Diffcult 2");
//Fl_Box d2(100,20,100,300,"The top five score is \n ");
//--------------win23-----------------------
Fl_Window win23(500,500, "Diffcult 3");
//Fl_Box d3(100,20,100,300,"The top five score is \n ");
//--------------win24-----------------------
Fl_Window win24(500,500, "Diffcult 4");
//Fl_Box d4(100,20,100,300,"The top five score is \n ");
//--------------win25-----------------------
Fl_Window win25(500,500, "Diffcult 5");
//Fl_Box d5(100,20,100,300,"The top five score is \n ");














#endif //SPLASH_SCREEN