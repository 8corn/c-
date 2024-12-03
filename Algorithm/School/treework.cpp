#include <stdio.h>
#include <stdlib.h>
#include <queue>

struct Node {                               // 노드 구조체 정의
    int data;
    struct Node *left, *right;              // 노드의 엣지
};

struct Node* newNode(int data) {            // 새로운 노드를 생성하는 함수
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = data;                    
    node -> left = NULL;                    // 자식 노드에는 비워둠
    node -> right = NULL;
    return node;
}

void preorder(struct Node* root) {          // 전위 순회
    if(root == NULL) 
        return;
    printf(" %d ", root -> data);         // 루트 -> 왼 -> 오
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(struct Node* root) {           // 중위 순회
    if(root == NULL) 
        return;
    inorder(root -> left);                 // 왼 -> 루트 -> 오
    printf(" %d ", root -> data);
    inorder(root -> right);
}

void postorder(struct Node* root) {         // 후위 순회
    if(root == NULL) 
        return;
    postorder(root -> left);                 // 왼 -> 오 -> 루트
    postorder(root -> right);
    printf(" %d ", root -> data);
}

void levelorder(struct Node* root) {        // 레벨 순회
    if(root == NULL) 
        return;
    
    std::queue<struct Node*> q;             // 큐를 이용하여 돌면서 순회
    q.push(root);

    while (!q.empty()) {                    // 루트부어 리프까지 빈칸이 남아있지 않을때까지 계속 루프
        struct Node* node = q.front();
        printf(" %d ", node -> data);
        q.pop();

        if (node -> left != NULL)           // 왼쪽에 자식이 있으면 큐에 추가
            q.push(node -> left);

        if (node -> right != NULL)          // 오른쪽에 자식이 있으면 큐에 추가
            q.push(node -> right);
    }
}

int main() {
    struct Node* root = newNode(1);         // 트리 구성
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(6);

    printf("전위 순회 : ");
    preorder(root);
    printf("\n");

    printf("중위 순회 : ");
    inorder(root);
    printf("\n");

    printf("후위 순회 : ");
    postorder(root);
    printf("\n");

    printf("레벨 순회 : ");
    levelorder(root);
    
    return 0;
}