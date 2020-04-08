#include <cstdio>

const int maxn = 1000;
int n, pre[maxn], treePre[maxn], index = 0;
bool isBST = true, isMirrBST = true, isRoot = true;

struct Node {
    int data;
    Node *left, *right;
} root;

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

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    treePre[index++] = root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void mirrPreOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    treePre[index++] = root->data;
    mirrPreOrder(root->right);
    mirrPreOrder(root->left);
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

void mirrPostOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    mirrPostOrder(root->right);
    mirrPostOrder(root->left);
    if (isRoot) {
        isRoot = false;
    } else {
        printf(" ");
    }
    printf("%d", root->data);
}

int main() {
    scanf("%d", &n);
    Node *root = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        root = insert(root, pre[i]);
    }
    preOrder(root);
    for (int i = 0; i < n; i++) {
        if (pre[i] != treePre[i]) {
            isBST = false;
            break;
        }
    }
    if (isBST) {
        printf("YES\n");
        postOrder(root);
    } else {
        index = 0;
        mirrPreOrder(root);
        for (int i = 0; i < n; i++) {
            if (pre[i] != treePre[i]) {
                isMirrBST = false;
                break;
            }
        }
        if (isMirrBST) {
            printf("YES\n");
            isRoot = true;
            mirrPostOrder(root);
        } else {
            printf("NO");
        }
    }
    return 0;
}
