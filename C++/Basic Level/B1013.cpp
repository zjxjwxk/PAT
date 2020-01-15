#include <cstdio>
#include <cmath>

// 埃式筛法 O(nloglogn)，获取素数表 
const int maxn = 1000001;
int prime[10000], num = 0;
int p[maxn] = {0};

void find_prime(int n) {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == false) {
            prime[num++] = i;
            if (num == n) {
                break;
            }
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    find_prime(n);
    int count = 0;
    for (int i = m - 1; i <= n - 1; i++) {
        printf("%d", prime[i]);
        count++;
        if (count % 10 == 0) {
            printf("\n");
        } else if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}

/*
//  暴力获取素数表 
const int maxn = 10000;
int prime[maxn], num = 0;

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

void find_prime(int n) {
    int i = 2;
    while (num != n) {
        if (is_prime(i) == true) {
            prime[num++] = i;
        }
        i++;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    find_prime(n);
    int count = 0;
    for (int i = m - 1; i <= n - 1; i++) {
        printf("%d", prime[i]);
        count++;
        if (count % 10 == 0) {
            printf("\n");
        } else if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}
*/
