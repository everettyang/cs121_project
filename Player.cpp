#include "std_lib_facilities_4.h"
#include "Player.h"
Player::Player(string name, int score) : name(initial), int(score) {}

void set_init(string name){
	this->initial = name;
}

void set_score(int score){
	this->score = score;
}