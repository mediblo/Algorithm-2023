# 알고리즘 설계 구현 결과 : <이진 트리 제작>

## 1. <문제 정의>
- **문제이름**: 이진 트리 제작
- **문제설명**: 각각의 노드가 최대 두 개의 자식 노드를 가지는 트리 자료 구조
- **문제예시** : 다음 그림은 이진 트리에 대한 설명이다.  
![photo](https://i.imgur.com/6UeCp8t.png)

## 2. <함수 정의>
- **기능** : 정렬되지 않은 데이터 값을 정렬하며 원하는 인덱스의 값을 출력한다.
- **프로토타입** : int quick(int A[], int left, int right, int find)

## <C코드 구현 결과>
라이브러리 헤더 파일은 생략 ( stdio.h, stdlib.h )  
tree.h
```C
#pragma once // 한번만 넣어라

typedef struct tNode {
    int data;
    tNode* left;
    tNode* right;
} Node;

Node* make_tree();

void print_node(Node* n);

Node* createNode(int value);
void link(Node* p, Node* l, Node* r);

Node* findNode(Node* n, int value);
Node* insertLeftNode(Node* where, Node* new_node);
Node* insertRightNode(Node* where, Node* new_node);
void destroy(Node* n);

void TC();
```

test.cpp
```C
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void TC() {
	Node* root = make_tree();

    print_node(root);

    printf("\n");
    Node* find = findNode(root, 300);
    if (find == NULL)
        printf("없습니다.\n");
    else
        printf("찾았습니다! : %d\n", find->data);
    printf("\n");

    Node* In_left = createNode(250);
    Node* In_right = createNode(550);

    insertLeftNode(root, In_left);
    insertRightNode(root->right, In_right);

    print_node(root);

    free(In_left);
    free(In_right);
}
```

tree.cpp
```C
#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    int data;
    tNode* left;
    tNode* right;
} Node;

void pre_order(Node* n);
void in_order(Node* n);
void post_order(Node* n);
void print_node(Node* n);

Node* createNode(int value);
void link(Node* p, Node* l = NULL, Node* r = NULL);
Node* make_tree();

Node* findNode(Node* n, int value);
Node* insertLeftNode(Node* where, Node* new_node);
Node* insertRightNode(Node* where, Node* new_node);

void destroy(Node* n);

Node* make_tree() {
    Node* a, * b, * c, * d, * e;

    a = createNode(100);
    b = createNode(200);
    c = createNode(300);
    d = createNode(400);
    e = createNode(500);

    link(a, b, c);
    link(b);
    link(c, d, e);
    link(d);
    link(e);

    return a;
}

void destroy(Node* n) {
    if (n == NULL) return;

    destroy(n->left);
    destroy(n->right);

    free(n);
}

void link(Node* p, Node* l, Node* r) {
    p->left = l;
    p->right = r;
}

Node* createNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void pre_order(Node* n) {
    if (n == NULL) return;

    printf("%d ", n->data);
    pre_order(n->left);
    pre_order(n->right);
}

void in_order(Node* n) {
    if (n == NULL) return;

    in_order(n->left);
    printf("%d ", n->data);
    in_order(n->right);
}

void post_order(Node* n) {
    if (n == NULL) return;

    post_order(n->left);
    post_order(n->right);
    printf("%d ", n->data);
}

void print_node(Node* n) {
    printf("전위 : ");
    pre_order(n);
    printf("\n");

    printf("중위 : ");
    in_order(n);
    printf("\n");

    printf("후위 : ");
    post_order(n);
    printf("\n");
}

Node* findNode(Node* n, int value) {
    if (n == NULL) return NULL;
    if (n->data == value) return n;

    Node* ln = findNode(n->left, value);
    Node* rn = findNode(n->right, value);

    return ln != NULL ? ln : rn;
}

Node* insertLeftNode(Node* where, Node* new_node) {
    if (where == NULL) return NULL;
    Node* n;

    // 댕글링 포인터 조심
    new_node->left = where->left->left;
    new_node->right = where->left->right;

    n = where->left;
    where->left = new_node;

    free(n);

    return where;
}

Node* insertRightNode(Node* where, Node* new_node) {
    if (where == NULL) return NULL;
    Node* n;
    // 댕글링 포인터 조심
    new_node->left = where->right->left;
    new_node->right = where->right->right;

    n = where->right;
    where->right = new_node;

    free(n);

    return where;
}
```

main.cpp
```C
#include "tree.h"

int main() {
	TC();

	return 0;
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_4/tree