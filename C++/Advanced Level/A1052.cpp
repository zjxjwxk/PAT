#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;

struct Node {
    int address;
    int key;
    int next;
    int flag = 0;
} node[maxn];

int cmp(Node n1, Node n2) {
    if (n1.flag == 0 || n2.flag == 0) {
        return n1.flag > n2.flag;
    } else {
        return n1.key < n2.key;
    }
}

int main() {
    int n, head;
    scanf("%d %d", &n, &head);
    int count = 0;
    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        node[address].address = address;
        scanf("%d %d", &node[address].key, &node[address].next);
    }
    int k = head;
    while (k != -1) {
        node[k].flag = 1;
        count++;
        k = node[k].next;
    }
    if (count == 0) {
        printf("0 -1");
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].address);
        for (int i = 0; i < count; i++) {
            if (i == count - 1) {
                node[i].next = -1;
                printf("%05d %d -1", node[i].address, node[i].key);
            } else {
                node[i].next = node[i + 1].address;
                printf("%05d %d %05d\n", node[i].address, node[i].key, node[i].next);
            }
        }
    }
    return 0;
}
