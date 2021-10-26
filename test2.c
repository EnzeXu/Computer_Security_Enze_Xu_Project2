#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[]) {
	char *p;
	p = getenv(argv[1]);
	p += (strlen(argv[0]) - strlen(argv[2])) * 2;
	printf("%s at %p\n", argv[1], p);
	return 0;
}