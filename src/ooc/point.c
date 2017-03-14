#include <stdio.h>
#include "class.h"
#include "point.h"

static void *Point_ctor(void *_self, va_list *app) {
    struct Point *self = _self;
    self->x = va_arg(*app, int);
    self->y = va_arg(*app, int);
    printf("%s: new Point (%d, %d)\n", __func__, self->x, self->y);
    return self;
}

static void *Point_dtor(void *_self) {
    printf("%s: destroy Point\n", __func__);
    // do nothing
    return _self;
}

static const struct Class _Point = {
    .size = sizeof(struct Point),
    .ctor = Point_ctor,
    .dtor = Point_dtor
};

const void * Point = &_Point;