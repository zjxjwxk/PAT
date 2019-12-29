#include <cstdio>

int main() {
    double ans[1010] = {0};
    int n, e, count = 0;
    double k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        scanf("%lf", &k);
        ans[e] += k;
    }
    count += n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        scanf("%lf", &k);
        if (ans[e] == 0) {
            count++;
        }
        ans[e] += k;
        if (ans[e] == 0) {
            count--;
        }
    }
    printf("%d", count);
    for (int i = 1000; i >= 0; i--) {
        if (ans[i] != 0) {
            printf(" %d %.1lf", i, ans[i]);
            count--;
        }
    }
    return 0;
}
