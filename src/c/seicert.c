#include <stdio.h>
#include "seicert.h"

static inline short sabs(short v)
{
	printf("short abs\n");
	return v < 0 ? -v : v;
}

static inline int iabs(int v)
{
	printf("int abs\n");
	return v < 0 ? -v : v;
}

#define ABS(v) _Generic(v, short    \
						: sabs, int \
						: iabs)(v)

static int unsafe_macros()
{
	printf("PRE31-C. Avoid side effects in arguments to unsafe macros\n");

	int i = 10;
	short s = 5;
	ABS(i);
	ABS(s);
	return 0;
}

int main(int argc, char const *argv[])
{
	unsafe_macros();

	return 0;
}
