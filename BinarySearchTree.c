#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// 노드 생성 함수
Node* createNode(int key) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}

// 노드 삽입 함수
Node* insert(Node* p, int key) {
    if (p == NULL) return createNode(key);
    if (key < p->key) p->left = insert(p->left, key);
    else if (key > p->key) p->right=insert(p->right,key);
    return p;
}

// 중위순회 함수(오름차순 목록을 얻는다)
void inorder(Node* p) {
    if(p == NULL) return;
    inorder(p->left);
    printf("%d ", p->key);
    inorder(p->right);
}

// 노드 탐색 함수(재귀적 구현)
Node* search(Node* p, int key) {
    if (p == NULL) return NULL;
    if (key == p->key) return p;
    if (key < p->key) return search(p->left, key);
    return search(p->right, key);
}

// 노드 탐색 함수(반복적 구현)
Node* isearch(Node* p, int key) {
    while (p != NULL) {
        if (key == p->key) return p;
        if (key < p->key) p=p->left;
        else p = p->right;
    }
    return NULL;
}

// 최솟값 반환 함수
Node* min(Node* p) {
    if (p == NULL) return NULL;
    while (p->left != NULL) p=p->left;
    return p;
}

// 최댓값 반환 함수
Node* max(Node* p) {
    if (p == NULL) return NULL;
    while (p->right != NULL) p=p->right;
    return p;
}

// 노드 삭제 함수
Node* delete(Node* p, int key){
    if (p == NULL) return NULL;
    if (key < p->key) {
        p->left=delete(p->left, key);
        return p;
    }
    if (key > p->key) {
        p->right=delete(p->right, key);
        return p;
    }
    if (p->left == NULL) {
        Node *t=p->right;
        free(p);
        return t;
    }
    if (p->right == NULL) {
        Node *t=p->left;
        free(p);
        return t;
    }
    Node *next = p->right;
    while (next->left!=NULL) next=next->left;
    p->key = next->key;
    p->right = delete(p->right,next->key);
    return p;
}

int main(void){
    Node *root = NULL;
    int v[] = {35,18,68,7,26,99,3,12,22,30};
    for(int i=0; i<10; i++) root = insert(root,v[i]);
    inorder(root);
    return 0;
}