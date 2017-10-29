#include "point.h"
#include <stdlib.h>
#include <math.h>

struct Point {
  double x, y;
};

struct Point* makePoint(double x, double y) {
  struct Point* p = malloc(sizeof(struct Point));
  p->x = x;
  p->y = y;
  return p;
}

double distance(struct Point* p1, struct Point* p2) {
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;

  return sqrt(dx*dx+dy*dy);
}
