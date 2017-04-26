#ifndef P3_WINDOW
#define P3_WINDOW

//------------------------------------------------------------------------------
struct Part3_window : Fl_Window
{
/*******************Window Canvas*************************/
Part3_window(int w, int h, const char* title);
/*******************************************************/
private:
/***************Initiate Variables/Vectors***********************/
	int y;
	int x;
	Fl_Box score1_txt;
	Fl_Box score2_txt;
	Fl_Box score3_txt;
	Fl_Box score4_txt;
	Fl_Box score5_txt;
	Fl_Box score6_txt;
	Fl_Input inbox;
	Fl_Button start_game;           // the "start" button
	Fl_Button enter_button;         // the "enter" button
	std::vector<std::string> score; //score vector 
	std::vector<std::string> initials; //initials vector
	bool valid_initials_entered;      //Make sure they input appr. numb of char.
/***************Open files and input into vectors************************/
	std::vector<std::string> score_read();
	std::vector<std::string> initials_read();
	std::string file_write();
/*******************************************************/	
	void set_inbox_error();		//
	void init_scores(); 		//
/****************Game Callbacks***********************/	
	static void startgame_callback(Fl_Widget*, void*v); 
	static void enter_callback(Fl_Widget*, void*v);
	void change_label(std::vector<std::string> vecScore, std::vector<std::string> vecInit);//reads vectors
	const char* results(int index, std::vector<std::string> vec, std::vector<std::string> vec1);//reads vectors
};
/*****************Show Window**************************/
extern Part3_window scoreboard;
#endif // P3_WINDOW
