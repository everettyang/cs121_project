#include "splash_screen.h"

Part6_window finalscore(width,height,"Final Score");

Part6_window::Part6_window(int w, int h, const char* title = 0) :
	//constructs window and the boxes for score entries
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
	//attach callbacks
	play_again.callback(playagain_callback, this);
	quit_game.callback(quitgame_callback, this);
	end();
}	

void Part6_window::write_file()
{
	//prepends '> ' to the file name
	std::ofstream file;
	std::ofstream file1;

	std::string arrow = "> ";
	std::string i = arrow + initial_file;
	std::string s = arrow + score_file;
	const char* initials = i.c_str();
	const char* scores = s.c_str();
	//uses bash to clear score and initial files
	system(scores);
	system(initials);

	if (elements > 5){ elements = 5;}

	for (int i = 0; i < elements; ++i)
	{
		//puts results into file
		file.open(score_file, std::ios::app);
		file1.open(initial_file, std::ios::app);

		file << results[i][1] << std::endl;
		file1 << results[i][0] << std::endl;

		file.close();
		file1.close();
	}

}

void Part6_window::init_scores()
{
	//shows the final score screen by updating all the boxes on score screen
	score_read();
	if (!(results.size() < 2))
	std::sort(results.begin(), results.end() - 1, [](const std::vector<std::string>& a,const std::vector<std::string>& b) {return a[1] > b[1];} );
	
	//change the lables on the score boxes
	score1_txt.copy_label(stats(0, results));
	score2_txt.copy_label(stats(1, results));
	score3_txt.copy_label(stats(2, results));
	score4_txt.copy_label(stats(3, results));
	score5_txt.copy_label(stats(4, results));
	score6_txt.copy_label(stats(5, results));
}

std::vector<std::vector<std::string> > Part6_window::score_read()
{
	//reads from score and initial file

	std::string line;
	elements += 1;

	std::ifstream file1(initial_file);
	 if (file1.is_open())
	 {
		for(int i = 0; i < results.size(); ++i)
		{
			if (getline(file1, line))
			{
			
			results[i][0] = line;
			}
		}
		 file1.close();
	 }
	
	//assigns the second index of column to score
	std::string line2;
	std::ifstream file3(score_file);
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

	//converts to cstr
	std::string temp = ss.str();
	const char* cstr = temp.c_str();
	std::cout << "part 6 results: " << cstr << std::endl;
	return cstr;

}

void Part6_window::update_part3()
{
	//updates initials scoreboard
	scoreboard->score1_txt.copy_label(stats(0, results));
	scoreboard->score2_txt.copy_label(stats(1, results));
	scoreboard->score3_txt.copy_label(stats(2, results));
	scoreboard->score4_txt.copy_label(stats(3, results));
	scoreboard->score5_txt.copy_label(stats(4, results));
	scoreboard->score6_txt.copy_label(stats(5, results));
}
 
void Part6_window::playagain_callback(Fl_Widget*, void* v)
{
	//casts void pointer to Part6_window pointer
        Part6_window* p6 = (Part6_window*)v;
	//resets all global variables for rounds and points
	NUM_ROUNDS = 32;
	points = 0;
	//activates the next round button
	time_right.activate();
	p6->hide();

	//turns on the enter button for initial input
	scoreboard->enter_button.activate();
	scoreboard->init_scores();

	//shows difficulty selector and deactivates the play again button
	win2.show();	
	continue_game.deactivate();

	//writes to file and updates part 3
	p6->write_file();
	p6->update_part3();

	}

void Part6_window::quitgame_callback(Fl_Widget*, void*v)
{
	//hides part 6 window and writes sorted top scores to file
	((Part6_window*)v)->hide();
	((Part6_window*)v)->write_file();
}
