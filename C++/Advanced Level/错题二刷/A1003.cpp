#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500, INF = 1000000000;
int n, m, c1, c2, weight[maxn], G[maxn][maxn], d[maxn], w[maxn] = {0}, nums[maxn] = {0};
bool vis[maxn] = {false};

void Dijkstra() {
    fill(d, d + maxn, INF);
    d[c1] = 0;
    w[c1] = weight[c1];
    nums[c1] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    nums[v] = nums[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    nums[v] += nums[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    int v1, v2, len;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &len);
        G[v1][v2] = G[v2][v1] = len;
    }
    Dijkstra();
    printf("%d %d", nums[c2], w[c2]);
    return 0;
}
