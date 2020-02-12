#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500, INF = 1000000000;
int n, m, s, D, G[maxn][maxn], cost[maxn][maxn], d[maxn], c[maxn], pre[maxn];
bool vis[maxn] = {false};

void init() {
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
}

void Dijsktra() {
    d[s] = 0;
    c[s] = 0;
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
            if (vis[v] == false && G[u][v] < INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if (d[u] + G[u][v] == d[v]) {
                    if (c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void printPath(int i) {
    if (i == pre[i]) {
        printf("%d ", i);
        return;
    }
    printPath(pre[i]);
    printf("%d ", i);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &D);
    init();
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        scanf("%d %d", &G[v1][v2], &cost[v1][v2]);
        G[v2][v1] = G[v1][v2];
        cost[v2][v1] = cost[v1][v2];
    }
    Dijsktra();
    printPath(D);
    printf("%d %d", d[D], c[D]);
    return 0;
}
