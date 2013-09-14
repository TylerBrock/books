// coordin.h -- structure templates and function prototypes
#ifndef COORDIN_H_
#define COORDIN_H_

// structure templates
struct polar
{
    double distance;    // distance from origin
    double angle;       // direction from origin
};

struct rect
{
    double x;           // horizontal distance from origin
    double y;           // vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
