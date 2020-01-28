#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int post[30], in[30];

Node* create(int post_left, int post_right, int in_left, int in_right) {
    if (post_left > post_right) {
        return NULL;
    }
    Node* root = new Node;
    root->data = post[post_right];
    int k;
    for (k = in_left; k <= in_right; k++) {
        if (post[post_right] == in[k]) {
            break;
        }
    }
    int leftNum = k - in_left;
    root->left = create(post_left, post_left + leftNum - 1, in_left, k - 1);
    root->right = create(post_left + leftNum, post_right - 1, k + 1, in_right);
    return root;
}

void show_layer(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
        Node* node = q.front();
        if (flag == true) {
            printf(" ");
        } else {
            flag = true;
        }
        printf("%d", node->data);
        q.pop();
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    Node* root = create(0, n - 1, 0, n - 1);
    show_layer(root);
    return 0;
}
