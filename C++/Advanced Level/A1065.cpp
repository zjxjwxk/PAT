#include <cstdio>
#include <math.h>

int main() {
    int n; 
    long long a, b, c;
    scanf("%d", &n);
    int a1, b1, c1;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a / 2 + b / 2 == c / 2) {
            printf("Case #%d: %s\n", i, a % 10 + b % 10 > c % 10 ? "true" : "false");
        } else {
            printf("Case #%d: %s\n", i, (a / 2) + (b / 2) > c / 2 ? "true" : "false");
        }
    }
    return 0;
}
