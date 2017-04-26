#ifndef GAME_ALG
#define GAME_ALG

extern std::vector< std::vector<int> > choices;
extern int NUM_ROUNDS;
extern const char* label;

void blue_callback( Fl_Widget* w , void* choice);
void red_callback( Fl_Widget* w, void* choice);
void white_callback( Fl_Widget*w , void* choice);

void game_over();
void score_to_file(double points);
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
/****************IMAGES************************/
void backImage();
extern Fl_JPEG_Image image2;
extern Fl_JPEG_Image image3;
extern Fl_JPEG_Image image4;
extern Fl_Box background2;


/*****************************************************/
// number of rounds
extern Fl_Box rounds;
void num_rounds(); 

// timer
void time(Fl_Widget* w, void*);
void button_time(void *);
void timer(void *);

extern Fl_Button time_right;
extern Fl_Box time_left;

//continue 
void continue_button(Fl_Widget* w, void*);
extern Fl_Button continue_game;


#endif //GAME_ALG
