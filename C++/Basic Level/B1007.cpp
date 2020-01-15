#include <cstdio>

const int maxn = 100000;
int prime[maxn], num = 0;
int p[maxn] = {0};

void find_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (p[i] == false) {
            prime[num++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    find_prime(n);
    int count = 0;
    for (int i = 1; i < num; i++) {
        if (prime[i + 1] - prime[i] == 2) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
