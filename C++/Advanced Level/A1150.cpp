#include <cstdio>
#include <unordered_set>
using namespace std;

const int maxn = 201, INF = 1000000000;
int n, m, k, G[maxn][maxn] = {0};

int main() {
    scanf("%d %d", &n, &m);
    int v1, v2, dis, num, minSum = INF, minIndex;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &dis);
        G[v1][v2] = G[v2][v1] = dis;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &num);
        int v[maxn], flag = 1, sum = 0;
        unordered_set<int> s;
        for (int j = 0; j < num; j++) {
            scanf("%d", &v[j]);
            s.insert(v[j]);
        }
        for (int j = 0; j < num - 1; j++) {
            if (G[v[j]][v[j + 1]] == 0) {
                flag = 0;
                break;
            } else {
                sum += G[v[j]][v[j + 1]];
            }
        }
        if (flag == 0) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else if (s.size() != n || v[0] != v[num - 1]) {
            printf("Path %d: %d (Not a TS cycle)\n", i, sum);
        } else if (num != n + 1) {
            printf("Path %d: %d (TS cycle)\n", i, sum);
            if (sum < minSum) {
                minSum = sum;
                minIndex = i;
            }
        } else {
            printf("Path %d: %d (TS simple cycle)\n", i, sum);
            if (sum < minSum) {
                minSum = sum;
                minIndex = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d", minIndex, minSum);
    return 0;
}
