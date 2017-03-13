#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "string.h"
#include "class.h"

static void * String_ctor(void * _self, va_list * app) {
    struct String * self = _self;
    const char * text = va_arg(*app, const char *);
    self->text = malloc(strlen(text) + 1);
    strcpy(self->text, text);
    printf("%s => %s\n", __func__, self->text);
    return self;
}

static void * String_dtor(void * _self) {
    struct String * self = _self;
    free(self->text);
    self->text = NULL;
    printf("%s\n", __func__);
    return self;
}

static const struct Class _String = {
    sizeof(struct String),
    String_ctor,
    String_dtor,
};

const void * String = &_String;