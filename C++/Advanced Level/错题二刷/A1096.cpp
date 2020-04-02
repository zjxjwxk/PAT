#include <cstdio>
#include <cmath>

int main() {
    long long n;
    scanf("%lld", &n);
    long long ansI, ansLen = 0, sqr = sqrt(1.0 * n);
    for (long long i = 2; i <= sqr; i++) {
        long long temp = 1;
        for (long long j = i; j <= n ; j++) {
            temp *= j;
            if (n % temp == 0) {
                if (j - i + 1 > ansLen) {
                    ansLen = j - i + 1;
                    ansI = i;
                }
            } else {
                break;
            }
        }
    }
    if (ansLen == 0) {
        printf("1\n%lld", n);
    } else {
        printf("%lld\n", ansLen);
        for (long long i = 0; i < ansLen; i++) {
            printf("%lld", ansI + i);
            if (i != ansLen - 1) {
                printf("*");
            }
        }
    }
    return 0;
}
