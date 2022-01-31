//	file:	point.h
//	by:		Austin Hood
//	org:	COP 2001, 10410
//	desc:	declaration of a point class object
// -----------------------------------------------------------------------------

#ifndef POINT_H
#define POINT_H

#include "fgcugl.h"

class Point
{
public:
	//constructors
	// -----------------------------------------------------------------------------
	Point();
	Point(float xCoord, float yCoord);

	//accesors
	// -----------------------------------------------------------------------------
	//getters
	float getXCoord();
	float getYCoord();

	//setters
	void setXCoord(float value);
	void setYCoord(float value);

private:
	float xpos;
	float ypos;
};


#endif // POINT_H
