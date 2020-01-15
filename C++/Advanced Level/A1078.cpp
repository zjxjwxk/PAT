#include <cstdio>
#include <cmath>

const int maxn = 100000;

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

int main() {
    int m_size, n;
    scanf("%d %d", &m_size, &n);
    int hash_table[maxn] = {0};
    if (!is_prime(m_size)) {
        for (int i = m_size + 1; i < maxn; i++) {
            if (is_prime(i)) {
                m_size = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        int index = v % m_size, index2;
        if (hash_table[index] != 0) {
            int e;
            for (e = 1; e < m_size; e++) {
                index2 = (index + e * e) % m_size;
                if (hash_table[index2] == 0) {
                    hash_table[index2] = v;
                    printf("%d", index2);
                    break;
                }
            }
            if (e >= m_size) {
                printf("-");
            }
        } else {
            hash_table[index] = v;
            printf("%d", index);
        }
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}
