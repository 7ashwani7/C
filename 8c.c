// Expression Tree Creation
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        struct Node* newNode = createNode(postfix[i]);

        if (isalnum(postfix[i])) {
            stack[++top] = newNode;
        } else {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }
    return stack[top];
}

void inorder(struct Node* root) {
    if (root) {
        if (!isalnum(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (!isalnum(root->data)) printf(")");
    }
}

int main() {
    char postfix[] = "ab+c*";
    struct Node* root = buildExpressionTree(postfix);

    printf("Infix expression from tree: ");
    inorder(root);
    printf("\n");

    return 0;
}