#include <cstdio>
#include <cmath>

struct Factor {
    int x;
    int count;
} factors[10];

const int maxn = 100000;
int prime[maxn], prime_num = 0, factor_num = 0;
int p[maxn] = {0};

void find_prime(int n) {
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++) {
        if (p[i] == false) {
            prime[prime_num++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    int origin, n;
    scanf("%d", &origin);
    n = origin;
    find_prime(n);
    for (int i = 0; i < prime_num; i++) {
        if (prime[i] > n) {
            break;
        }
        if (n % prime[i] == 0) {
            factors[factor_num].x = prime[i];
            factors[factor_num].count = 0;
            while (n % prime[i] == 0) {
                factors[factor_num].x = prime[i];
                factors[factor_num].count++;
                n /= prime[i];
            }
            factor_num++;
        }
    }
    if (n > 1) {
        factors[factor_num].x = n;
        factors[factor_num++].count = 1;
    }
    printf("%d=", origin);
    if (origin == 1) {
        printf("1");
    } else {
        for (int i = 0; i < factor_num; i++) {
            printf("%d", factors[i].x);
            if (factors[i].count > 1) {
                printf("^%d", factors[i].count);
            }
            if (i != factor_num - 1) {
                printf("*");
            }
        }
    }
    return 0;
}
