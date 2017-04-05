#ifndef PLAYER
#define PLAYER

#include<string>


class Player {
public:
	int getInitial() const {return initial;}
	std::string getScore() const {return score;}
	void set_score(int current) {};
private:
	int score;
	std::string initial; 
}


#endif