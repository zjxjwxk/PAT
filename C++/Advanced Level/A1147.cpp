#include <cstdio>

const int maxn = 1001;
int m, n, nodes[maxn], cnt = 0;

int ifHeap() {
    int flag = 0;
    for (int i = 2; i <= n; i++) {
        if (nodes[i] > nodes[i / 2]) {
            if (flag == 0) {
                flag = 1;
            } else if (flag == 2) {
                flag = 0;
                break;
            }
        } else {
            if (flag == 0) {
                flag = 2;
            } else if (flag == 1) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void postOrder(int root) {
    if (root > n) {
        return;
    }
    postOrder(root * 2);
    postOrder(root * 2 + 1);
    printf("%d", nodes[root]);
    cnt++;
    if (cnt != n) {
        printf(" ");
    } else {
        printf("\n");
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &nodes[j]);
        }
        int flag = ifHeap();
        if (flag == 0) {
            printf("Not Heap\n");
        } else if (flag == 1) {
            printf("Min Heap\n");
        } else {
            printf("Max Heap\n");
        }
        cnt = 0;
        postOrder(1);
    }
    return 0;
}
