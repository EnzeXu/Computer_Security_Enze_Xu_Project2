#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void readHistory(void) {
	FILE *fp = NULL;
	fp = fopen("badfile", "r");
	if (fp == NULL) {
		perror("Error in opening file .myhistory");
		return;
	}
	int count = 0;
	int c;
	while(fscanf(fp, "%x", &c)) {
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

int main() {
	readHistory();
	return 0;
}