#include <cstdio>
#include <stack>
using namespace std;

struct Node {
    char data;
    int next;
    bool flag;
} node[100000];

int main() {
    int a1, a2, n;
    scanf("%d %d %d", &a1, &a2, &n);
    for (int i = 0; i < n; i++) {
        int index;
        scanf("%d%*c", &index);
        scanf("%c %d", &node[index].data, &node[index].next);
        node[index].flag = false;
    }
    for (int i = a1; i != -1; i = node[i].next) {
        node[i].flag = true;
    }
    int i;
    for (i = a2; i != -1; i = node[i].next) {
        if (node[i].flag == true) {
            break;
        }
    }
    if (i == -1) {
        printf("-1");
    } else {
        printf("%05d", i);
    }
    return 0;
}
