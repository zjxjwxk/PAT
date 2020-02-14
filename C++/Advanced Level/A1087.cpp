#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 200, INF = 1000000000;
int n, k, G[maxn][maxn], happy[maxn] = {0}, 
    c[maxn], h[maxn] = {0}, num[maxn] = {0}, 
    pre[maxn], counts[maxn] = {0};
bool vis[maxn] = {false};
string start;
map<string, int> strToInt;
map<int, string> intToStr;

void init() {
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(c, c + maxn, INF);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
}

void Dijkstra() {
    c[0] = 0;
    h[0] = 0;
    num[0] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && c[j] < min) {
                min = c[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (c[u] + G[u][v] < c[v]) {
                    c[v] = c[u] + G[u][v];
                    h[v] = h[u] + happy[v];
                    pre[v] = u;
                    num[v] = num[u];
                    counts[v] = counts[u] + 1;
                } else if (c[u] + G[u][v] == c[v]) {
                    if (h[u] + happy[v] > h[v]) {
                        h[v] = h[u] + happy[v];
                        pre[v] = u;
                        counts[v] = counts[u] + 1;
                    } else if (h[u] + happy[v] == h[v]) {
                        double avg1 = 1.0 * h[v] / counts[v];
                        double avg2 = 1.0 * h[v] / (counts[u] + 1);
                        if (avg2 > avg1) {
                            pre[v] = u;
                            counts[v] = counts[u] + 1;
                        }
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

void printPath(int i) {
    if (i == pre[i]) {
        cout << intToStr[i];
        return;
    }
    printPath(pre[i]);
    cout << "->" << intToStr[i];
}

int main() {
    cin >> n >> k >> start;
    init();
    strToInt[start] = 0;
    intToStr[0] = start;
    string v;
    int happiness;
    for (int i = 1; i <= n - 1; i++) {
        cin >> v >> happiness;
        strToInt[v] = i;
        intToStr[i] = v;
        happy[i] = happiness;
    }
    string v1, v2;
    int cost;
    for (int i = 0; i < k; i++) {
        cin >> v1 >> v2 >> cost;
        int id1 = strToInt[v1], id2 = strToInt[v2];
        G[id1][id2] = G[id2][id1] = cost;
    }
    Dijkstra();
    string destStr = "ROM";
    int dest = strToInt[destStr];
    printf("%d %d %d %d\n", num[dest], c[dest], h[dest], h[dest] / counts[dest]);
    printPath(dest);
    return 0;
}
