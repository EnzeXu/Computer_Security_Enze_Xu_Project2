#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void myRead(void) {
	FILE *fp;
	fp = fopen("badfile", "rb");
	int n;
	unsigned char buf[16];
	unsigned long count = 0;
	while((n = fread(buf, sizeof(char), 16, fp)) > 0) {
		printf("%08lx ", count);
		for(int i = 0; i < n; ++i) {
			printf("%02x ", (unsigned)buf[i]);
		}
		if (n < 16) {
			for(int i = n; i < 16; ++i) printf("    ");
		}
		for(int i = 0; i < n; ++i) {
			putchar(isprint(buf[i]) ? buf[i] : '.');
		}
		putchar('\n');
		count += 16;
	}
	fclose(fp);
}

int main() {
	myRead();
	return 0;
}