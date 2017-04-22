#include "splash_screen.h" 
int main()
{
	animation.image(image);
	animation1.image(image1);

	animation1.hide();
	animation.set_changed();
	background.image(bg);
	Fl::add_timeout(.05, animate);

	start.callback(start_callback);
	starte.callback(starte_callback);
	ed.label("First, the game will ask the user to select the difficulty. \n The computer will try to guess the user's choice. \nIf the computer guesses wrong then the user gets 10 points.\n The number of rounds vary based on difficulty.\n In the end, the user will be shown how his/her score ranks among the top 5 scores.");

	dl1.label("Top five\n ");
	dl2.label("Top five\n ");
	dl3.label("Top five\n ");
	dl4.label("Top five\n ");
	dl5.label("Top five\n ");

	l1.callback(l1_callback);
	l2.callback(l2_callback);
	l3.callback(l3_callback);
	l4.callback(l4_callback);
	l5.callback(l5_callback);

	red.deactivate();
	white.deactivate();
	blue.deactivate();

	blue.callback(blue_callback);
	red.callback(red_callback);
        white.callback(white_callback);

	time_right.callback(time);
	box.box(FL_UP_BOX);

	win1.show();

	return Fl::run();

}
