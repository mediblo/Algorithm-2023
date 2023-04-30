# 알고리즘 설계 구현 결과 : <파일의 특정 단어를 변형하기>

## 1. <문제 정의>
- **문제이름**: 파일의 특정 단어를 변형하기
- **문제설명**: 파일의 특정 단어(ex : Android)를 변형(ex : 안드로이드)한다.

## 2. <알고리즘>
- **명칭**: change_file
- **입력**: 텍스트 파일 ( 문자열 )
- **출력**: 변형된 문자열 ( 텍스트 파일 )
- **처리순서** :
	1. 텍스트파일을 읽어 문자열을 저장한다.
	2. 특정 단어가 있는지 확인하여 있으면 변형한다.
	3. 변형한 문자열을 다시 파일에 저장한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 파일 : (FILE* fp) - 파일
	- 문자열 : (char temp[]) - 문자열

2. **함수 정의**
- **기능** : 파일의 문자열을 읽어 변형하여 저장한다.


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, string.h ) 
```c
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
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE15_change_file/Change_File