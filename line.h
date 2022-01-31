//	file:	line.h
//	by:		Austin Hood
//	org:	COP 2001, 10410
//	desc:	declaration of a line class object
// -----------------------------------------------------------------------------

#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line
{
public:
	//constructors
	// -----------------------------------------------------------------------------
	Line();
	Line(Point point1, Point point2);
	Line(Point point, float slope);

	//accesors
	// -----------------------------------------------------------------------------
	//getters
	Point getPoint1();	
	Point getPoint2();
	float getSlope();

	//setters
	void setPoint1(Point value);
	void setPoint2(Point value);
	void setSlope(float value);

	//member methods
	// -----------------------------------------------------------------------------
	float diffX();
	float diffY();
	float calcSlope();
	float calcYint();
	float calcLength();
	float calcAngle();

private:
	Point point1;
	Point point2;
	float slope;

};

#endif //LINE_H
