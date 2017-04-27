#ifndef P6_WINDOW
#define P6_WINDOW

//------------------------------------------------------------------------------

struct Part6_window : Fl_Window
{

Part6_window(int w, int h, const char* title);

void init_scores(); 


private:
	int elements;
	int x;
	int y;
	Fl_Box score1_txt;
	Fl_Box score2_txt;
	Fl_Box score3_txt;
	Fl_Box score4_txt;
	Fl_Box score5_txt;
	Fl_Box score6_txt;
	std::vector<std::vector<std::string> > score_read();
	std::vector<std::vector<std::string> > results;
	Fl_Button play_again;    // play again 
	Fl_Button quit_game;     // end game
	
	
	
	void write_file(); 

	static void quitgame_callback(Fl_Widget*, void*v); 
	static void playagain_callback(Fl_Widget*, void*v);
	
	const char* stats(int index, std::vector<std::vector<std::string> > results);
};


extern Part6_window finalscore;
#endif // P6_WINDOW
