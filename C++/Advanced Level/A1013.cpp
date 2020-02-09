#include <cstdio>

const int maxn = 1000;
int n, m, k, enemy, G[maxn][maxn] = {0};

void DFS(int root, bool vis[]) {
    for (int i = 1; i <= n; i++) {
        if (i != enemy && G[root][i] == 1 && vis[i] == false) {
            vis[i] = true;
            DFS(i, vis);
        }
    }
}

int getAns(bool vis[]) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i != enemy && vis[i] == false) {
            ans++;
            vis[i] = true;
            DFS(i, vis);
        }
    }
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &enemy);
        bool vis[maxn] = {false};
        printf("%d\n", getAns(vis) - 1);
    }
    return 0;
}
