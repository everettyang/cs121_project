#include "splash_screen.h"
Part3_window * scoreboard = new Part3_window(width,height,"Initials");

Part3_window::Part3_window(int w, int h, const char* title = 0) :

	Fl_Window(w,h,title),
	x{100},
	y{100},
	score1_txt(y, x, 125, 12),
	score2_txt(y, x + 100,125,12),
	score3_txt(y, x + 200,125,12),
	score4_txt(y, x + 300,125,12),
	score5_txt(y, x + 400,125,12),
	score6_txt(y, x + 500,125,12),
	inbox(90,0,150, 20, "Enter Initials"),
	start_game(w-70,0, 70, 20, "Start Game"),
   	enter_button(240, 0, 70,20, "Enter"),
   	valid_initials_entered(false)

{
	init_scores();
	enter_button.callback(enter_callback, this);
	start_game.callback(startgame_callback, this);
	end();
}

void Part3_window::init_scores()
{
	score = score_read();
	initials = initials_read();

	score1_txt.copy_label(results(0, initials, score));
	score2_txt.copy_label(results(1, initials, score));
	score3_txt.copy_label(results(2, initials, score));
	score4_txt.copy_label(results(3, initials, score));
	score5_txt.copy_label(results(4, initials, score));
	score6_txt.copy_label(results(5, initials, score));

}
std::vector<std::string> Part3_window::score_read()
{
	std::string line2;
	std::vector<std::string>vecScore(6, "---");
	std::ifstream file3("scoretxtFile.txt");
		if(file3.is_open())
		{
			for(int i = 0; i < vecScore.size(); ++i)
			{
				if (getline(file3, line2))
				{
					vecScore.at(i) = line2;
				}
			}
		file3.close();
		}

	//for (int i = 0; i < vecScore.size(); ++i) { std::cout << "vecScore in enter callback: " << vecScore[i] << std::endl; }
	return vecScore;

}

std::vector<std::string> Part3_window::initials_read()
{

	std::string line;

	std::vector<std::string>vecInit{6, "---"};

	std::ifstream file1("initials.txt");
	 if (file1.is_open())
	 {
		// while (getline(file1, line))
			for(int i = 0; i < vecInit.size(); ++i)
		 {
			if (getline(file1, line))
			{
				 vecInit.at(i) = line;
			}
			 
		 }
		 file1.close();
	 }
	//for (int i = 0; i < vecInit.size(); ++i) { std::cout << "vecInit in enter callback: " << vecInit[i] << std::endl; }
	return vecInit;

}

const char* Part3_window::results(int index, std::vector<std::string> initials, std::vector<std::string> score)
{
	std::stringstream ss;

	//if index is bigger than the initials list then its empty
	if (index > initials.size() - 1) ss << index + 1 << ". --- " << "\t\t" << "---"; 

	//if index is bigger than score list then its the new initial
	else if (index > score.size() - 1) ss << index + 1 << ". " << initials[index] << "\t\t" << "---"; 
	else ss << index + 1 << ". " << initials[index] << "\t\t" << score[index];   

	std::string temp = ss.str();
	const char* cstr = temp.c_str();
	std::cout << "results: " << cstr << std::endl;
	return cstr;

}

void Part3_window::set_inbox_error() { inbox.value("Enter valid initials!"); }

std::string Part3_window::file_write()
{
	std::string newInput = inbox.value();

	if (newInput.size() > 3 || newInput.empty())
	{
		set_inbox_error();
		return "error";
	}
	enter_button.deactivate();

	valid_initials_entered = true;

	std::ofstream file2("initials.txt", std::ios::app);
	file2 << newInput << '\n';
	file2.close();
	return newInput;

}

void Part3_window::startgame_callback(Fl_Widget*, void*v)
{
Part3_window * p3  = ((Part3_window *)v);

update_score(0,0);

if (!(p3->valid_initials_entered))
{
	p3->set_inbox_error();
	return;
}

	p3->hide();
	win.show();
}

void Part3_window::change_label(std::vector<std::string> vecScore, std::vector<std::string> vecInit)
{
	score1_txt.copy_label(results(0, vecInit, vecScore));
	score2_txt.copy_label(results(1, vecInit, vecScore));
	score3_txt.copy_label(results(2, vecInit, vecScore));
	score4_txt.copy_label(results(3, vecInit, vecScore));
	score5_txt.copy_label(results(4, vecInit, vecScore));
	score6_txt.copy_label(results(5, vecInit, vecScore));

}
void Part3_window::enter_callback(Fl_Widget*, void* v)
{

	std::cout << "enter_callback" << std::endl;
	Part3_window* p3 = ((Part3_window*)v);
	//newinput is for input checking
	std::string newInput = p3->file_write();
	if (newInput == "error") return;
	std::vector<std::string> vecScore = p3->score_read();
	std::vector<std::string> vecInit = p3->initials_read();
	p3->change_label(vecScore, vecInit);
	
}

