#include <stdlib.h>
#include "new.h"
#include "class.h"

void * new(const void * _class, ...)
{
    const struct Class * class = _class;
    void * p = calloc(1, class->size);
    * (const struct Class **)p = _class;

    if (class->ctor) {
        va_list ap;
        va_start(ap, _class);
        p = class->ctor(p, &ap);
        va_end(ap);
    }

    return p;
}

void delete(void * self)
{
    const struct Class ** cp = self;
    if (self && *cp && (*cp)->dtor) {
        self = (*cp)->dtor(self);
    }
    free(self);
}