#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int hash_table[101] = {0};
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);
        hash_table[score]++;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int query;
        scanf("%d", &query);
        printf("%d", hash_table[query]);
        if (i != k - 1) {
            printf(" ");
        }
    }
    return 0;
}
