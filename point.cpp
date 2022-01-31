//	file:	point.cpp
//	by:		Austin Hood
//	org:	COP 2001, 10410
//	desc:	implementation of a point class object
// -----------------------------------------------------------------------------
#include "point.h"

//constructors
// -----------------------------------------------------------------------------
//default constructor - initalize empty block
Point::Point()
{
	xpos = 0;
	ypos = 0;
	
}

//properties constructor - initalize to parameter values
Point::Point(float x, float y)
{
	xpos = x;
	ypos = y;
	
}

// -----------------------------------------------------------------------------
//getters
float Point::getXCoord() { return xpos; }
float Point::getYCoord() { return ypos; }


//setters
void Point::setXCoord(float value) { xpos = value; }
void Point::setYCoord(float value) { ypos = value; }




