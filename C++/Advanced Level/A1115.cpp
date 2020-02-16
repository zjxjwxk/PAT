#include <cstdio>

const int maxn = 1001;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insert(Node* &root, int data, int level) {
    if (root == NULL) {
        root = newNode(data);
        return level;
    }
    if (data <= root->data) {
        insert(root->left, data, level + 1);
    } else {
        insert(root->right, data, level + 1);
    }
}

int main() {
    int n, data, level, levels[maxn] = {0}, max_level = 1;
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        level = insert(root, data, 1);
        levels[level]++;
        if (level > max_level) {
            max_level = level;
        }
    }
    printf("%d + %d = %d", levels[max_level], levels[max_level - 1], levels[max_level] + levels[max_level - 1]);
    return 0;
}
