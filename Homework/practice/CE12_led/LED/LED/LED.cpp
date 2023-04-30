#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main() {
	char msg[80];
	char temp[80];
	int len;
	printf("광고하고 싶은 텍스트를 입력하시오 : ");
	gets_s(msg, sizeof(msg));
	
	len = strlen(msg);

	for (int i = 0; i <= len; i++) {
		system("cls");
		printf("%s\n", msg);
		strcpy(temp, msg + 1);
		strncat(temp, msg, 1);
		strcpy(msg, temp);
		Sleep(200);
	}

	return 0;
}