#include "splash_screen.h" 
int main()
{
	backImage();
	start.callback(start_callback);
	starte.callback(starte_callback);

	l1.callback(l1_callback);
	l2.callback(l2_callback);
	l3.callback(l3_callback);
	l4.callback(l4_callback);
	l5.callback(l5_callback);
/*****************win***************************/
	rounds.box(FL_SHADOW_BOX);
	box.box(FL_SHADOW_BOX);
	score.box(FL_SHADOW_BOX);
/*****************Option1***************************/	
	red.deactivate();
	red.box(FL_NO_BOX);
	red.image(image2);
	red.labelcolor(FL_WHITE);
/*****************Option2***************************/	
	white.deactivate();
	white.box(FL_NO_BOX);
	white.image(image3);
	white.labelcolor(FL_WHITE);
/*****************Option3***************************/	
	blue.deactivate();
	blue.box(FL_NO_BOX);
	blue.image(image4);
	blue.labelcolor(FL_WHITE);
/********************************************/
	blue.callback(blue_callback);
	red.callback(red_callback);
        white.callback(white_callback);

	time_right.callback(time);
	box.box(FL_UP_BOX);

	win1.show();

	return Fl::run();

}
