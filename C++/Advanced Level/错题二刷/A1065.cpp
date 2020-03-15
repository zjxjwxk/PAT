#include <cstdio>

int main() {
    int t;
    long long a, b, c;
    bool flag;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        long long res = a + b;
        if (a > 0 && b > 0 && res < 0) {
            flag = true;
        } else if (a < 0 && b < 0 && res >= 0) {
            flag = false;
        } else if (res > c) {
            flag = true;
        } else {
            flag = false;
        }
        printf("Case #%d: %s\n", i, flag ? "true" : "false");
    }
    return 0;
}
