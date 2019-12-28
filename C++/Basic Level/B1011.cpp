#include <cstdio>

int main() {
    int n;
    long long a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: %s\n", i + 1, a + b > c ? "true" : "false");
    }
    return 0;
}
