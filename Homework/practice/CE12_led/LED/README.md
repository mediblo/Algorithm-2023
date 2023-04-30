# 알고리즘 설계 구현 결과 : <'LED'>

## 1. <문제 정의>
- **문제이름**: LED 전광판
- **문제설명**: LED 전광판처럼 한단어씩 밀려 보인다.

## 2. <알고리즘>
- **명칭**: LED전관판 ( LED )
- **입력**: 돌릴 문자열
- **출력**: 돌려지는 문자열
- **처리순서** :
	1. 문자열을 출력한다.
	2. 문자열의 첫 번째 단어를 끝에 붙인다.
	3. 1-2번을 반복한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 문자열 : (char msg[]) - 문자열

2. **함수 정의**
- **기능** : 문자열을 받아 밀면서 출력한다.


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, string.h, windows.h ) 
```c
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
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE12_led/LED