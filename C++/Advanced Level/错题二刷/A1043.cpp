#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1000;
int n, index = 0;
vector<int> pre, treePre;
bool isBST = true, isMirrBST = true, isRoot = true;

struct Node {
    int data;
    Node *left, *right;
} *root = NULL, *mirrRoot = NULL;

Node* insert(Node *root, int data) {
    if (root == NULL) {
        Node *node = new Node;
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* mirrInsert(Node *root, int data) {
    if (root == NULL) {
        Node *node = new Node;
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }
    if (data >= root->data) {
        root->left = mirrInsert(root->left, data);
    } else {
        root->right = mirrInsert(root->right, data);
    }
    return root;
}

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    treePre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    if (isRoot) {
        isRoot = false;
    } else {
        printf(" ");
    }
    printf("%d", root->data);
}

int main() {
    scanf("%d", &n);
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        pre.push_back(data);
        root = insert(root, data);
        mirrRoot = mirrInsert(mirrRoot, data);
    }
    preOrder(root);
    if (treePre == pre) {
        printf("YES\n");
        postOrder(root);
    } else {
        treePre.clear();
        preOrder(mirrRoot);
        if (treePre == pre) {
            printf("YES\n");
            postOrder(mirrRoot);
        } else {
            printf("NO");
        }
    }
    return 0;
}
