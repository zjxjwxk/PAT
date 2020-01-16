#include <cstdio>
#include <cmath>

int factors[20], num = 0;

int main() {
    long long n;
    scanf("%lld", &n);
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++) {
        int j = i, temp_factors[20], temp_num = 0;
        long long temp_n = n;
        for (int j = i; j <= sqr; j++) {
            if (temp_n % j == 0) {
                temp_factors[temp_num++] = j;
                temp_n /= j;
                if (temp_n == 1) {
                    break;
                }
            } else {
                break;
            }
        }
        if (temp_num > num) {
            num = temp_num;
            for (int j = 0; j < num; j++) {
                factors[j] = temp_factors[j];
            }
        }
    }
    if (num == 0) {
        printf("1\n");
        printf("%d", n);
    } else {
        printf("%d\n", num);
        for (int i = 0; i < num; i++) {
            printf("%d", factors[i]);
            if (i != num - 1) {
                printf("*");
            }
        }
    }
    return 0;
}
