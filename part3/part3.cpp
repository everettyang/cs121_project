#include "part3_window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"
#include "Window.h"
#include "part3.h"

using namespace Graph_lib;

/*****************Creating the window************************/
	Point topCorner(100, 100);
		part3_window win{topCorner, 500, 300, "Game"}; /////////
		//topCorner.set_color(Color::cyan); 
		
		
		
	tracker::tracker()
	{
		//Polygon background;
	//background.add(Point{200,0});
	//background.add(Point{200,20});
	//background.add(Point{win.x_max()-70, 20});
	//background.add(Point{win.x_max()-70, 0});
	//background.set_fill_color(Color::white);
	/*****************Creating the backGround************************/
	Image backGround{Point{0 , 20},"uzumaki.jpg"};
		win.attach(backGround);
	/*****************button************************/
		win.wait_for_button();
	}

	
	