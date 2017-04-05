#ifndef GAME_ALG
#define GAME_ALG

#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <time.h>


std::vector<std::vector<int>> choices{{0,1},{0,2},{0,3},{0}};
int NUM_ROUNDS = 32;

void game_over(double total_choices);
void blue_callback(Fl_Widget* w , void* choice);
void red_callback(Fl_Widget* w, void* choice);
void white_callback(Fl_Widget*w , void* choice);
void show_result();
void update_score(double points, double percent_correct);
int ai_predict(double total_choices);

Fl_Window win(500,500, "Guessing Game");
Fl_Button red(250,350,75,75, "Red");
Fl_Button white(350,350,75,75, "White");
Fl_Button blue(150,350,75,75,"Blue");
Fl_Box box(50,50,200,200,"Choose an option");
Fl_Box score(400,400,100,100,"Points: 0");
Fl_Box comp_right(300,100,100,100,"Percent computer correct:\n\t0%");

#endif //GAME_ALG
