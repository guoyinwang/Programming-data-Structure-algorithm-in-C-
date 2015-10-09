#include "point.h"
#include <cmath>

Point::Point() : x(0.0), y(0.0) {}
void Point::move(double dx, double dy){
  x+=dx;
  y+=dy;
} 
double Point::distanceFrom(const Point & p){
  double px = p.x;
  double py = p.y;
  double dist = sqrt((x-px)*(x-px)+(y-py)*(y-py));
  return dist;
}
