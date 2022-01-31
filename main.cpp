//	file:	main.cpp
//	by:		Austin Hood
//	org:	COP 2001, 10410
//	desc:	main application file for graphing tool
// -----------------------------------------------------------------------------

//includes
#include <iostream>		
#include <iomanip>
#include <string>
#include <math.h>
#include "main.h"
#include "line.h"

//includes for opengl
#include "fgcugl.h"

int main()
{
	Mode mode;

	do
	{
		Line line;
		mode = getProblem();

		//mode specific calls
		if (mode == TWO_POINT)
		{
			get2Point(line);
		}
		else if (mode == POINT_SLOPE)
		{
			getPointSlope(line);
		}

		//common line code
		if (mode != EXIT)
		{

			displayLine(line);

			if (mode == TWO_POINT)
			{
				display2pt(line);
			}
			else if (mode == POINT_SLOPE)
			{
				displayPointSlope(line);
			}

			displaySlopeIntercept(line);
			drawLine(line);

		}

	} while (mode != EXIT);

	return 0;

}	//end main


Mode getProblem()
{

	Mode mode;

	//output menu
	std::cout << "Select the form that you would like to convert to slope intercept form: \n";
	std::cout << "\t1) Two-point form (you know the two points of the line) \n";
	std::cout << "\t2) Point-slope form (you know the line's slope and one point) \n";
	std::cout << "\t3) exit\n";

	int input;

	std::cin >> input;

	//get user input for choice
	mode = static_cast<Mode>(input);

	return mode;

}

Point getPoint()
{

	Point point;

	std::cout << "\nEnter the X coordinate / Y coordinate: \n";
	std::cin >> point.getXCoord() >> point.getYCoord();

	return point;

}

void get2Point(Line& line)
{

	std::cout << "\nEnter the first point: \n";
	line.setPoint1(getPoint());

	std::cout << "\nEnter the second point: \n";
	line.setPoint2(getPoint());

	//calculation and setting
	line.calcSlope();
	line.setSlope();

}

void getPointSlope(Line& line)
{
	line.setPoint1(getPoint());

	std::cout << "\nEnter slope: ";
	line.getSlope();
	line.setSlope();

	float yInt = line.calcYint();
	line.setPoint2.setX(0, yInt);

}

void displayLine(Line line)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nline: \n";
	std::cout << "\tPt-1: (" << line.point1.getXCoord() << " ," << line.point1.getYCoord() << ")\n";
	std::cout << "\tPt-2: (" << line.point2.getXCoord() << " ," << line.point2.getYCoord() << ")\n";
	std::cout << "\t Slope =  " << line.getSlope();
	std::cout << "\n\t Length =  " << line.calcLength();
	std::cout << "\n\t Degrees =  " << line.calcAngle();
}

void display2pt(Line line)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\n\t2-pt Form: \n";
	std::cout << "\n\t    (: " << line.point2.getYCoord() << " ," << line.point1.getYCoord() << ")\n";
	std::cout << "\n\tm = -------------------------------------------------------------: \n";
	std::cout << "\n\t    (: " << line.point2.getXCoord() << " ," << line.point1.getXCoord() << ")\n";

}

void displayPointSlope(Line line)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nPoint Slope Form: \n";
	std::cout << "\n\ty - " << line.point1.getYCoord() << " = " << line.getSlope() << "(x - " << line.point1.getXCoord();
}

void displaySlopeIntercept(Line line)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nSlope Intercept Form: \n";
	std::cout << "\n\ty = " << line.getSlope() << " + " << line.getYInt();
}

void drawLine(Line line)
{

	fgcugl.openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	while (!fgcugl::windowClosing())
	{

		//x axis
		fgcugl::drawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2);

		//y axis
		fgcugl::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);

		//plot line
		fgcugl::drawLine(line.point1.xCoord + WINDOW_WIDTH / 2, line.point1.yCoord + WINDOW_HEIGHT / 2, line.point2.xCoord + WINDOW_WIDTH / 2, line.point2.yCoord + WINDOW_HEIGHT / 2);

		fgcugl::windowPaint();

		fgcugl::getEvents();

	}

	fgcugl::cleanup();
}
