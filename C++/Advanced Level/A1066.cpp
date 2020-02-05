#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    int height;
    Node *left;
    Node *right;
};

const int maxn = 20;
int n;

Node* newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int getHeight(Node* root) {
    if (root == 0) {
        return 0;
    } else {
        return root->height;
    }
}

void updateHeight(Node* root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBF(Node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

void R(Node* &root) {
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void L(Node* &root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node* &root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else {
        if (data < root->data) {
            insert(root->left, data);
            updateHeight(root);
            if (getBF(root) == 2) {
                if (getBF(root->left) == 1) {
                    R(root);
                } else if (getBF(root->left) == -1) {
                    L(root->left);
                    R(root);
                }
            }
        } else {
            insert(root->right, data);
            updateHeight(root);
            if (getBF(root) == -2) {
                if (getBF(root->right) == -1) {
                    L(root);
                } else if (getBF(root->right) == 1) {
                    R(root->right);
                    L(root);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    Node* root = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(root, data);
    }
    printf("%d", root->data);
    return 0;
}
