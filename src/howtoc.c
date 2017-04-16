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
  localThing = (struct thing){0};

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

int main(int argc, char const *argv[]) {
  printf("how-to-c starting\n\n");

  case1();
  case2();

  case4();
  case5();
  case6();
  case7();

  printf("\nhow-to-c end\n");
  return 0;
}