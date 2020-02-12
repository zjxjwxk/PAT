#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 501, INF = 1000000000;
int cmax, n, sp, m, c[maxn], G[maxn][maxn], d[maxn], min_need = INF, min_remain = INF;
bool vis[maxn] = {false};
vector<int> pre[maxn], temp_path, path;

void init() {
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(d, d + maxn, INF);
}

void Dijkstra() {
    d[0] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j <= n; j++) {
            if (vis[j] == false && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (vis[v] == false && G[u][v] < INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int root) {
    int need = 0, remain = 0, differ;
    if (root == 0) {
        temp_path.push_back(root);
        for (int i = temp_path.size() - 2; i >= 0; i--) {
            differ = cmax / 2 - c[temp_path[i]];
            if (differ > 0) {
                if (remain <= differ) {
                    need += differ - remain;
                    remain = 0;
                } else {
                    remain -= differ;
                }
            } else if (differ < 0) {
                remain += -differ;
            }
        }
        if (need < min_need) {
            min_need = need;
            min_remain = remain;
            path = temp_path;
        } else if (need == min_need) {
            if (remain < min_remain) {
                min_remain = remain;
                path = temp_path;
            }
        }
        temp_path.pop_back();
        return;
    }
    temp_path.push_back(root);
    for (int i = 0; i < pre[root].size(); i++) {
        DFS(pre[root][i]);
    }
    temp_path.pop_back();
}

int main() {
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    int si, sj;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &si, &sj);
        scanf("%d", &G[si][sj]);
        G[sj][si] = G[si][sj];
    }
    Dijkstra();
    DFS(sp);
    printf("%d ", min_need);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i != 0) {
            printf("->");
        }
    }
    printf(" %d", min_remain);
    return 0;
}
