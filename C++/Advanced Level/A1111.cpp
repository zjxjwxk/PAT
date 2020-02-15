#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 500, INF = 1000000000;
int n, m, source, dest, G[maxn][maxn], times[maxn][maxn], d[maxn], t[maxn], counts[maxn] = {0}, pre1[maxn], pre2[maxn];
bool vis[maxn] = {false};
vector<int> path1, path2;

void init() {
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(times[0], times[0] + maxn * maxn, INF);
    for (int i = 0; i < n; i++) {
        pre1[i] = pre2[i] = i;
    }
}

void DijkstraLength() {
    fill(d, d + maxn, INF);
    fill(t, t + maxn, INF);
    d[source] = 0;
    t[source] = 0;
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
                    t[v] = t[u] + times[u][v];
                    pre1[v] = u;
                } else if (d[u] + G[u][v] == d[v]) {
                    if (t[u] + times[u][v] < t[v]) {
                        t[v] = t[u] + times[u][v];
                        pre1[v] = u;
                    }
                }
            }
        }
    }
}

void DijkstraTime() {
    fill(t, t + maxn, INF);
    memset(vis, false, sizeof(vis));
    t[source] = 0;
    counts[source] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && t[j] < min) {
                min = t[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && times[u][v] < INF) {
                if (t[u] + times[u][v] < t[v]) {
                    t[v] = t[u] + times[u][v];
                    counts[v] = counts[u] + 1;
                    pre2[v] = u;
                } else if (t[u] + times[u][v] == t[v]) {
                    if (counts[u] + 1 < counts[v]) {
                        counts[v] = counts[u] + 1;
                        pre2[v] = u;
                    }
                }
            }
        }
    }
}

void createPath(vector<int> &path, int pre[], int root) {
    if (root == pre[root]) {
        path.push_back(root);
        return;
    }
    createPath(path, pre, pre[root]);
    path.push_back(root);
}

void printPath(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        printf("%d", path[i]);
        if (i != path.size() - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    int v1, v2, flag, length, time;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &v1, &v2, &flag, &length, &time);
        G[v1][v2] = length;
        times[v1][v2] = time;
        if (flag == 0) {
            G[v2][v1] = length;
            times[v2][v1] = time;
        }
    }
    scanf("%d %d", &source, &dest);
    DijkstraLength();
    DijkstraTime();
    createPath(path1, pre1, dest);
    createPath(path2, pre2, dest);
    if (path1 == path2) {
        printf("Distance = %d; Time = %d: ", d[dest], t[dest]);
        printPath(path1);
    } else {
        printf("Distance = %d: ", d[dest]);
        printPath(path1);
        printf("Time = %d: ", t[dest]);
        printPath(path2);
    }
    return 0;
}
