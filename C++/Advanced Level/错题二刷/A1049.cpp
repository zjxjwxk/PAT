#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int i, leftNum = n, rightNum, e = 1, ans = 0;
    while (leftNum != 0) {
        i = n / e % 10;
        leftNum /= 10;
        rightNum = n % e;
        if (i > 1) {
            ans += (leftNum + 1) * e;
        } else if (i == 1) {
            ans += leftNum * e + rightNum + 1;
        } else {
            ans += leftNum * e;
        }
        e *= 10;
    }
    printf("%d", ans);
    return 0;
}
