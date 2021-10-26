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
	char c;
	int count = 0;
	while(c = fgetc(fp)) {
		printf("%2d ", c);
		count ++;
		if (count % 20 == 0) {
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