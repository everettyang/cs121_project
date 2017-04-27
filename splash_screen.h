#ifndef SPLASH_SCREEN
#define SPLASH_SCREEN

#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_JPEG_Image.H>
#include <time.h>
#include "game_algorithm.h" 
#include "part3_window.h" 
#include "part6_window.h"
//---------------win1----------------------------
extern int points;
extern Fl_Window win1;
//buttton
void start_callback(Fl_Widget* w , void* start_but);
extern Fl_Button start;
//box
extern int width,height;
extern Fl_Box name;
extern Fl_Box teamm;
extern Fl_Box teamn;
extern Fl_Box teamname;

extern Fl_Box animation;
extern Fl_Box animation1;
extern Fl_Box background;
extern Fl_JPEG_Image bg;
extern Fl_GIF_Image image;
extern Fl_GIF_Image image1;
//---------------winexplain----------------------------
extern Fl_Window wine;
//button
void starte_callback(Fl_Widget* w , void* starte_but);
extern Fl_Button starte;
//box explain
extern Fl_Box explain;
extern Fl_Box ed;

//--------------win2-----------------------
extern Fl_Window win2;
//box
extern Fl_Box difficulty;
//button1
void l1_callback(Fl_Widget* w , void* start_but);
extern Fl_Button l1;
//button2
void l2_callback(Fl_Widget* w , void* start_but);
extern Fl_Button l2;
//button3
void l3_callback(Fl_Widget* w , void* start_but);
extern Fl_Button l3;
//button4
void l4_callback(Fl_Widget* w , void* start_but);
extern Fl_Button l4;
//button5
void l5_callback(Fl_Widget* w , void* start_but);
extern Fl_Button l5;
void animate(void *);
//--------------win21-----------------------
extern Fl_Window win21;
//extern Fl_Box d1(100,20,100,300,"The top five score is \n ");
//--------------win22-----------------------
extern Fl_Window win22;
//extern Fl_Box d2(100,20,100,300,"The top five score is \n ");
//--------------win23-----------------------
extern Fl_Window win23;
//extern Fl_Box d3(100,20,100,300,"The top five score is \n ");
//--------------win24-----------------------
extern Fl_Window win24;
//extern Fl_Box d4(100,20,100,300,"The top five score is \n ");
//--------------win25-----------------------
extern Fl_Window win25;
//extern Fl_Box d5(100,20,100,300,"The top five score is \n ");
void animate(void*);
void animate_helper(int x, int y);

#endif //SPLASH_SCREEN
