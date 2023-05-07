# �˰��� ���� ���� ��� : <�ֱ��� �� ã��>

## 1. <���� ����>
- **�����̸�**: �ֱ��� �� ã��
- **��������**: �� ���� ��ǥ�� �� ���� �����Ÿ��� ����� �� ã��
- **��������** : ���� �׸��� �ֱ��� �� ������ �����̴�.  
![photo](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FdNtAJp%2FbtrhshMpkZN%2FuPzqCYmGus6jcmLbQtkthk%2Fimg.png)

## 2. <�˰���>
- **��Ī**: �ֱ��� �� ( closest_pair )
- **�Է�**: ���ĵ��� ���� ��ǥ��
- **���**: �ֱ��� �ְ� �� �Ÿ�
- **ó������** :
	1. ��ǥ���� �Է¹޾� x��ǥ�� �������� �����Ѵ�. ( x��ǥ�� ������� y��ǥ�� )
    2. ��ǥ���� 3�� ���ϰ� �� �� ���� x��ǥ�� �������� ������ �ڸ���.
    3. ���� �� ���� ��� ����(2~3)�� �Ÿ����� ����Ͽ� �ּҰ��� ����Ѵ�.
    4. ������ �ڸ����� �������� �ּҰ��� +-�Ͽ� �� ������ �ٽ� ����Ѵ�.
    5. �ּҰ��� ����Ѵ�. 

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- ����ü : point ( struct ) - int, int
    - ���ĵ��� ���� ��ǥ�� : p (point []) - point ����ü
    - �ֱ��� �Ÿ� : min (double) - �Ǽ�
    - �ֱ��� �� : min_p (point []) - point ����ü

2. **�Լ� ����**
	- **���**: ������ �б� ( ���� �迭 )
    - **������Ÿ��** : int read_file(point\*\* mp)
    - **���**: �����Ÿ� ��ȯ
    - **������Ÿ��** : double distance(point a, point b)
    - **���**: ���� �� �ֱ��� �� ã��
    - **������Ÿ��** : void merge(point* A, int left, int right, int size)
    - **���**: x��ǥ �������� ���� ( x��ǥ ���� �� y��ǥ ���� )
    - **������Ÿ��** : void quick(point* A, int left, int right)
    - **���**: �ּڰ� �� �ּڰ� ��ǥ
    - **������Ÿ��** : void who_min(point temp[], int size)

3. �׽�Ʈ ���̽� ����
TC1. ���������� ���� ��ǥ�� �־� ����� Ȯ���Ѵ�.

## 4. <�ǻ� �ڵ�>
```
���� �����͸� �ҷ����δ�
�� �� �� ������ ���� x��ǥ�� �����Ѵ�. ���� x��ǥ�� ������ �� y��ǥ�� �������� �����Ѵ�.
�� �� ���������� ���� ��ǥ�� ���� 3�� ���ϰ� �� �� ���� ������.
���� 3�� �����̸� �̵� ������ �Ÿ��� Ȯ���ϰ� �ּҰŸ����� �Ǻ��Ѵ�.
���� ������ �߰� ������ Ȯ���ϱ� ���� �ּҰŸ��� +- �� �Ÿ��� ��� ������ �ٽ� ���� �����Ѵ�.
 ```

## 5. <������>
![photo](https://i.imgur.com/Eij7Iez.png)

## <C�ڵ� ���� ���>
��������� ���� ( stdio.h, stdlib.h )  
**���� �б�**
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
    fseek(fp, 0, SEEK_SET); // ���� ����
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
**�� ����**
```
void quick(point* A, int left, int right) {
    if (left < right) {
        int p = (left + right) / 2;
        point temp = *(A + right - 1);
        *(A + right - 1) = *(A + p);
        *(A + p) = temp;
        int i, j = left;
        for (i = left; i < right; i++) {
            if ((A + i)->x < (A + right - 1)->x) { // i��° x��ǥ�� �ǹ��� x��ǥ���� ���� ���
                temp = *(A + j);
                *(A + j++) = *(A + i);
                *(A + i) = temp;
            }
            else if ((A + i)->x == (A + right - 1)->x && (A + i)->y < (A + right - 1)->y) { // x��ǥ�� ������ y��ǥ�� �ٸ� ���
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
        quick(A, left, j); // ����
        quick(A, j + 1, right); // ������
    }
}
```
**���� ����**
```
void merge(point* A, int left, int right, int size) {
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
        int count = 0;
        merge(A, left, p, size);
        merge(A, p, right, size);
        int check_l = (A + p)->x - (int)min;
        int check_r = (A + p)->x + (int)min;
        // �ּڰ� �������� �߰� ���� Ȯ��
        for (int i = left; i <= (right == size ? right - 1 : right); i++) if (check_l <= (A + i)->x && (A + i)->x <= check_r) *(temp + j++) = *(A + i);
        if (j > 0) {
            for (int i = 0; i < j; i++) // �ּ��� ù ��° �ߺ� Ȯ��
                if ((temp + i)->x == min_p[0].x && (temp + i)->y == min_p[0].y) continue;
                else count++;
            if (j == count) *(temp + j++) = min_p[0];
            count = 0;
            for (int i = 0; i < j; i++) // �ּ��� �� ��° �ߺ� Ȯ��
                if ((temp + i)->x == min_p[1].x && (temp + i)->y == min_p[1].y) continue;
                else count++;
            if (j == count) *(temp + j++) = min_p[1];
            merge(temp, 0, j - count, size);
        }
        free(temp);
    }
}
```
**�ֱ��� �� Ȯ��**
```
void who_min(point temp[], int size) {
    double check;
    if (size == 2) {
        check = distance(temp[0], temp[1]); // ���� ���� ���
        if (min < check && min != -1.0) return;
        min = check;
        min_p[0] = temp[0];
        min_p[1] = temp[1];
    }
    else {
        double dis[3] = { 0 }; // 3���� �����Ÿ� ����
        for (int i = 0; i < size; i++) { // 3���� �����Ÿ� ���ϱ�
            if (i == 2) dis[i] = distance(temp[i], temp[0]);
            else dis[i] = distance(temp[i], temp[i + 1]);
        }
        // �� ���� �Ÿ� ����
        check = dis[0] < dis[1] ? dis[0] : dis[1];
        check = check < dis[2] ? check : dis[2];
        if (min != -1.0 && min < check) return;
        min = check;
        // �� ���� �Ÿ� ���� ����
        for (int i = 0; i < 3; i++) { // 3���� �����Ÿ� ���ϱ�
            if (min == dis[i]) {
                if (i == 2) min_p[0] = temp[i], min_p[1] = temp[0];
                else min_p[0] = temp[i], min_p[1] = temp[i + 1];
            }
        }
    }
}
```
**�����Ÿ� ��ȯ**
```
doubledistance(point a, point b) { returnsqrt(pow((a.x -b.x), 2.0) +pow((a.y -b.y), 2.0)); }
```


## <�ڵ� ����� ��ũ>
���� : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_3/Quick%20Sort  
���� : https://github.com/20LDH/algorithm_2023  
���� : https://github.com/jwgarde/algorithm-find-nearest-neighbor-pairs  
���� : https://github.com/KANGMUSEOK/-min  
���� : https://github.com/rrrrrrongmo/dot  
���� : 