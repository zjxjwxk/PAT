#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int hash_table[10001];
    int bets[100000];
    int num = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &bets[num]);
        hash_table[bets[num]]++;
        num++;
    }
    int i;
    for (i = 0; i < num; i++) {
        if (hash_table[bets[i]] == 1) {
            printf("%d", bets[i]);
            break;
        }
    }
    if (i == num) {
        printf("None");
    }
    return 0;
}
