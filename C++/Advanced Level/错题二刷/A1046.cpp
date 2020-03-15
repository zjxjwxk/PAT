#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100001;

int main() {
    int n, m, dis, d[maxn], sum = 0, v1, v2;
    scanf("%d", &n);
    d[1] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dis);
        sum += dis;
        if (i != n) {
            d[i + 1] = sum;
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        int d1 = abs(d[v2] - d[v1]);
        int d2 = sum - abs(d[v2] - d[v1]);
        if (d1 < d2) {
            printf("%d\n", d1);
        } else {
            printf("%d\n", d2);
        }
    }
    return 0;
}
