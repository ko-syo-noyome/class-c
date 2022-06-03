#include "window.h"
#include "math.h"

#include "PointXY.c"

#define DRAWING 1 // 1 enables drawing, 0 disables drawing

int main(int argc, char **argv)
{
    size(400, 300);
    title("circle");

    // // polar point
    // float r = 1.0; // radius
    // float t = 0.0; // theta

	struct Point *p = newPointRT(1.0, 0.0);



    // animation loop
    for (int i = 0;  i < 30;  ++i) { // repeat 30 times
	// r = 1.0; // reset point to centre
	Point_setR(p, 1.0);
	// t = 0.0;
	Point_setT(p, 0.0);
	while (Point_getR(p) < height/2) {   // expand until point hits edge
	    int npoints = Point_getR(p) * 8; // 2 * pi * radius, plus 25% extra
	    float step = 360.0 / npoints; // size of each angular step around the circumference
	    if (DRAWING) clear();
	    //t = 0.0; // reset theta
		Point_setT(p, 0.0);
	    while (npoints--) { // draw each of npoints
		if (DRAWING) {
		    float x = Point_getR(p) * cos(Point_getT(p)), y = Point_getR(p) * sin(Point_getT(p)); // get x and y from polar coordinates
		    drawPoint(width / 2 + x, height / 2 + y); // relative to centre
		}
		//t = Point_getT(p) + step; // increase angle around circumference
		Point_setT(p, Point_getT(p) + step);
	    }
	    if (DRAWING) delay(10);
	    //r = Point_getR(p) + 1.0; // increase radius of circumference
		Point_setR(p, Point_getR(p) + 1.0);
	}
    }
	

    return 0;
}
