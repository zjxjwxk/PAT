#include <cstdio>
#include <cmath>

int reverse[31], num = 0;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void to_radix(int n, int d) {
    num = 0;
    while (n != 0) {
        reverse[num++] = n % d;
        n /= d;
    }
}

int to_decimal(int radix) {
    int ret = 0, e = 1;
    for (int i = num - 1; i >= 0; i--) {
        ret += reverse[i] * e;
        e *= radix;
    }
    return ret;
}

int main() {
    int n, d, reverse_10;
    scanf("%d", &n);
    while (n > 0) {
        scanf("%d", &d);
        to_radix(n, d);
        reverse_10 = to_decimal(d);
        if (is_prime(n) && is_prime(reverse_10)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
