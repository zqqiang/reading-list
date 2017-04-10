# Git Source Code Reading Notes

## cache.h
~~~
#define alloc_nr(x) (((x)+16)*3/2)

/*
 * Realloc the buffer pointed at by variable 'x' so that it can hold
 * at least 'nr' entries; the number of entries currently allocated
 * is 'alloc', using the standard growing factor alloc_nr() macro.
 *
 * DO NOT USE any expression with side-effect for 'x', 'nr', or 'alloc'.
 */
#define ALLOC_GROW(x, nr, alloc) \
    do { \
        if ((nr) > alloc) { \
            if (alloc_nr(alloc) < (nr)) \
                alloc = (nr); \
            else \
                alloc = alloc_nr(alloc); \
            REALLOC_ARRAY(x, alloc); \
        } \
    } while (0)
~~~

if nr is so small just allocate alloc_nr(alloc) size memory to void small memory malloc.  

~~~
#include <stdint.h>

#define bitsizeof(x)  (CHAR_BIT * sizeof(x))

#define maximum_signed_value_of_type(a) \
    (INTMAX_MAX >> (bitsizeof(intmax_t) - bitsizeof(a)))

#define maximum_unsigned_value_of_type(a) \
    (UINTMAX_MAX >> (bitsizeof(uintmax_t) - bitsizeof(a)))

// >> in order to padding 0 at the begining of max 

/*
 * Signed integer overflow is undefined in C, so here's a helper macro
 * to detect if the sum of two integers will overflow.
 *
 * Requires: a >= 0, typeof(a) equals typeof(b)
 */
#define signed_add_overflows(a, b) \
    ((b) > maximum_signed_value_of_type(a) - (a))

#define unsigned_add_overflows(a, b) \
    ((b) > maximum_unsigned_value_of_type(a) - (a))

/*
 * Returns true if the multiplication of "a" and "b" will
 * overflow. The types of "a" and "b" must match and must be unsigned.
 * Note that this macro evaluates "a" twice!
 */
#define unsigned_mult_overflows(a, b) \
    ((a) && (b) > maximum_unsigned_value_of_type(a) / (a))

static inline size_t st_mult(size_t a, size_t b)
{
    if (unsigned_mult_overflows(a, b)) // check overflows
        die("size_t overflow: %"PRIuMAX" * %"PRIuMAX,
            (uintmax_t)a, (uintmax_t)b);
    return a * b;
}

#define ALLOC_ARRAY(x, alloc) (x) = xmalloc(st_mult(sizeof(*(x)), (alloc)))
#define REALLOC_ARRAY(x, alloc) (x) = xrealloc((x), st_mult(sizeof(*(x)), (alloc)))
~~~

## commit.c
~~~
#define OPT_COUNTUP(s, l, v, h)     { OPTION_COUNTUP, (s), (l), (v), NULL, \
                      (h), PARSE_OPT_NOARG }

#define OPT__VERBOSE(var, h)  OPT_COUNTUP('v', "verbose", (var), (h))
#define OPT__QUIET(var, h)    OPT_COUNTUP('q', "quiet",   (var), (h))

static struct option builtin_commit_options[] = {
    OPT__QUIET(&quiet, N_("suppress summary after successful commit")),
    OPT__VERBOSE(&verbose, N_("show diff in commit message template")),
}
~~~
using several macro defination to reduce complicated struct option define.  
