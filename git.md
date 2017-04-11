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

## alloc.c
~~~
#define BLOCKING 1024

struct alloc_state {
    int count; /* total number of nodes allocated */
    int nr;    /* number of nodes left in current allocation */
    void *p;   /* first free node in current allocation */
};

static inline void *alloc_node(struct alloc_state *s, size_t node_size)
{
    void *ret;

    // if first time alloc, create a big blob memory
    if (!s->nr) {
        s->nr = BLOCKING; // 1024
        s->p = xmalloc(BLOCKING * node_size); //s->p point to new alloc memory
    }
    s->nr--; // reduce avaliable count
    s->count++; // increase already used count
    ret = s->p; // save current pos
    s->p = (char *)s->p + node_size; //move to remain memory
    memset(ret, 0, node_size); // calloc
    return ret; // return alloc memory
}
~~~

## apply.c
~~~
/*
 * Compare lines s1 of length n1 and s2 of length n2, ignoring
 * whitespace difference. Returns 1 if they match, 0 otherwise
 */
static int fuzzy_matchlines(const char *s1, size_t n1,
                const char *s2, size_t n2)
{
    const char *last1 = s1 + n1 - 1;
    const char *last2 = s2 + n2 - 1;
    int result = 0;

    /* ignore line endings */
    while ((*last1 == '\r') || (*last1 == '\n'))
        last1--;
    while ((*last2 == '\r') || (*last2 == '\n'))
        last2--;

    /* skip leading whitespaces, if both begin with whitespace */
    if (s1 <= last1 && s2 <= last2 && isspace(*s1) && isspace(*s2)) {
        while (isspace(*s1) && (s1 <= last1))
            s1++;
        while (isspace(*s2) && (s2 <= last2))
            s2++;
    }
    /* early return if both lines are empty */
    if ((s1 > last1) && (s2 > last2))
        return 1;
    while (!result) {
        result = *s1++ - *s2++;
        /*
         * Skip whitespace inside. We check for whitespace on
         * both buffers because we don't want "a b" to match
         * "ab"
         */
        if (isspace(*s1) && isspace(*s2)) {
            while (isspace(*s1) && s1 <= last1)
                s1++;
            while (isspace(*s2) && s2 <= last2)
                s2++;
        }
        /*
         * If we reached the end on one side only,
         * lines don't match
         */
        if (
            ((s2 > last2) && (s1 <= last1)) ||
            ((s1 > last1) && (s2 <= last2)))
            return 0;
        if ((s1 > last1) && (s2 > last2))
            break;
    }

    return !result;
}
~~~