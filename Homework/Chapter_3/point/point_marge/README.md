# 알고리즘 설계 구현 결과 : <최근접 쌍 찾기>

## 1. <문제 정의>
- **문제이름**: 최근접 쌍 찾기
- **문제설명**: 수 많은 좌표들 중 가장 직선거리가 가까운 점 찾기
- **문제예시** : 다음 그림은 최근접 쌍 문제의 예시이다.  
![photo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FdNtAJp%2FbtrhshMpkZN%2FuPzqCYmGus6jcmLbQtkthk%2Fimg.png)

## 2. <알고리즘>
- **명칭**: 최근접 쌍 ( closest_pair )
- **입력**: 정렬되지 않은 좌표들
- **출력**: 최근접 쌍과 그 거리
- **처리순서** :
	1. 좌표들을 입력받아 x좌표를 기준으로 정렬한다. ( x좌표가 같은경우 y좌표로 )
    2. 좌표들이 3개 이하가 될 때 까지 x좌표를 기준으로 반으로 자른다.
    3. 나눌 수 없을 경우 점들(2~3)의 거리들을 계산하여 최소값을 계산한다.
    4. 반으로 자른곳을 기준으로 최소값을 +-하여 기 주위를 다시 계산한다.
    5. 최소값을 출력한다. 

## 3. <코드 설계>
1. **자료 구조 정의**
	- 구조체 : point ( struct ) - int, int
    - 정렬되지 않은 좌표들 : p (point []) - point 구조체
    - 최근접 거리 : min (double) - 실수
    - 최근접 쌍 : min_p (point []) - point 구조체

2. **함수 정의**
	- **기능**: 데이터 읽기 ( 동적 배열 )
    - **프로토타입** : int read_file(point\*\* mp)
    - **기능**: 직선거리 반환
    - **프로토타입** : double distance(point a, point b)
    - **기능**: 분할 후 최근접 쌍 찾기
    - **프로토타입** : void merge(point* A, int left, int right, int size)
    - **기능**: x좌표 기준으로 정렬 ( x좌표 같을 시 y좌표 기준 )
    - **프로토타입** : void quick(point* A, int left, int right)
    - **기능**: 최솟값 및 최솟값 좌표
    - **프로토타입** : void who_min(point temp[], int size)

3. 테스트 케이스 설계
TC1. 지속적으로 여러 좌표를 넣어 출력을 확인한다.

## 4. <의사 코드>
```
먼저 데이터를 불러들인다
그 후 퀵 정렬을 통해 x좌표를 정렬한다. 만약 x좌표가 동일할 시 y좌표를 기준으로 정렬한다.
그 후 병합정렬을 통해 좌표가 각각 3개 이하가 될 때 까지 나눈다.
만약 3개 이하이면 이들 사이의 거리를 확인하고 최소거리인지 판별한다.
나눈 사이의 중간 점들을 확인하기 위해 최소거리를 +- 한 거리의 모든 점들을 다시 병합 정렬한다.
 ```

## 5. <순서도>
![photo](https://i.imgur.com/Eij7Iez.png)

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, string.h, math.h )  
**메인 함수**
```C
int main() {

    point* p = (point*)malloc(sizeof(point));

    int size = read_file(&p);

    for (int i = 0; i < size; i++) {
        if (i == 8) printf("\n");
        printf("[%d %d] ", (p + i)->x, (p + i)->y);
    }
    printf("\n\n");

    quick(p, 0, size);

    for (int i = 0; i < size; i++) {
        if (i == 8) printf("\n");
        printf("[%d %d] ", (p + i)->x, (p + i)->y);
    }
    printf("\n\n");

    merge(p, 0, size - 1, size, false);
    free(p);
    printf("%.2f의 거리로 [%d %d]와 [%d %d]의 거리가 제일 적다.", min, min_p[0].x, min_p[0].y, min_p[1].x, min_p[1].y);

    FILE* fp = fopen("result.txt", "w");
    if (fp == NULL) return 0;
    fprintf(fp, "%.2f의 거리로 [%d %d]와 [%d %d]의 거리가 제일 적다.", min, min_p[0].x, min_p[0].y, min_p[1].x, min_p[1].y);
    fclose(fp);
        
    return 0;
}
```
**파일 읽기**
```C
int read_file(point** mp) {
    FILE* fp = NULL;
    fp = fopen("test.txt", "r");
    if (fp == NULL) 0;
    point* p = NULL;
    char temp[10];
    char* temp_tok = NULL;
    int size = 0;
    int i = 0;
    while (1) {
        fgets(temp, 10, fp);
        size++;
        if (feof(fp)) break;
    }
    fseek(fp, 0, SEEK_SET); // 갯수 세기
    p = (point*)malloc(size * sizeof(point));
    while (1) {
        fgets(temp, 10, fp);
        temp_tok = strtok(temp, " ");
        (p + i)->x = atoi(temp_tok);
        temp_tok = strtok(NULL, " ");
        (p + i++)->y = atoi(temp_tok);
        if (feof(fp)) break;
    }
    fclose(fp);
    free(*mp);
    *mp = p;
    return size;
}
```
**퀵 정렬**
```
void quick(point* A, int left, int right) {
    if (left < right) {
        int p = (left + right) / 2;
        point temp = *(A + right - 1);
        *(A + right - 1) = *(A + p);
        *(A + p) = temp;
        int i, j = left;
        for (i = left; i < right; i++) {
            if ((A + i)->x < (A + right - 1)->x) { // i번째 x좌표가 피벗의 x좌표보다 작을 경우
                temp = *(A + j);
                *(A + j++) = *(A + i);
                *(A + i) = temp;
            }
            else if ((A + i)->x == (A + right - 1)->x && (A + i)->y < (A + right - 1)->y) { // x좌표는 같으나 y좌표가 다를 경우
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
        quick(A, left, j); // 왼쪽
        quick(A, j + 1, right); // 오른쪽
    }
}
```
**병합 정렬**
```
void merge(point* A, int left, int right, int size, bool loop) {
    int p_size = right - left + 1;
    point temp[3];
    if (2 == p_size) {
        temp[0] = *(A + left);
        temp[1] = *(A + left + 1);
        who_min(temp, 2);
        return;
    }
    else if (3 == p_size) {
        for (int i = 0; i < 3; i++) temp[i] = *(A + left + i);
        who_min(temp, 3);
        return;
    }
    else if (3 < p_size) {
        int p = (right - left) / 2 + left;
        point* temp = (point*)malloc(size * sizeof(point));
        int j = 0;
        bool count = false;

        merge(A, left, p, size, false);
        merge(A, p, right, size, false);

        int check_l = (A + p)->x - (int)min;
        int check_r = (A + p)->x + (int)min;

        // 최솟값 기준으로 중간 영역 확인
        for (int i = left; i <= (right == size ? right - 1 : right); i++) if (check_l <= (A + i)->x && (A + i)->x <= check_r) *(temp + j++) = *(A + i);


        if (j > 0 && loop == false) {
            for (int i = 0; i < j; i++) // 최소점 첫 번째 중복 확인
                if ((temp + i)->x == min_p[0].x && (temp + i)->y == min_p[0].y) continue;
                else count++;
            if (j == count) *(temp + j++) = min_p[0];

            count = 0;
            for (int i = 0; i < j; i++) // 최소점 두 번째 중복 확인
                if ((temp + i)->x == min_p[1].x && (temp + i)->y == min_p[1].y) continue;
                else count++;
            if (j == count) *(temp + j++) = min_p[1];

            merge(temp, 0, j - 1, j, true);
        }
        free(temp);
    }
}
```
**최근접 쌍 확인**
```
void who_min(point temp[], int size) {
    double check;
    if (size == 2) {
        check = distance(temp[0], temp[1]); // 제일 작은 경우
        if (min < check && min != -1.0) return;
        min = check;
        min_p[0] = temp[0];
        min_p[1] = temp[1];
    }
    else {
        double dis[3] = { 0 }; // 3개의 직선거리 저장
        for (int i = 0; i < size; i++) { // 3개의 직선거리 구하기
            if (i == 2) dis[i] = distance(temp[i], temp[0]);
            else dis[i] = distance(temp[i], temp[i + 1]);
        }
        // 젤 작은 거리 저장
        check = dis[0] < dis[1] ? dis[0] : dis[1];
        check = check < dis[2] ? check : dis[2];
        if (min != -1.0 && min < check) return;
        min = check;
        // 젤 작은 거리 점들 저장
        for (int i = 0; i < 3; i++) { // 3개의 직선거리 구하기
            if (min == dis[i]) {
                if (i == 2) min_p[0] = temp[i], min_p[1] = temp[0];
                else min_p[0] = temp[i], min_p[1] = temp[i + 1];
            }
        }
    }
}
```
**직선거리 반환**
```
doubledistance(point a, point b) { returnsqrt(pow((a.x -b.x), 2.0) +pow((a.y -b.y), 2.0)); }
```


## <코드 저장소 링크>
용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_3/Quick%20Sort  
동희 : https://github.com/20LDH/algorithm_2023  
정원 : https://github.com/jwgarde/algorithm-find-nearest-neighbor-pairs  
무석 : https://github.com/KANGMUSEOK/-min  
종모 : https://github.com/rrrrrrongmo/dot  
윤서 : 