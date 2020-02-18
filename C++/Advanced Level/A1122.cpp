#include <cstdio>

const int maxn = 1000, INF = 1000000000;
int n, m, k, G[maxn][maxn] = {0};

int main() {
    scanf("%d %d", &n, &m);
    int v1, v2, num, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &num);
        int nums[maxn];
        for (int j = 0; j < num; j++) {
            scanf("%d", &nums[j]);
        }
        if (num != n + 1) {
            printf("NO\n");
            continue;
        }
        bool flag[maxn] = {false};
        flag[nums[0]] = true;
        for (int j = 1; j < num; j++) {
            if (G[nums[j - 1]][nums[j]] == 0) {
                printf("NO\n");
                break;
            }
            if (flag[nums[j]] == false) {
                flag[nums[j]] = true;
            } else {
                if (j == num - 1 && nums[j] == nums[0]) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                    break;
                }
            }
        }
    }
    return 0;
}
