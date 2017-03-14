#include <stdio.h>

#include "new.h"
#include "set.h"
#include "string.h"
#include "point.h"
#include "circle.h"

int main()
{
    void * str = new(String, "Hello String");
    delete(str);

    void * point = new(Point, 1, 1);
    delete(point);

    void * circle = new(Circle, 10, 10, 100);
    delete(circle);

    return 0;
}