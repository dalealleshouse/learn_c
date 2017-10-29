#include "namedPoint.h"
#include <stdlib.h>

struct NamedPoint {
  double x,y;
  const char* name;
};

struct NamedPoint* makeNamedPoint(double x, double y, const char* name) {
  struct NamedPoint* p = malloc(sizeof(struct NamedPoint));
  p->x = x;
  p->y = y;
  p->name = name;
  return p;
}

void setName(struct NamedPoint* np, const char* name) {
  np->name = name;
}

const char* getName(struct NamedPoint* np) {
  return np->name;
}
