#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1001;
int n, data[maxn], node[maxn], index = 0;

void inorder(int root) {
    if (root > n) {
        return;
    }
    inorder(root * 2);
    node[root] = data[index++];
    inorder(root * 2 + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + n);
    inorder(1);
    for (int i = 1; i <= n; i++) {
        printf("%d", node[i]);
        if (i != n) {
            printf(" ");
        }
    }
    return 0;
}

/*
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

const int maxn = 1000;
int n, data[maxn], num = 0, index = 0;

Node* newNode() {
    Node *node = new Node;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* create_CBT(Node *root) {
    queue<Node*> q;
    q.push(root);
    num++;
    while (!q.empty() && num != n) {
        Node *node = q.front();
        q.pop();
        if (num != n) {
            Node *left = newNode();
            node->left = left;
            q.push(left);
            num++;
        }
        if (num != n) {
            Node *right = newNode();
            node->right = right;
            q.push(right);
            num++;
        }
    }
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    root->data = data[index++];
    inorder(root->right);
}

void show_level(Node *root) {
    queue<Node*> q;
    q.push(root);
    num = 0;
    while(!q.empty()) {
        Node *node = q.front();
        q.pop();
        num++;
        printf("%d", node->data);
        if (num != n) {
            printf(" ");
        }
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + n);
    Node *root = newNode();
    create_CBT(root);
    inorder(root);
    show_level(root);
    return 0;
}
*/
