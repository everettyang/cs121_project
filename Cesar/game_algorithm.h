#ifndef GAME_ALG
#define GAME_ALG
/*******************VECTORS*************************/
extern std::vector< std::vector<int> > choices;
extern int NUM_ROUNDS;
extern const char* label;
/****************DECLARATION OF BUTTON CALLBACKS****************************/
void blue_callback( Fl_Widget* w , void* choice); //CALLBACK LINKAGE TO blue() 
void red_callback( Fl_Widget* w, void* choice);
void white_callback( Fl_Widget*w , void* choice);
/****************DECLARATION OF FUNCTIONS IN GAME_ALG.CPP****************************/
void game_over();	//ENDS GAME
void score_to_file(double points); //ADD POINTS UP
void show_result();	//COUT SCORE
void show_countdown(int time);	//TIMER
void update_score(double points, double percent_correct); //KEEPS TRACK OF SCORE
int ai_predict(double total_choices); //CALCULATES PREDICTIONS
/*******************DECLARATION OF BUTTONS*************************/
extern Fl_Window win; //WINDOW
extern Fl_Button red; //BUTTON 1
extern Fl_Button white; //BUTTON 2
extern Fl_Button blue; //BUTTON 3
extern Fl_Box box; //DISPLAY OF SMALL INSTRUCT. BOX
extern Fl_Box score; //DISP OF SCORE BOX
extern Fl_Box comp_right; //DISP OF COMPUTER CORRECT BOX
/****************IMAGES************************/
void backImage();
extern Fl_JPEG_Image image2;
extern Fl_JPEG_Image image3;
extern Fl_JPEG_Image image4;
extern Fl_Box background2;
extern Fl_Box background3;   //////////////////////////////////////////
/*****************************************************/
extern Fl_Box rounds; // number of rounds DISP
void num_rounds(); 
// timer
void time(Fl_Widget* w, void*);
void button_time(void *);
void timer(void *);
/*****************************************************/
extern Fl_Button time_right;
extern Fl_Box time_left;
/*****************************************************/
#endif //GAME_ALG
