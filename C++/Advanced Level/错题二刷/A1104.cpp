#include <cstdio>

const int maxn = 100000;

int main() {
    int n;
    scanf("%d", &n);
    double temp, ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &temp);
        ans += temp * i * (n - i + 1);
    }
    printf("%.2f", ans);
    return 0;
}
