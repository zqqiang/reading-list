#include <stdio.h>

#include "new.h"
#include "set.h"
#include "string.h"

int main()
{
    void * str = new(String, "Hello String");
    delete(str);
    return 0;
}