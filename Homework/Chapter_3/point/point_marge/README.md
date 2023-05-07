# 알고리즘 설계 구현 결과 : <병합 정렬>

## 1. <문제 정의>
- **문제이름**: 병합 정렬
- **문제설명**: 나눌 수 없을 때 까지 나눈 다음 합치면서 정렬을 하는 알고리즘
- **문제예시** : 다음 그림은 병합 정렬의 예시이다.  
![photo](https://gmlwjd9405.github.io/images/algorithm-merge-sort/merge-sort-concepts.png)

## 2. <알고리즘>
- **명칭**: 병합 정렬 ( merge_sort )
- **입력**: 정렬되지 않은 정수들
- **출력**: 정렬된 정수들
- **처리순서** :
	1. 정수들을 입력 받아 피벗을 설정한다 ( 왼쪽과 오른쪽의 가운데 값 )
	2. 피벗을 기준으로 왼쪽과 오른쪽을 나눈다.
	3. 나눌 수 없을 때 까지 1번과 2번을 반복한다.
	4. 나눈 숫자들을 합치면서 작은 것은 왼쪽, 큰 것은 오른쪽으로 보낸다.
	5. 정렬된 값을 출력한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 정렬되지 않은 정수들 : A (int A[]) - 정수 배열

2. **함수 정의**
- **기능** : 정수 배열을 받아 왼쪽과 오른쪽으로 나눈 다음에 병합한 후에 정렬된 배열을 출력한다.
- **프로토타입** : void merge(int A[], int left, int right)

3. **테스트 케이스 설계**  
TC. 랜덤한 시드값을 받아 위 함수에 넣어서 정렬되는지 확인한다.

## 4. <의사 코드>
```
만약 오른쪽이 왼쪽보다 크면 ( 원소가 2개 이상이면 )
  피벗을 중간 값으로 설정
  
  피벗 기준으로 왼쪽을 다시 합병
  피펏기준 오른쪽을 다시 합병
  
  원소 갯수만큼 반복
    만약 왼쪽을 다 돌면 오른쪽만 더미배열에 추가
    만약 오른쪽 인덱스가 왼쪽 인덱스보다 크거나 오른쪽을 다 돌면 더미배열에 왼쪽 추가
    아니면 더미배열에 오른쪽 추가
  더미배열을 진짜 배열에 옮기기
```

## 5. <순서도>
![flow chart](https://i.imgur.com/w10wiq5.png)

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h )  
```c
void merge(int A[], int left, int right) {
	if (left < right) {
		int p = (right - left) / 2 + left;
		int t_size = right - left + 1;
		int temp[MAX_SIZE+1];
		int a = left, b = p+1;
		
		merge(A, left, p);
		merge(A, p + 1, right);

		for (int i = 0; i < t_size; i++) {
			
			if (a == p + 1) // 왼쪽 인덱스 다 돌면
			{
				temp[i] = A[b++];
				continue;
			}
			if (A[a] < A[b] || b > right) temp[i] = A[a++]; // 왼쪽 넣기
			else temp[i] = A[b++]; // 오른쪽 넣기
		}

		for (int i = 0, a=left; i < t_size; i++, a++) A[a] = temp[i]; // 임시배열에서 진짜 배열로 데이터 옮기기

	}
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_3/Merge%20Sort