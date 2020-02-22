#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    int level;
};

const int maxn = 30;
int n, in[maxn], post[maxn];

Node* newNode(int data, int level) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->level = level;
    return node;
}

Node* create(int left1, int right1, int left2, int right2, int level) {
    if (left1 > right1) {
        return NULL;
    }
    Node *root = newNode(post[right2], level);
    int k;
    for (k = left1; k <= right1; k++) {
        if (in[k] == post[right2]) {
            break;
        }
    }
    int num = k - left1;
    root->left = create(left1, k - 1, left2, left2 + num - 1, level + 1);
    root->right = create(k + 1, right1, left2 + num, right2 - 1, level + 1);
    return root;
}

void level(Node *root) {
    queue<Node*> q;
    q.push(root);
    int cnt = 0, level = 1;
    vector<int> temp;
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (node->level % 2 == 1) {
            temp.push_back(node->data);
        }
        if (node->level % 2 == 0 || q.empty()) {
            for (int i = temp.size() - 1; i >= 0; i--) {
                printf("%d", temp[i]);
                cnt++;
                if (cnt != n) {
                    printf(" ");
                }
            }
            temp.clear();
        }
        if (node->level % 2 == 0) {
            printf("%d", node->data);
            cnt++;
            if (cnt != n) {
                printf(" ");
            }
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
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    Node *root = create(0, n - 1, 0, n - 1, 1);
    level(root);
    return 0;
}
