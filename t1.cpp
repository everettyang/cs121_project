
#include "game.h"



void start_callback(Fl_Widget* , void *) {
	if (start_but)
	{
	
	win1.hide();
	win2.show();
	}
	
	
}

void l1_callback(Fl_Widget* , void *) {
	if (l1_but)
	{
	win2.hide();
	win21.show();
	
	}
	
	
}

void l2_callback(Fl_Widget* , void *) {
	if (l2_but)
	{
	win2.hide();
	win22.show();
	
	}
	
	
}
	
void l3_callback(Fl_Widget* , void *) {
	if (l3_but)
	{
	win2.hide();
	win23.show();
	
	}
	
	
}
void l4_callback(Fl_Widget* , void *) {
	if (l4_but)
	{
	win2.hide();
	win24.show();
	
	}
	
	
}
void l5_callback(Fl_Widget* , void *) {
	if (l5_but)
	{
	win2.hide();
	win25.show();
	
	}
	
	
}
	
	


	
	
	int  main(){
		
		win1.show();
		start.callback(start_callback);
		
		l1.callback(l1_callback);
		l2.callback(l2_callback);
		l3.callback(l3_callback);
		l4.callback(l4_callback);
		l5.callback(l5_callback);
		
		
		
		
		return Fl::run();
		
	
	}