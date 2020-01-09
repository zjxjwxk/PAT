#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int nc, np;
    scanf("%d", &nc);
    int c[100000], p[100000];
    for (int i = 0; i < nc; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }
    sort(c, c + nc);
    sort(p, p + np);
    int i1 = 0, j1 = nc - 1, i2 = 0, j2 = np - 1;
    int ans = 0;
    while (c[j1] > 0 && p[j2] > 0) {
        ans += c[j1--] * p[j2--];
    }
    while (c[i1] < 0 && p[i2] < 0) {
        ans += c[i1++] * p[i2++];
    }
    printf("%d", ans);
    return 0;
}
