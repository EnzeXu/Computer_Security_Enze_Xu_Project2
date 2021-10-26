#include<stdio.h>
#include<stdlib.h>

int main() {
	char *env = getenv("RTL_SHELL");
	if (env) {
		printf("/bin/sh is at %x\n", (unsigned int) shell);
	}
	return 0;
}