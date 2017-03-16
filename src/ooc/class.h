#ifndef CLASS_H
#define CLASS_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#include "object.h"

struct Class {
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
};

#endif