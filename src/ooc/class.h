#ifndef CLASS_H
#define CLASS_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#include "object.h"

struct Class {
    const struct Object _;
    const char * name;
    const struct Class * super;
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
    int (* differ) (const void * self, const void * b);
    int (* puto) (const void *self, FILE *fp);
};

#endif