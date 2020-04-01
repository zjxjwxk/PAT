#include <cstdio>

const int maxn = 1000000;
int m, n, prime[maxn], cnt = 1;
bool flag[maxn] = {false};

void findPrime() {
    for (int i = 2; i < maxn; i++) {
        if (flag[i] == false) {
            prime[cnt++] = i;
            for (int j = i + i; j < maxn; j += i) {
                flag[j] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    findPrime();
    for (int i = m; i <= n; i++) {
        printf("%d", prime[i]);
        if ((i - m + 1) % 10 == 0) {
            printf("\n");
        } else if (i != n) {
            printf(" ");
        }
    }
    return 0;
}
