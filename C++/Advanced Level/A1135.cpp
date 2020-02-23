#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 30;
int k, n, tempBlackCnt = 0, pre[maxn];

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

Node* insert(Node *root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    if (abs(data) < abs(root->data)) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool ifRBT(Node *root, int preData, int blackCnt) {
    if (root == NULL) {
        if (tempBlackCnt == 0) {
            tempBlackCnt = blackCnt;
            return true;
        } else if (blackCnt == tempBlackCnt) {
            return true;
        } else {
            return false;
        }
    }
    if (preData < 0 && root->data < 0) {
        return false;
    } else {
        if (root->data > 0) {
            blackCnt++;
        }
        return ifRBT(root->left, root->data, blackCnt) && ifRBT(root->right, root->data, blackCnt);
    }
}

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        Node *root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &pre[j]);
            root = insert(root, pre[j]);
        }
        if (pre[0] < 0) {
            printf("No\n");
        } else {
            tempBlackCnt = 0;
            if (ifRBT(root, 0, 0) == true) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
