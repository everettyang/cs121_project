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
