#include "part3_window.h"
#include "part3.h" 

using namespace Graph_lib;
//------------------------------------------------------------------------------
part3_window::part3_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
	inboxIn1(Point( 90 , 0), 40, 20, "Enter Initials"),
	test_out(Point(450 , 245), "6. "),
	test2_out(Point( 20 , 245),"6. "),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
   	enter_button (Point(130, 0), 70,20, "Enter", cb_enter),
	score1_txt(Point(20, 95), "1. "),
	score2_txt(Point(20, 125), "2. "),
	score3_txt(Point(20, 155), "3. "),
	score4_txt(Point(20, 185), "4. "),
	score5_txt(Point(20, 215), "5. "),
	numScore1_txt(Point(450, 95), "1. "),
	numScore2_txt(Point(450, 125), "2. "),
	numScore3_txt(Point(450, 155), "3. "),
	numScore4_txt(Point(450, 185), "4. "),
	numScore5_txt(Point(450, 215), "5. "),
	button_pushed(false)
{
/*********************textStyle***********************************/	
	test2_out.set_font(Graph_lib::Font::times_bold);
	test_out.set_font(Graph_lib::Font::times_bold);
/*********************textSze***********************************/	
	test_out.set_font_size(15);
	test2_out.set_font_size(15);
/*********************This is the cb for quit***********************************/
	test_out.set_color(Color::white);
	test2_out.set_color(Color::white);
/*********************attach***********************************/	
	attach (inboxIn1);
	attach(quit_button);
	attach(enter_button);
}
//------------------------------------------------------------------------------
bool part3_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
	//next_pushed = false;
	
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
	//return next_pushed;
}

//------------------------------------------------------------------------------
/*********************This is the cb for quit***********************************/
void part3_window::cb_quit(Address, Address pw)
// call Simple_window::next() for the window located at pw
/*********************This is the ref to quit***********************************/

{  
    reference_to<part3_window>(pw).quit();    
}
/*********************what to do when quit***********************************/

void part3_window::quit()
{
    button_pushed = true;
    hide();
}
//------------------------------------------------------------------------------
/*********************This is the cb for enter***********************************/

void part3_window::cb_enter(Address, Address pw)
// ca;; Simple_window::enter(address, address pw)
{
	reference_to<part3_window>(pw).enter();
	
}
/*********************This is the reference for enter***********************************/

//------------------------------------------------------------------------------
void part3_window::enter()
{
/*******************outPut***********************************/	
	string newInput;
	newInput = inboxIn1.get_string();
		if(newInput.empty())
			newInput = "---";
	ofstream file2("initTxtFile.txt", ios::out | ios::app | ios::binary);
		file2 << '\n' <<newInput ;
		file2.close();
/*******************************************************************************/	
/*******************************************************************************/	
	string x = inboxIn1.get_string();
	string y = "---";
//////////////////////////////////////////////////////////////////////////////
//////////////////////open text file/////////////////////////////////////
	string line;

	vector<string>vecInit;
	ifstream file1("initTxtFile.txt");
	 if (file1.is_open())
	 {
		// while (getline(file1, line))
		while(file1 >> line)
		 {
			 vecInit.push_back(line);
			 
		 }
		 file1.close();
	 }
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////		
	score1_txt.set_label("1. "+ vecInit[0]);
	score2_txt.set_label("2. "+ vecInit[1]);
	score3_txt.set_label("3. "+ vecInit[2]);
	score4_txt.set_label("4. "+ vecInit[3]);
	score5_txt.set_label("5. "+ vecInit[4]);
	test2_out.set_label("6. "+ x );
	test_out.set_label(" "+ y);
////////////////////////////////////////////////////////////////////////////////
///////////////////////Score textColor and style/////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////	
	score1_txt.set_color(Color::white);
	score2_txt.set_color(Color::white);
	score3_txt.set_color(Color::white);
	score4_txt.set_color(Color::white);
	score5_txt.set_color(Color::white);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////open text file/////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////	
	attach (score1_txt);
	attach (score2_txt);
	attach (score3_txt);
	attach (score4_txt);
	attach (score5_txt);
	attach (test2_out);
	attach (test_out);
	////////////////////////////////////////////////////////////////////////////////
////////////////////////////////open text file/////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	string line2;
	
	vector<string>vecScore;
	ifstream file3("scoretxtFile.txt");
		if(file3.is_open())
		{
			while(file3 >>line2)
			{
				vecScore.push_back(line2);
			}
		file3.close();
		}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////What the score is from the file///////////////////
	////////////////////////////////////////////////////////////////////////////////		
	numScore1_txt.set_label(vecScore[0]);
	numScore2_txt.set_label(vecScore[1]);
	numScore3_txt.set_label(vecScore[2]);
	numScore4_txt.set_label(vecScore[3]);
	numScore5_txt.set_label(vecScore[4]);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////text color for numScores/////////////////////////////
	////////////////////////////////////////////////////////////////////////////////	
	numScore1_txt.set_color(Color::white);
	numScore2_txt.set_color(Color::white);
	numScore3_txt.set_color(Color::white);
	numScore4_txt.set_color(Color::white);
	numScore5_txt.set_color(Color::white);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////attach numScore's/////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////	
	attach (numScore1_txt);
	attach (numScore2_txt);
	attach (numScore3_txt);
	attach (numScore4_txt);
	attach (numScore5_txt);	
		
	redraw();	
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

