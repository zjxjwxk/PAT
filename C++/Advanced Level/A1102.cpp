#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int data;
    int left;
    int right;
} node[10];

bool flag[10] = {false};
int n, count = 0;

void show_layer(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        count++;
        printf("%d", cur);
        if (count != n) {
            printf(" ");
        }
        if (node[cur].left != -1) {
            q.push(node[cur].left);
        }
        if (node[cur].right != -1) {
            q.push(node[cur].right);
        }
    }
}

void show_inorder(int root) {
    if (root == -1) {
        return;
    }
    show_inorder(node[root].left);
    printf("%d", root);
    count++;
    if (count != n) {
        printf(" ");
    }
    show_inorder(node[root].right);
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        node[i].data = i;
        char c1, c2;
        scanf("%c %c", &c1, &c2);
        getchar();
        if (c1 != '-') {
            node[i].right = c1 - '0';
            flag[c1 - '0'] = true;
        } else {
            node[i].right = -1;
        }
        if (c2 != '-') {
            node[i].left = c2 - '0';
            flag[c2 - '0'] = true;
        } else {
            node[i].left = -1;
        }
    }
    int root;
    for (root = 0; root < n; root++) {
        if (flag[root] == false) {
            break;
        }
    }
    show_layer(root);
    printf("\n");
    count = 0;
    show_inorder(root);
    return 0;
}
