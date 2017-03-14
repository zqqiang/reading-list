#ifndef OBJECT_T
#define OBJECT_T

struct Class;

struct Object {
    const struct Class * class;
};

extern const void * Object;

#endif