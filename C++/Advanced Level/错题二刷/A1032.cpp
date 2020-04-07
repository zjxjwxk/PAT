#include <cstdio>

const int maxn = 100000;

struct Node {
    char data;
    int next;
    bool flag = false;
} nodes[maxn];

int main() {
    int root1, root2, n, address, next;
    char data;
    scanf("%d %d %d", &root1, &root2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf(" %c %d", &nodes[address].data, &nodes[address].next);
    }
    int cur = root1;
    while (cur != -1) {
        nodes[cur].flag = true;
        cur = nodes[cur].next;
    }
    cur = root2;
    while (cur != -1) {
        if (nodes[cur].flag == true) {
            printf("%05d", cur);
            return 0;
        }
        cur = nodes[cur].next;
    }
    printf("-1");
    return 0;
}
