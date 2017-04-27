#include "splash_screen.h"

Part6_window::Part6_window(int w, int h, const char* title = 0) :

	Fl_Window(w,h,title),
	elements{0},
	x{95},
	y{95},
	score1_txt(x,y, 125, 12),
	score2_txt(x, y + 100,125,12),
	score3_txt(x, y + 200,125,12),
	score4_txt(x, y + 300,125,12),
	score5_txt(x, y + 400,125,12),
	score6_txt(x,y + 500,125,12),
	results(6, std::vector<std::string>(2,"---")),
	play_again(300,700, 150, 20, "Continue game"),
   	quit_game(470, 700, 150,20, "End game")
{
	init_scores();
	play_again.callback(playagain_callback, this);
	quit_game.callback(quitgame_callback, this);
	end();
}	
void Part6_window::write_file()
{
	for (int i = 0; i <= elements; ++i)
	{
		//clears files
	std::cout << "i: " << i << std::endl;
		system("> scoretxtFile.txt");
		system("> initials.txt");
	std::cout << "score" << std::endl;
		std::ofstream file("scoretxtFile.txt");
		std::ofstream file1("initials.txt");
		file << results[i][1] << '\n';
		file1 << results[i][0] << '\n';
		file.close();
		file1.close();
	}

}
void Part6_window::init_scores()
{
	score_read();
	std::cout << "init_score" << std::endl;
	if (!(results.size() < 2))
	std::sort(results.begin(), results.end() - 1, [](const std::vector<std::string>& a,const std::vector<std::string>& b) {return a[1] > b[1];} );
	std::cout << "init_score1" << std::endl;
	
	score1_txt.copy_label(stats(0, results));
	score2_txt.copy_label(stats(1, results));
	score3_txt.copy_label(stats(2, results));
	score4_txt.copy_label(stats(3, results));
	score5_txt.copy_label(stats(4, results));
	score6_txt.copy_label(stats(5, results));
}
std::vector<std::vector<std::string> > Part6_window::score_read()
{
	std::string line;

	std::ifstream file1("initials.txt");
	 if (file1.is_open())
	 {
		for(int i = 0; i < results.size(); ++i)
		{
			if (getline(file1, line))
			{
			
		std::cout << line  << std::endl;
			 results[i][0] = line;
			elements++;
			}
		}
		 file1.close();
	 }
	
	std::string line2;
	std::cout << "score read mid" << std::endl;
	std::ifstream file3("scoretxtFile.txt");
		if(file3.is_open())
		{
		
			for(int i = 0; i < results.size(); ++i)
			{
				if(getline(file3, line2))
				{
				results[i][1] = line2;
				}
				
			}
		file3.close();
		}
	std::cout << "score read end" << std::endl;

	return results;

}
const char* Part6_window::stats(int index, std::vector<std::vector<std::string> > results)
{
	std::stringstream ss;

	//if index is bigger than the initials list then its empty
	if (index > results.size() - 1) ss << index + 1 << ". --- " << "\t\t" << "---"; 

	//if index is bigger than score list then its the new initial
	else if (index > results.size() - 1) ss << index + 1 << ". " << results[index][0] << "\t\t" << "---"; 
	else ss << index + 1 << ". " << results[index][0] << "\t\t" << results[index][1];   

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
	((Part6_window*)v)->hide();
	win2.show();	
	continue_game.deactivate();
	((Part6_window*)v)->write_file();
}

void Part6_window::quitgame_callback(Fl_Widget*, void*v)
{
	((Part6_window*)v)->hide();
	((Part6_window*)v)->write_file();
}
