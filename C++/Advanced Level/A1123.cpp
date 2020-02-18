#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    int height = 1;
};

int n;

int getHeight(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->height;
    }
}

int getBF(Node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

Node* newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void updateHeight(Node *root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void L(Node* &root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node* &root) {
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node* &root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
    updateHeight(root);
    if (getBF(root) == 2) {
        if (getBF(root->left) == 1) {
            R(root);
        } else if (getBF(root->left) == -1) {
            L(root->left);
            R(root);
        }
    } else if (getBF(root) == -2) {
        if (getBF(root->right) == -1) {
            L(root);
        } else if (getBF(root->right) == 1) {
            R(root->right);
            L(root);
        }
    }
}

bool levelOrder(Node *root) {
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    bool flag = true;
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) {
            if (cnt != n) {
                flag = false;
            }
        } else {
            cnt++;
            printf("%d", temp->data);
            if (cnt != n) {
                printf(" ");
            } else {
                printf("\n");
            }
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return flag;
}

int main() {
    scanf("%d", &n);
    int data;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(root, data);
    }
    if (levelOrder(root)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
