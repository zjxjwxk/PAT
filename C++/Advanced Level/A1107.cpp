#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1001;
int n, father[maxn], course[maxn], root[maxn];

int cmp(int a, int b) {
    return a > b;
}

void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        root[i] = 0;
    }
}

int getFather(int i) {
    int a = i;
    while (i != father[i]) {
        i = father[i];
    }
    while (a != father[a]) {
        int x = a;
        a = father[a];
        father[x] = i;
    }
    return i;
}

void Union(int i, int j) {
    int father1 = getFather(i);
    int father2 = getFather(j);
    if (father1 != father2) {
        father[father1] = father2;
    }
}

int main() {
    scanf("%d", &n);
    init();
    int num, hobby, count = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d: ", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &hobby);
            if (course[hobby] == 0) {
                course[hobby] = i;
            }
            Union(i, getFather(course[hobby]));
        }
    }
    for (int i = 1; i <= n; i++) {
        root[getFather(i)]++;
    }
    sort(root + 1, root + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (root[i] == 0) {
            break;
        } else {
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 1; i <= count; i++) {
        printf("%d", root[i]);
        if (i != count) {
            printf(" ");
        }
    }
    return 0;
}
