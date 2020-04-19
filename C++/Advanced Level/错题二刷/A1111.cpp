#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 500, INF = 1000000000;
int n, m, source, dest, Gl[maxn][maxn], Gt[maxn][maxn], d[maxn], t[maxn], num[maxn] = {0}, path1[maxn], path2[maxn];
bool vis[maxn] = {false};
vector<int> vec1, vec2;

void Dijkstra1(int root) {
    fill(d, d + maxn, INF);
    fill(t, t + maxn, INF);
    d[root] = 0;
    t[root] = 0;
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
            if (vis[v] == false && Gl[u][v] != INF) {
                if (d[u] + Gl[u][v] < d[v]) {
                    d[v] = d[u] + Gl[u][v];
                    t[v] = t[u] + Gt[u][v];
                    path1[v] = u;
                } else if (d[u] + Gl[u][v] == d[v]) {
                    if (t[u] + Gt[u][v] < t[v]) {
                        t[v] = t[u] + Gt[u][v];
                        path1[v] = u;
                    }
                }
            }
        }
    }
}

void Dijkstra2(int root) {
    fill(t, t + maxn, INF);
    fill(vis, vis + maxn, false);
    t[root] = 0;
    num[root] = 1;
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
            if (vis[v] == false && Gt[u][v] != INF) {
                if (t[u] + Gt[u][v] < t[v]) {
                    t[v] = t[u] + Gt[u][v];
                    num[v] = num[u] + 1;
                    path2[v] = u;
                } else if (t[u] + Gt[u][v] == t[v]) {
                    if (num[u] + 1 < num[v]) {
                        num[v] = num[u] + 1;
                        path2[v] = u;
                    }
                }
            }
        }
    }
}

void getVec(int dest, int path[], vector<int> &vec) {
    if (path[dest] == source) {
        vec.push_back(source);
        vec.push_back(dest);
        return;
    }
    getVec(path[dest], path, vec);
    vec.push_back(dest);
}

void printPath(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i != 0) {
            printf(" -> ");
        }
        printf("%d", vec[i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    fill(Gl[0], Gl[0] + maxn * maxn, INF);
    fill(Gt[0], Gt[0] + maxn * maxn, INF);
    int v1, v2, one, length, time;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &v1, &v2, &one, &length, &time);
        Gl[v1][v2] = length;
        Gt[v1][v2] = time;
        if (one == 0) {
            Gl[v2][v1] = length;
            Gt[v2][v1] = time;
        }
    }
    scanf("%d %d", &source, &dest);
    Dijkstra1(source);
    getVec(dest, path1, vec1);
    Dijkstra2(source);
    getVec(dest, path2, vec2);
    if (vec1 == vec2) {
        printf("Distance = %d; Time = %d: ", d[dest], t[dest]);
        printPath(vec1);
    } else {
        printf("Distance = %d: ", d[dest]);
        printPath(vec1);
        printf("\n");
        printf("Time = %d: ", t[dest]);
        printPath(vec2);
    }
    return 0;
}
