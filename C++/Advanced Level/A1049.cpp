#include <cstdio>

int main() {
    int n, a = 1, left, now, right, ans = 0;
    scanf("%d", &n);
    while (n / a != 0) {
        left = n / (a * 10);
        now = n % (a * 10) / a;
        right = n % a;
        if (now == 0) {
            ans += left * a;
        } else if (now == 1) {
            ans += left * a + right + 1;
        } else {
            ans += (left + 1) * a;
        }
        a *= 10;
    }
    printf("%d", ans);
    return 0;
}
