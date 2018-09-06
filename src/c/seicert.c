#include <stdio.h>
#include "seicert.h"

static inline short sabs(short v) {
	printf("short abs\n");
	return v < 0 ? -v : v;
}

static inline int iabs(int v) {
	printf("int abs\n");
	return v < 0 ? -v : v;
} 

#define ABS(v) _Generic(v, short : sabs, int : iabs)(v)

int main(int argc, char const *argv[]) {
	int i = 10;
	short s = 5;
	ABS(i);
	ABS(s);
	return 0;
}
