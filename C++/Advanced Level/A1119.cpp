#include <cstdio>

struct Node {
    int data;
    Node *left;
    Node *right;
};

const int maxn = 30;
int n, pre[maxn], post[maxn], count = 0;
bool unique = true;

Node* newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* create(int left1, int right1, int left2, int right2) {
    if (left1 > right1) {
        return NULL;
    }
    Node *root = newNode(pre[left1]);
    if (left1 == right1) {
        return root;
    }
    int k;
    for (int i = left1; i <= right1; i++) {
        if (pre[i] == post[right2 - 1]) {
            k = i;
            break;
        }
    }
    int num = k - left1 - 1;
    if (k == left1 + 1) {
        unique = false;
        root->left = NULL;
        root->right = create(left1 + 1, right1, left2, right2 - 1);
    } else {
        root->left = create(left1 + 1, k - 1, left2, left2 + num - 1);
        root->right = create(k, right1, left2 + num, right2 - 1);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    count++;
    if (count != n) {
        printf(" ");
    }
    inorder(root->right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    Node *root = create(0, n - 1, 0, n - 1);
    if (unique == true) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    inorder(root);
    printf("\n");
    return 0;
}
