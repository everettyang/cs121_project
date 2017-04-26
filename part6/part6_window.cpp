#include "splash_screen.h"

Part6_window finalscore(width, height, "Final scores"); 

Part6_window::Part6_window(int w, int h, const char* title = 0) :

	Fl_Window(w,h,title),
	txt_height{95},
	score1_txt(50,txt_height, 125, 12),
	score2_txt(50, txt_height + 100,125,12),
	score3_txt(50, txt_height + 200,125,12),
	score4_txt(50, txt_height + 300,125,12),
	score5_txt(50, txt_height + 400,125,12),
	score6_txt(50,txt_height + 500,125,12),
	play_again(300,700, 150, 20, "Continue game"),
   	quit_game(470, 700, 150,20, "End game")
{
	init_scores();
	play_again.callback(playagain_callback, this);
	quit_game.callback(quitgame_callback, this);
	end();
}	

void Part6_window::init_scores()
{
	std::string temp;
	std::string tempI;
	score = score_read();
	initials = initials_read();
	for(int i = score.size()-1; i > 0; i--){
		
		if(std::stoi(score.at(i),nullptr,0) > std::stoi(score.at(i-1)),nullptr,0){
			temp = score.at(i);
			score.at(i)=score.at(i-1);
			score.at(i-1) = temp;
			tempI = initials.at(i);
			initials.at(i)=initials.at(i-1);
			initials.at(i-1)=tempI;
		}
	}
	
	score1_txt.copy_label(results(0, initials, score));
	score2_txt.copy_label(results(1, initials, score));
	score3_txt.copy_label(results(2, initials, score));
	score4_txt.copy_label(results(3, initials, score));
	score5_txt.copy_label(results(4, initials, score));
	score6_txt.copy_label(results(5, initials, score));
}
std::vector<std::string> Part6_window::score_read()
{
	std::string line2;
	std::vector<std::string>vecScore;
	std::ifstream file3("scoretxtFile.txt");
		if(file3.is_open())
		{
			while(getline(file3, line2))
			{
				vecScore.push_back(line2);
			}
		file3.close();
		}

	return vecScore;

}

std::vector<std::string> Part6_window::initials_read()
{
	std::string line;

	std::vector<std::string>vecInit;

	std::ifstream file1("initials.txt");
	 if (file1.is_open())
	 {
		while(getline(file1, line))
		 {
			 vecInit.push_back(line);
		 }
		 file1.close();
	 }
	return vecInit;

}

const char* Part6_window::results(int index, std::vector<std::string> initials, std::vector<std::string> score)
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



void Part6_window::playagain_callback(Fl_Widget*, void* v)
{
	NUM_ROUNDS = 32;
	points = 0;
	time_right.activate();
	finalscore.hide();
	win2.show();	
	continue_game.deactivate();
}

void Part6_window::quitgame_callback(Fl_Widget*, void*v)
{
	finalscore.hide();
}
