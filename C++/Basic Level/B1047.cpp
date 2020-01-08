#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int hash_table[1001] = {0};
    int max_team = 0, max_score = 0;
    for (int i = 0; i < n; i++) {
        int team, score;
        scanf("%d-%*d %d", &team, &score);
        hash_table[team] += score;
        if (hash_table[team] > max_score) {
            max_team = team;
            max_score = hash_table[team];
        }
    }
    printf("%d %d", max_team, max_score);
    return 0;
}
