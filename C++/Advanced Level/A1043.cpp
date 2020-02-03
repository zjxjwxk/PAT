#include <cstdio>

const int maxn = 1000;

struct Node {
    int data;
    Node* left;
    Node* right;
} node[maxn];

int id[maxn], n, count = 0;

void insert(Node* root, Node* node) {
    if (node->data < root->data) {
        if (root->left == NULL) {
            root->left = node;
        } else {
            insert(root->left, node);
        }
    } else if (node->data >= root->data) {
        if (root->right == NULL) {
            root->right = node;
        } else {
            insert(root->right, node);
        }
    }
}

bool preorder(Node* root, int &index) {
    if (root == NULL) {
        return true;
    }
    if (root->data != id[index]) {
        return false;
    } else {
        index++;
        return preorder(root->left, index) && preorder(root->right, index);
    }
}

bool preorder_mirror(Node* root, int &index) {
    if (root == NULL) {
        return true;
    }
    if (root->data != id[index]) {
        return false;
    } else {
        index++;
        return preorder_mirror(root->right, index) && preorder_mirror(root->left, index);
    }
}

void show_postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    show_postorder(root->left);
    show_postorder(root->right);
    printf("%d", root->data);
    if (count++ != n - 1) {
        printf(" ");
    }
}

void show_postorder_mirror(Node* root) {
    if (root == NULL) {
        return;
    }
    show_postorder_mirror(root->right);
    show_postorder_mirror(root->left);
    printf("%d", root->data);
    if (count++ != n - 1) {
        printf(" ");
    }
}

int main() {
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id[i]);
        Node* node = new Node;
        node->data = id[i];
        node->left = NULL;
        node->right = NULL;
        if (root == NULL) {
            root = node;
        } else {
            insert(root, node);
        }
    }
    int index = 0;
    bool flag = preorder(root, index);
    if (flag == true) {
        printf("YES\n");
        show_postorder(root);
    } else {
        index = 0;
        flag = preorder_mirror(root, index);
        if (flag == true) {
            printf("YES\n");
            show_postorder_mirror(root);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
