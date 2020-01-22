#include <cstdio>

const int maxn = 100000;

struct Node {
    int address;
    int data;
    int next;
} temp[maxn], node[maxn];

void reverse(int left, int right) {
    while (left < right) {
        Node temp_node = node[left];
        node[left++] = node[right];
        node[right--] = temp_node;
    }
}

int main() {
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        temp[address].address = address;
        scanf("%d %d", &temp[address].data, &temp[address].next);
    }
    int address = head, count = 0;
    while (address != -1) {
        node[count++] = temp[address];
        address = temp[address].next;
    }
    for (int i = 0; i < count; i += k) {
        if (i + k > count) {
            break;
        } else {
            reverse(i, i + k - 1);
        }
    }
    for (int i = 0; i < count; i++) {
        if (i == count - 1) {
            node[i].next = -1;
            printf("%05d %d -1", node[i].address, node[i].data);
        } else {
            node[i].next = node[i + 1].address;
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i].next);
        }
    }
    return 0;
}
