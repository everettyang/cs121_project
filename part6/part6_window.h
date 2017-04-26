#ifndef P6_WINDOW
#define P6_WINDOW

//------------------------------------------------------------------------------

struct Part6_window : Fl_Window
{

Part6_window(int w, int h, const char* title);

	

private:
	int txt_height;
	Fl_Box score1_txt;
	Fl_Box score2_txt;
	Fl_Box score3_txt;
	Fl_Box score4_txt;
	Fl_Box score5_txt;
	Fl_Box score6_txt;
	
	Fl_Button quit_game;     // end game
	Fl_Button play_again;    // play again 
	
	std::vector<std::string> score_read();
	std::vector<std::string> initials_read();
	
	std::vector<std::string> score;
	std::vector<std::string> initials;
	
	void init_scores(); 

	static void quitgame_callback(Fl_Widget*, void*v); 
	static void playagain_callback(Fl_Widget*, void*v);
	
	const char* results(int index, std::vector<std::string> vec, std::vector<std::string> vec1);
};


extern Part6_window finalscore;
#endif // P6_WINDOW
