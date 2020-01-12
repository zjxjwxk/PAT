#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    double v;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &v);
        sum += v * i * (n + 1 - i);
    }
    printf("%.2lf", sum);
    return 0;
}
