#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int coins[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins, coins + n);
    int i = 0, j = n - 1;
    while (i < j) {
        while (coins[j] > m - coins[i]) {
            j--;
        }
        if (coins[i] + coins[j] == m) {
            break;
        }
        i++;
    }
    if (i >= j) {
        printf("No Solution");
    } else {
        printf("%d %d", coins[i], coins[j]);
    }
    return 0;
}
