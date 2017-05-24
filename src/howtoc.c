// #include <inttypes.h>
#include "howtoc.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void case1() {
    printf("modern type size {\n");
    printf("  int8_t size is %lld\n", sizeof(int8_t));
    printf("  int16_t size is %lld\n", sizeof(int16_t));
    printf("  uint64_t size is %lld\n", sizeof(uint64_t));
    printf("  float size is %lld\n", sizeof(float));
    printf("  double size is %lld\n", sizeof(double));
    printf("  int_fast8_t size is %lld\n", sizeof(int_fast8_t));
    printf("  uint_fast16_t size is %lld\n", sizeof(uint_fast16_t));
    printf("  int_least8_t size is %lld\n", sizeof(int_least8_t));
    printf("  int_least16_t size is %lld\n", sizeof(int_least16_t));
    printf("  uint8_t * size is %lld\n", sizeof(uint8_t *));
    printf("}\n");
}

void case2() {
    printf("unicode {\n");
    const char *unicode_str = u8"abc😬";
    printf("  unicode str is %s\n", unicode_str);
    printf("}\n");
}

//  MSVC does not have inttypes.h prior to Visual Studio 2013
//  #error MSVC does not have inttypes.h prior to Visual Studio 2013

// void case3() {
//   printf("ptr type {\n");
//   struct _obj {
//     uint8_t attr8;
//     uint16_t attr16;
//   } obj;
//   uint8_t *ptrOld = &obj.attr8;
//   uint16_t *ptrNew = &obj.attr16;
//   ptrdiff_t diff = (uintptr_t)ptrOld - (uintptr_t)ptrNew;
//   printf("  old is %" PRIuPTR "new is %" PRIuPTR "diff is %" PRIuPTR "\n",
//          (uintptr_t)ptrOld, (uintptr_t)ptrNew, diff);
//   printf("}\n");
// }

void case4() {
    printf("max type {\n");
    printf("  intmax_t size is %lld\n", sizeof(intmax_t));
    printf("  uintmax_t size is %lld\n", sizeof(uintmax_t));
    printf("}\n");
}

void case5() {
    printf("variable declarations anywhere {\n");
    for (uint32_t i = 0; i < 10; i++) {
    }
    printf("}\n");
}

void case6() {
    printf("allows static initialization of auto-allocated arrays/structs {\n");

    uint32_t numbers[64] = {0};
    struct thing {
        uint64_t index;
        uint32_t counter;
    };
    static const struct thing localThingNull = {0};
    struct thing localThing = {.counter = 3};
    localThing = localThingNull;
    localThing = (struct thing) {0};

    printf("}\n");
}

void case7() {
    printf("added variable length arrays {\n");

    uintmax_t arrayLength = 16;
    // error: variable-sized object may not be initialized
    // uint8_t array[arrayLength] = {0};
    uint8_t array[arrayLength];

    printf("  dynamic array size is %lld\n", sizeof(array));

    printf("}\n");
}

void case8() {
    printf("bind type modifier and qualifiers to the left\n");

    char* name = "char*";
    char const* const path_name = "char const* const";

    printf("}\n");
}

// The ﬁrst stresses the fact that strlen must receive a valid (non-null) pointer
size_t string_len(char const string[static 1]) {
    return 0;
}

// one null pointer terminates the array
int test_main(int argc, char* argv[argc + 1]) {
    return 0;
}

void test_void(void) {};
void test_aexit(void test_func(void)) {
    return;
}

void* case9_helper() {
    static char string;
    return &string;
}

void case9() {
    printf("array or function notation for pointer parameters to functions\n");

    string_len("string");

    char* ptr = case9_helper();
    // warning: null passed to a callee that requires a non-null argument
    string_len(ptr);

    char* test_string[] = {"one", NULL};
    test_main(1, test_string);

    test_aexit(test_void);

    printf("}\n");
}

void case10() {
    printf("all variables should be initialized\n");

    double A[] = {7.8,};
    double B[3] = {2 * A[0], 7, 33, };
    double C[] = {[0] = 7.8, [7] = 0, };

    printf("sizeof double A[] = {7.8,}; is %lld\n", sizeof(A) / sizeof(double));
    printf("sizeof double B[3] = {2 * a[0], 7, 33, }; is %lld\n", sizeof(B) / sizeof(double));
    printf("sizeof double C[] = {[0] = 7.8, [7] = 0, }; is %lld\n", sizeof(C) / sizeof(double));

    printf("}\n");
}

void case11() {
    printf("enumeration constants {\n");

    enum corvid {magpie, raven, corvid_max};
    char const* const animal[corvid_max] = {
        [magpie] = "magpie",
        [raven] = "raven",
    };

    printf("  %s\n", animal[magpie]);
    printf("  %s\n", animal[raven]);

    printf("}\n");
}

void case12_helper(size_t n, double a[n]) {
    for (int i = 0; i < n; ++i) {
        printf("a[%d] => %f\n", i, a[i]);
    }
}

void case12() {
    printf("VLA notation {\n");

    double a[5] = {1, 2, 3, 4, 5};
    case12_helper(5, a);

    printf("}\n");
}

inline
char const* string_literal(char const str[static 1]) {
    return str;
}
// compile success
// #define string_literal(S) string_literal(S)
#define string_literal(S) string_literal("" S "")

void case13() {
    printf("macro replacement {\n");

    string_literal("test string");
    // error: called object type 'char [1]' is not a function or function pointer
    // string_literal(NULL);

    printf("}\n");
}

void typeofInt(int X) {
    printf("type int => %d\n", X);
}

void typeofFloat(float X) {
    printf("type float => %f\n", X);
}

void case14() {
    printf("_Generic {\n");

#define typeof(X) \
_Generic((X), \
    int: typeofInt, \
    float: typeofFloat)(X)

    int a = 100;
    typeof(a);

    float b = 100.0;
    typeof(b);

    printf("}\n");
}

int main(int argc, char const *argv[]) {
    printf("how-to-c starting\n\n");

    case1();
    case2();

    case4();
    case5();
    case6();
    case7();
    case8();
    case9();
    case10();
    case11();
    case12();
    case13();
    case14();

    printf("\nhow-to-c end\n");
    return 0;
}