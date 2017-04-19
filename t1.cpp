
#include "game.h"
#include "game_algorithm.h"





//score




//how to play game
//team detail


void start_callback(Fl_Widget* , void *) {
	if (start_but)
	{
	
	win1.hide();
	wine.show();
	}
	
	
}

void starte_callback(Fl_Widget* , void *) {
	if (starte_but)
	{
	
	wine.hide();
	win2.show();
	}
	
	
}

void l1_callback(Fl_Widget* , void *) {
	if (l1_but)
	{
	win2.hide();
	win21.show();
	NUM_ROUNDS = NUM_ROUNDS * 1;
	}
	
	
}

void l2_callback(Fl_Widget* , void *) {
	if (l2_but)
	{
	win2.hide();
	win22.show();
	NUM_ROUNDS = NUM_ROUNDS * 2;
	}
	
	
}
	
void l3_callback(Fl_Widget* , void *) {
	if (l3_but)
	{
	win2.hide();
	win23.show();
	NUM_ROUNDS = NUM_ROUNDS * 3;
	}
	
	
}
void l4_callback(Fl_Widget* , void *) {
	if (l4_but)
	{
	win2.hide();
	win24.show();
	NUM_ROUNDS = NUM_ROUNDS * 4;
	}
	
	
}
void l5_callback(Fl_Widget* , void *) {
	if (l5_but)
	{
	win2.hide();
	win25.show();
	NUM_ROUNDS = NUM_ROUNDS * 5;
	}
	
	
}
	
	


	
	
	int  main(){
		
		win1.show();
		start.callback(start_callback);
		starte.callback(starte_callback);
		ed.label("How to play game");
		
		l1.callback(l1_callback);
		l2.callback(l2_callback);
		l3.callback(l3_callback);
		l4.callback(l4_callback);
		l5.callback(l5_callback);
		
		
		
		
		return Fl::run();
		
	
	}