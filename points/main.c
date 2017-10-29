#include "point.h"
#include "namedPoint.h"
#include <stdio.h>

int main(int ac, char** av) {
  struct NamedPoint* one = makeNamedPoint(5, 5, "one");
  struct NamedPoint* two = makeNamedPoint(10, 10, "two");

  printf("distance=%f\n", distance((struct Point*)one, (struct Point*)two));

  return 0;
}
