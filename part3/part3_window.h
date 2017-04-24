
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup


#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct part3_window : Graph_lib::Window 
	{
    part3_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

private:


/*********BUTTONS***********/	
    Button quit_button;     // the "quit" button
	Button enter_button;   // the "enter" button
/**********BOXS**************/	
	Text test_out;
	Text test2_out;
	In_box inboxIn1;
/****************************START txt score************************************/    
	Text score1_txt;
	Text score2_txt;
	Text score3_txt;
	Text score4_txt;
	Text score5_txt;
	Text numScore1_txt;
	Text numScore2_txt;
	Text numScore3_txt;
	Text numScore4_txt;
	Text numScore5_txt;
/*-------------START txt initials-------------------*/	

/***********START FUNCTION*********/    
	bool button_pushed;     // implementation detail

    static void cb_quit(Address, Address); // callback for next_button
    void quit();            // action to be done when next_button is pressed
	
	static void cb_enter(Address, Address);
	void enter();
	};

//------------------------------------------------------------------------------

//#endif // SIMPLE_WINDOW_GUARD
