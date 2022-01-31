//	file:	homework2.cpp
//	by:		Austin Hood
//	org:	COP 2001, 10410
//	desc:	main header file for graphing tool
// -----------------------------------------------------------------------------

#ifndef MAIN_H
#define MAIN_H

//includes
#include <string>	//for window title

//global constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Graphing Tool";

//global data structures
enum Mode
{
	TWO_POINT = 1,
	POINT_SLOPE = 2,
	EXIT = 3
};

#endif //MAIN_H
