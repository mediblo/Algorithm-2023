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