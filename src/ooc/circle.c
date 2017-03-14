#include <stdio.h>
#include "circle.h"
#include "point.h"
#include "class.h"

static void *Circle_ctor(void *_self, va_list *app) {
    struct Circle *self = ((const struct Class*)Point)->ctor(_self, app);
    self->rad = va_arg(*app, int);
    printf("%s: new Circle (%d)\n", __func__, self->rad);
    return self;
}

static struct Class _Circle = {
    .size = sizeof(struct Circle),
    .ctor = Circle_ctor,
};

const void * Circle = &_Circle;