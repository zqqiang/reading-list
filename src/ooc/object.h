#ifndef OBJECT_T
#define OBJECT_T

struct Object {
    const struct OClassBase * class;
};

struct OClassBase {
    const struct Object _;
    const char * name;
    const struct OClassBase * super;
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
    int (* differ) (const void * self, const void * b);
    int (* puto) (const void *self, FILE *fp);
};

extern const void * Object;

#endif