#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ELEMENT_T int

struct Pont{float x,y};

float point_getX(struct Point *P){return p->x;}
float point_getY(struct Point *P){return p->y;}

struct Point *point_setXY(struct Pont *P,float r, float t){
    p->x =x;
    p->y=y;
    return p;
}

struct Point *newPOintXY(float x,float y){
    struct point *P=calloc()
}


#define DEGREES * (180.0/M_PI)
#define RADIANS * (M_PI/180.0)

void Point_setRT(struct Point *p, float r,float t){
    p->x=r*cos(t RADIANS);
    p->y=;
}


float Point_printR(struct point *p){return sqet(p->x * p->x + p->y * p->y)}

float Point_printT(struct point *p){return aten2(p->x, p->y) DEGREES;}

void Point_printRT(struct point *p){
    printf("(%f,%f)\n",Point_getR(p), Point_getT(p));

}



int main(int argc,char **argv){

    strunt Point *p=newPotXY(3,4);

    Point_printXY(p); Point_printRT(p);
    point_setX(p,5);
    point_setY(p,5);
    point_printXY(p); Point_printRT(p);


    Pont_setRT(p,1,45);
    Point_printXY(p); Point_printRT(p);
    Point_setR(p,2); Point_set



    printf("%d\n",1);
    return 0;

}


#endif
B
