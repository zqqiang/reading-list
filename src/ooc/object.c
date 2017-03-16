#include <stdio.h>

#include "object.h"
#include "class.h"

const void *classOf(const void *_self) {
    const struct Object *self = _self;
    return self->class;
}

static int Object_put(const void *_self, FILE *fp) {
    const struct OClassBase * class = classOf(_self);
    return fprintf(fp, "%s at %p\n", class->name, _self);
}