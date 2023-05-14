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