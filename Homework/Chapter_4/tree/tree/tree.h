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