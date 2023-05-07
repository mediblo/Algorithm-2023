# 알고리즘 설계 구현 결과 : <퀵 정렬>

## 1. <문제 정의>
- **문제이름**: 퀵 정렬
- **문제설명**: 정렬 알고리즘 중 평균적으로 가장 효율적인 정렬 방법
- **문제예시** : 다음 그림은 퀵 정렬의 예시이다.  
![photo](https://gmlwjd9405.github.io/images/algorithm-quick-sort/quick-sort.png)

## 2. <알고리즘>
- **명칭**: 퀵 정렬 ( quick_sort )
- **입력**: 정렬되지 않은 데이터
- **출력**: 정렬된 데이터
- **처리순서** :
	1. 피벗 값을 설정한다 ( 기본 값은 중앙 값 )
	1. 피벗을 제일 오른쪽 값과 변경한 후 왼쪽부터 차례대로 작으면 왼쪽으로 둔다.
	1. 다 확인했으면 마지막으로 작은 값 옆에 두고 그 피벗을 기준으로 왼쪽 오른쪽 배열을 다시 정렬한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 정렬되지 않은 데이터 : A (int []) - 정수 배열

2. **함수 정의**
	- **기능** : 정렬되지 않은 데이터 값을 정렬하여 출력한다.
	- **프로토타입** : void quick(int A[], int left, int right)

3. **테스트 케이스 설계**  
TC. 랜덤한 시드값을 받아 위 함수에 넣어서 정렬되는지 확인한다.

## 4. <의사 코드>
```
만약 인덱스가 2개 이상이면 실행
  피벗 값 설정 ( 중앙 )
  피벗이랑 가장 오른쪽 인덱스랑 변경
  가장 왼쪽부터 순서대로 피벗보다 작은지 확인
    작은 경우 제일 왼쪽에 배치하고 배치해야할 곳을 +1 하기
  배치해야할 곳이랑 피벗이랑 변경
  피벗을 기준으로 왼쪽과 오른쪽을 다시 정렬
  ```



## 5. <순서도>
![photo](https://i.imgur.com/JmIWu3s.png)

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h )  
```C
void quick(int* A, int left, int right, int size) {
	if (left < right) {
		int p = (left + right) / 2;

		int temp = *(A + right - 1);
		*(A + right - 1) = *(A + p);
		*(A + p) = temp;

		int i, j = left;

		for (i = left; i < right; i++) {
			if (*(A + i) < *(A + right - 1)) { // i번째가 피벗 숫자보다 작을 경우
				temp = *(A + j);
				*(A + j++) = *(A + i);
				*(A + i) = temp;
			}
		}

		if (j <= right - 1) {
			temp = *(A + j);
			*(A + j) = *(A + right - 1);
			*(A + right - 1) = temp;
		}

		quick(A, left, j, size); // 왼쪽
		quick(A, j + 1, right, size); // 오른쪽
	}
}
```


## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_3/Quick%20Sort