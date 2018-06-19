#include <stdlib.h>
#include <stdio.h>
#include "byte.h"

int main (int argc, char const *argv []) {
	char str [10] = {'a', 0, 0, 0, 0, 'b', 0, 0, 0, 0};
	struct mybyte *ptr = (struct mybyte *)str;
	struct mybyteattribute *at_ptr = (struct mybyteattribute *)str;
	printf ("int a = %c\n, char b = %c", ptr -> a, ptr -> b);
	printf ("int a = %c\n, char b = %c", at_ptr -> a, at_ptr -> b);
	return 0;
}
