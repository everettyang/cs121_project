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


extern std::vector< std::vector<int> > choices;
extern int NUM_ROUNDS;
extern const char* label;

void blue_callback( Fl_Widget* w , void* choice);
void red_callback( Fl_Widget* w, void* choice);
void white_callback( Fl_Widget*w , void* choice);

void game_over();
void show_result();
void show_countdown(int time);
void update_score(double points, double percent_correct);
int ai_predict(double total_choices);


extern Fl_Window win;
extern Fl_Button red;
extern Fl_Button white;
extern Fl_Button blue;
extern Fl_Box box;
extern Fl_Box score;
extern Fl_Box comp_right;

// number of rounds
extern Fl_Box rounds;
void num_rounds(); 

// timer
void time(Fl_Widget* w, void*);
void button_time(void *);
void timer(void *);

extern Fl_Button time_right;
extern Fl_Box time_left;


#endif //GAME_ALG
