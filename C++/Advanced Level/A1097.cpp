#include <cstdio>
#include <cstdlib>

const int maxn = 100000;

struct Node {
    int address;
    int key;
    int next;
} node[maxn];

int hash_table[10001] = {0};

void show_list(int k) {
    while (k != -1) {
        if (node[k].next == -1) {
            printf("%05d %d -1\n", node[k].address, node[k].key);
        } else {
            printf("%05d %d %05d\n", node[k].address, node[k].key, node[k].next);
        }
        k = node[k].next;
    }
}

int main() {
    int head, n;
    scanf("%d %d", &head, &n);
    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        node[address].address = address;
        scanf("%d %d", &node[address].key, &node[address].next);
    }
    int pre = head, k = node[head].next, head2 = -1, cur;
    hash_table[abs(node[head].key)] = 1;
    while (k != -1) {
        if (hash_table[abs(node[k].key)] == 1) {
            node[pre].next = node[k].next;
            if (head2 == -1) {
                head2 = node[k].address;
            } else {
                node[cur].next = node[k].address;
            }
            cur = node[k].address;
            node[cur].next = -1;
            k = node[pre].next;
        } else {
            hash_table[abs(node[k].key)] = 1;
            pre = k;
            k = node[k].next;
        }
    }
    show_list(head);
    show_list(head2);
    return 0;
}
