//	file:	line.cpp
//	by:		Austin Hood
//	org:	COP 2001, 10410
//	desc:	implementation of a line class object
// -----------------------------------------------------------------------------

#define _USE_MATH_DEFINES    //endable M_PI

//includes
#include <iostream>		
#include <iomanip>
#include <string>
#include <math.h>
#include "line.h"

//constructors
// -----------------------------------------------------------------------------
//default constructor - initalize empty block
Line::Line()
{
	point1 = Point();
	point2 = Point();
	slope = 0.0;

}

//properties constructor - initalize to parameter values
Line::Line(Point point1, Point point2)
{
	this->point1 = point1;
	this->point2 = point2;
}

//properties constructor - initalize to parameter values
Line::Line(Point point1,float slope)
{
	this->point1 = point1;
	this->slope = slope;
}

//accessors
// -----------------------------------------------------------------------------
//getters
Point Line::getPoint1() { return point1; }
Point Line::getPoint2() { return point2; }
float Line::getSlope() { return slope; }

//setters
void Line::setPoint1(Point value) 
{ 
	this -> point1 = value; 
}

void Line::setPoint2(Point value) 
{ 
	this->point2 = value;
}

void Line::setSlope(float value)
{
	this->slope = value;
}

//member methods
// -----------------------------------------------------------------------------
float Line::diffX() 
{
	float diffX = (point2.getXCoord() - point1.getXCoord());
	return diffX;

}


float Line::diffY()
{
	float diffY = (point2.getYCoord() - point1.getYCoord());
	return diffY;
}

/*
 calculates the slope and returns a float slope value

 Parameters:
 diffX			xCoord,xCoord	-    difference in both x coordinates
 diffY			yCoord,yCoord	-    difference in both y coordinates
 */
float Line::calcSlope()
{
	slope = diffY() / diffX();
	return slope;
}

/*
 calculates the yIntercept and returns a float yInt value

 Parameters:
 yInt			(0,yInt)	
 */
float Line::calcYint() 
{
	float yInt = point1.getYCoord() - (slope * point1.getXCoord());
	return yInt;

}

/*
 calculates the length and returns a float distance value

 Parameters:
 diffX			xCoord,xCoord
 diffY			yCoord,yCoord
 */
float Line::calcLength() 
{
	float distance = sqrt(pow(diffX(), 2) + pow(diffY(), 2));
	return distance;
}

/*
 calculates the angle and returns a float cardinal value

 Parameters:
 diffX			xCoord,xCoord
 diffY			yCoord,yCoord
 */
float Line::calcAngle() 
{
	float radians = atan2(diffY(), diffX());
	float angle = radians * 180.0 / M_PI;
	float degrees = 90.0 - angle;
	float cardinal = (degrees > 0.0 ? degrees : degrees + 360.0);
	return cardinal;
}

