#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1000;
int n, m, k, q;
vector<int> G[maxn];
bool vis[maxn] = {false};

void DFS(int root) {
    vis[root] = true;
    for (int i = 0; i < G[root].size(); i++) {
        if (G[root][i] != q && vis[G[root][i]] == false) {
            DFS(G[root][i]);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    int c1, c2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c1, &c2);
        G[c1].push_back(c2);
        G[c2].push_back(c1);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &q);
        int cnt = -1;
        memset(vis + 1, false, n);
        for (int j = 1; j <= n; j++) {
            if (j != q && vis[j] == false) {
                DFS(j);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
