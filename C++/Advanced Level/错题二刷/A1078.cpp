#include <cstdio>
#include <cmath>

const int maxn = 10010;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    } else if (n == 2) {
        return true;
    } else {
        int q = (int) sqrt(1.0 * n);
        for (int i = 2; i <= q; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    int tSize, n, nums[maxn] = {0}, num;
    scanf("%d %d", &tSize, &n);
    while (!isPrime(tSize)) {
        tSize++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        int index = num % tSize;
        if (nums[index] == 0) {
            nums[index] = num;
            if (i != 0) {
                printf(" ");
            }
            printf("%d", index);
        } else {
            int j;
            for (j = 1; j <= tSize; j++) {
                index = (num + j * j) % tSize;
                if (nums[index] == 0) {
                    nums[index] = num;
                    printf(" %d", index);
                    break;
                }
            }
            if (j > tSize) {
                printf(" -");
            }
        }
    }
    return 0;
}
