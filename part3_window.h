#ifndef P3_WINDOW
#define P3_WINDOW

//------------------------------------------------------------------------------

struct Part3_window : Fl_Window
{

Part3_window(int w, int h, const char* title);
void init_scores(); 
Fl_Button enter_button;   // the "enter" button

private:
	int y;
	int x;
	Fl_Box score1_txt;
	Fl_Box score2_txt;
	Fl_Box score3_txt;
	Fl_Box score4_txt;
	Fl_Box score5_txt;
	Fl_Box score6_txt;
	Fl_Input inbox;
	Fl_Button start_game;     // the "quit" button
	std::vector<std::string> score;
	std::vector<std::string> initials;
	bool valid_initials_entered;

	std::vector<std::string> score_read();
	std::vector<std::string> initials_read();
	std::string file_write();
	
	void set_inbox_error();
	static void startgame_callback(Fl_Widget*, void*v); 
	static void enter_callback(Fl_Widget*, void*v);
	void change_label(std::vector<std::string> vecScore, std::vector<std::string> vecInit);
	const char* results(int index, std::vector<std::string> vec, std::vector<std::string> vec1);
};


extern Part3_window* scoreboard;
#endif // P3_WINDOW
