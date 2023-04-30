#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

// Before : Android 4.1, JellyBean, is the fastest and smoothest version of Android yet.
// After  : 안드로이드 4.1, JellyBean, is the fastest and smoothest version of Android yet.

int main() {
	FILE* fp;
	char temp[200];
	char* ptmp = NULL;
	bool flag = true;

	fp = fopen("test.txt", "r+");
	if (fp == NULL) {
		printf("파일못염");
		exit(1);
	}
	fgets(temp, 200, fp);

	printf("%s\n", temp);

	fflush(fp);
	fseek(fp, 0, SEEK_SET);

	ptmp = strtok(temp, " ");
	while (ptmp != NULL) {
		if (flag && strcmp(ptmp, "Android") == 0) {
			flag = false;
			fprintf(fp, "안드로이드 ");
			ptmp = strtok(NULL, " ");
			continue;
		}
		fprintf(fp, "%s ",ptmp);
		ptmp = strtok(NULL, " ");
	}

	fclose(fp);
	return 0;
}