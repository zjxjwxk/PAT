#include <cstdio>
#include <cstring>

const int maxn = 21;
int n, root = 1;

struct Node {
    char data[11];
    int left;
    int right;
} nodes[maxn];

void inorder(int temp_root) {
    if (strcmp(nodes[temp_root].data, "-") == 0 && nodes[temp_root].left == -1 && temp_root != root) {
        printf("(");
    }
    if (nodes[temp_root].left != -1) {
        if (temp_root != root) {
            printf("(");
        }
        inorder(nodes[temp_root].left);
    }
    printf("%s", nodes[temp_root].data);
    if (nodes[temp_root].right != -1) {
        inorder(nodes[temp_root].right);
        if (temp_root != root) {
            printf(")");
        }
    }
}

int main() {
    scanf("%d", &n);
    char data[11];
    bool flag[maxn] = {false};
    for (int i = 1; i <= n; i++) {
        scanf("%s %d %d", nodes[i].data, &nodes[i].left, &nodes[i].right);
        if (nodes[i].left != -1) {
            flag[nodes[i].left] = true;
        }
        if (nodes[i].right != -1) {
            flag[nodes[i].right] = true;
        }
    }
    while (flag[root] == true) {
        root++;
    }
    inorder(root);
    return 0;
}
