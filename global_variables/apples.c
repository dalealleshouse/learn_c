/*
 *  If this and the data variable in the main file were not static they would colide
 *  static makes the variable local to this file
 */
static int data;

void apples_set(int value)
{
    data = value;
}

int apples_get()
{
    return data;
}
