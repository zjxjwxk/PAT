#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 100;
int n, data[maxn], index = 0, num = 0;

struct Node {
    int data;
    int left;
    int right;
} node[maxn];

void inorder(int root) {
    if (node[root].left != -1) {
        inorder(node[root].left);
    }
    node[root].data = data[index++];
    if (node[root].right != -1) {
        inorder(node[root].right);
    }
}

void show_level(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int id = q.front();
        q.pop();
        printf("%d", node[id].data);
        num++;
        if (num != n) {
            printf(" ");
        }
        if (node[id].left != -1) {
            q.push(node[id].left);
        }
        if (node[id].right != -1) {
            q.push(node[id].right);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &node[i].left);
        scanf("%d", &node[i].right);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + n);
    inorder(0);
    show_level(0);
    return 0;
}
