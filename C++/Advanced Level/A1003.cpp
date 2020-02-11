#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500, INF = 100000000;
int n, m, c1, c2, teams[maxn], G[maxn][maxn], t[maxn], d[maxn], num[maxn] = {0};
bool vis[maxn] = {false};

void init() {
    for (int i = 0; i < n; i++) {
        fill(G[i], G[i] + n, INF);
    }
    fill(d, d + n, INF);
}

void Dijkstra() {
    d[c1] = 0;
    t[c1] = teams[c1];
    num[c1] = 1;
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
                    t[v] = t[u] + teams[v];
                    num[v] = num[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    if (t[u] + teams[v] > t[v]) {
                        t[v] = t[u] + teams[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    init();
    for (int i = 0; i < n; i++) {
        scanf("%d", &teams[i]);
    }
    int v1, v2, dis;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &dis);
        G[v1][v2] = dis;
        G[v2][v1] = dis;
    }
    Dijkstra();
    printf("%d %d", num[c2], t[c2]);
    return 0;
}
