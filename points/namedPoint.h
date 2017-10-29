struct NamedPoint;

struct NamedPoint* makeNamedPoint(double x, double y, const char* name);
void setName(struct NamedPoint* np, const char* name);
const char* getName(struct NamedPoint* np);
