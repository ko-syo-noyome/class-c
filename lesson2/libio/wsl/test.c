#include "window.h"

#include <stdio.h>
#include <math.h>

#define NSHAPES 10
#define degrees / 180.0 * M_PI  // suffix converting degrees to radians

#define frand()			((double)rand() / (((double)RAND_MAX) + 1))
#define randint(MIN, MAX)	(MIN + (int)(frand() * ((MAX) - (MIN))))

struct Shape
{
    int    nPoints, angle;  // number of vertices and angle at each vertex
    int    x, y, r, a;      // position, radius, rotation angle
    int    dx, dy, dr, da;  // speed of motion, radius change, angle change
    Colour stroke, fill;    // outline and fill colours
};

struct Shape makeShape(int x, int y, int r, int nPoints, int angle)
{
    return (struct Shape) {
        nPoints, angle,
        x, y, r, 0,
	// movement, expansion, and rotation speeds are random
        randint(-2, 3), randint(-2, 3), randint(-1, 2), randint(-8, 9),
	// border and interior colours are random
        RGB(randint(0, 256), randint(0, 256), randint(0, 256)),
        RGB(randint(0, 256), randint(0, 256), randint(0, 256)),
    };
}

void Shape_draw(struct Shape *s)
{
    static int *points = 0; // temp array of points: x0, y0, x1, y1, ...
    static int nPoints = 0; // number of X,Y points (half the number of elements)

    if (s->nPoints > nPoints) {   // grow the points[] array
	if (points) free(points);
	points = calloc((nPoints = s->nPoints) * 2, sizeof(*points));
    }

    for (int i = 0;  i < s->nPoints;  ++i) {  // calculate X,Y for each point
	double a = s->a + s->angle * i;
	points[2*i+0] = s->x + s->r * sin(a degrees);
	points[2*i+1] = s->y + s->r * cos(a degrees);
    }
    stroke(s->stroke);                 // set border and interior colours
    fill(s->fill);
    drawPolygon(s->nPoints, points);   // draw the polygon
}

void keyUpHandler(int key)
{
    if ('q' == key)  // exit the program if the 'q' key is pressed
        exit(0);
}

int main(int argc, char **argv)
{
    size(800, 600);
    title("window test");
    font(0, 24);
    onKeyUp(keyUpHandler);

    struct Shape shapes[NSHAPES];

    for (int i = 0;  i < NSHAPES / 2;  ++i)
	// first half of shapes are regular polygons
	shapes[i] = makeShape(randint(25, width-25), randint(25, height-25), 50, 3 + i, 360 / (3+i));
    for (int i = NSHAPES / 2;  i < NSHAPES;  ++i)
	// next half are regular polygons or self-intersecting polygrams
        shapes[i] = makeShape(randint(25, width-25), randint(25, height-25), 50, i,
                              (i % 2 ? 720 : 360) / i);

    double hue = 0;  // hue of greeting displayed top-left
    double lum = 0;  // luminosity of window background

    for (;;) {
        background(GREY(50 - 50*cos(lum)));      // set window background colour
        lum += 0.01;
	clear();                                 // clear window to background colour
	for (int i = 0;  i < NSHAPES;  ++i) {
	    struct Shape *s = shapes + i;
	    Shape_draw(s);                       // draw the polygon
	    char buf[8];                         // temporary string to hold the shape's number
	    sprintf(buf, "%d", i);
	    drawText(s->x - 6, s->y + 10, buf);  // draw the shapes's index on top of it
	    s->r += s->dr;                                             // shrink or expand the shape's radius
	    if (s->r < 5 || s->r > 100) s->dr = -s->dr;                // reverse when too small or too large
	    int x = s->x + s->dx, y = s->y + s->dy, a = s->a + s->da;  // move and rotate the shape
	    if (x < 0 || x > width ) s->dx = -s->dx;  else s->x = x;   // bounce off the edges of the window
	    if (y < 0 || y > height) s->dy = -s->dy;  else s->y = y;
	    s->a = a;
	}
	stroke(HSV(hue += 1.333, 100, 100));     // set text colour for top-left greeting
	drawText(10, 35, "hello, world!");
	delay(33);                               // pause 1/30th of a second = approx. 30 frames per second
    }

    return 0;
}
