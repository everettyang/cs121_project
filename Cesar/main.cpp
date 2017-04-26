#include "splash_screen.h" 


int main()                     //initiate our main()
{
/*******************Background*************************/	
	backImage();
/*****************button***************************/	
	start.callback(start_callback);
/*****************next button***************************/		
	starte.callback(starte_callback);
	difficulty.box(FL_DOWN_FRAME);
	difficulty.labelsize(34);
	difficulty.color(FL_WHITE);
/*****************callbacks***************************/
	l1.callback(l1_callback);  //callback for scoreboard level1
	l1.box(FL_UP_BOX);
/*****************callbacks***************************/	
	l2.callback(l2_callback);  //callback for scoreboard level2
	l2.box(FL_UP_BOX);
/*****************callbacks***************************/	
	l3.callback(l3_callback);  //callback for scoreboard level3
	l3.box(FL_UP_BOX);
/*****************callbacks***************************/	
	l4.callback(l4_callback);  //callback for scoreboard level4
	l4.box(FL_UP_BOX);
/*****************callbacks***************************/	
	l5.callback(l5_callback);  //callback for scoreboard level5
	l5.box(FL_UP_BOX);
/*****************Part4 Window Display***************************/
	rounds.box(FL_SHADOW_BOX);
	box.box(FL_SHADOW_BOX);
	score.box(FL_SHADOW_BOX);
/*****************Option1***************************/	
	red.deactivate();  //deactivates the button until start
	red.box(FL_NO_BOX); 
	red.image(image2);
	red.labelcolor(FL_WHITE);
/*****************Option2***************************/	
	white.deactivate();  //deactivates the button until start
	white.box(FL_NO_BOX);
	white.image(image3);
	white.labelcolor(FL_WHITE);
/*****************Option3***************************/	
	blue.deactivate();  //deactivates the button until start
	blue.box(FL_NO_BOX);
	blue.image(image4);
	blue.labelcolor(FL_WHITE);
/***************Buttons Callbacks*****************************/
	blue.callback(blue_callback);
	red.callback(red_callback);
    white.callback(white_callback);
/***************time Callback*****************************/
	time_right.callback(time);
/********************************************/
	box.box(FL_UP_BOX);
/***************Shows the screen*****************************/
	win1.show();

	return Fl::run();
}
