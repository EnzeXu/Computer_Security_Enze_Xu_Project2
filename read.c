#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void read1(void) {
	FILE *fp = NULL;
	fp = fopen("badfile", "r");
	if (fp == NULL) {
		perror("Error in opening file .myhistory");
		return;
	}
	int count = 0;
	int c;
	int z = 517;
	while(z--) {
		fscanf(fp, "%x", &c);
		printf("%4d ", c);
		count ++;
		if (count % 16 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	fclose(fp);
	return;
}

void read2(void) {
	FILE *sf;
	sf = fopen("badfile"", "rb");
	int n;
	unsigned char buf[16];
	unsigned long count = 0;
	while((n = fread(buf, sizeof(char), 16, sf)) > 0) {
		int i;
		printf("%08lx ", count);
		for(i=0; i<n; i++) {
			printf("%02x ", (unsigned)buf[i]);
		}
		if(n < 16) {
			for(i=n; i<16; i++) printf("    ");
		}
		for(i=0; i<n; i++) {
			putchar(isprint(buf[i]) ? buf[i] : '.');
		}
		putchar('\n');
		count += 16;
	}
	fclose(sf);
}

int main() {
	read2();
	//read1();
	return 0;
}