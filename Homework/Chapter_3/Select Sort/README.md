# 알고리즘 설계 구현 결과 : <선택 정렬>

## 1. <문제 정의>
- **문제이름**: 선택 정렬
- **문제설명**: 원하는 인덱스가 나올 때 까지 정렬하면서 선택한 인덱스를 출력하는 알고리즘
- **문제예시** : 다음 그림은 선택 정렬의 예시이다.  
![photo](https://dudri63.github.io/image/algo7-1.png)

## 2. <알고리즘>
- **명칭**: 선택 정렬 ( select_sort )
- **입력**: 정렬되지 않은 데이터, 원하는 인덱스
- **출력**: 인덱스 값
- **처리순서** :
	1. 피벗 값을 설정한다 ( 기본 값은 중앙 값 )
	1. 피벗을 제일 오른쪽 값과 변경한 후 왼쪽부터 차례대로 작으면 왼쪽으로 둔다.
	1. 다 확인했으면 마지막으로 작은 값 옆에 두고 그 피벗이 원하는 인덱스인지 확인한다.
	1. 인덱스가 일치하면 값을 반환, 피벗이 더 크면 오른쪽, 작으면 왼쪽을 재정렬한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 정렬되지 않은 데이터 : A (int []) - 정수 배열
	- 원하는 인덱스 : K (int) - 정수

2. **함수 정의**
	- **기능** : 정렬되지 않은 데이터 값을 정렬하며 원하는 인덱스의 값을 출력한다.
	- **프로토타입** : int quick(int A[], int left, int right, int find)


## 4. <의사 코드>
```
만약 인덱스가 2개 이상이면 실행
  피벗 값 설정 ( 중앙 )
  피벗이랑 가장 오른쪽 인덱스랑 변경
  가장 왼쪽부터 순서대로 피벗보다 작은지 확인
    작은 경우 제일 왼쪽에 배치하고 배치해야할 곳을 +1 하기
  배치해야할 곳이랑 피벗이랑 변경
  피벗이 원하는 인덱스랑 같으면 피벗 값 반환
  피벗이 크면 오른쪽 정렬
  피벗이 작으면 왼쪽 정렬
  ```

## 5. <순서도>
![photo](https://i.imgur.com/mfN38xw.png)

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h )  
```C
int quick(int A[], int left, int right, int find) {
	int ret = -1;
	if (left < right) {
		int p = (left + right) / 2;


		int temp = A[right - 1];
		A[right - 1] = A[p];
		A[p] = temp;

		int i, j = left;

		for (i = left; i < right; i++) {
			if (A[i] < A[right - 1]) { // i번째가 피벗 숫자보다 작을 경우
				temp = A[j];
				A[j++] = A[i];
				A[i] = temp;
			}
		}

		if (j <= right - 1) {
			temp = A[j];
			A[j] = A[right - 1];
			A[right - 1] = temp;
		}

		if (j + 1 > find) ret = quick(A, left, j, find); // 왼쪽
		else if (j + 1 < find) ret = quick(A, j + 1, right, find); // 오른쪽
		else if (j + 1 == find) return A[find - 1];
	}
	return ret;
}
```


## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_3/Select%20Sort