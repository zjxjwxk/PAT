#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 501;
int n, m, cnt = 0;
vector<int> G[maxn];
bool vis[maxn] = {false};

void DFS(int root) {
    vis[root] = true;
    cnt++;
    for (int i = 0; i < G[root].size(); i++) {
        if (vis[G[root][i]] == false) {
            DFS(G[root][i]);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int evenCnt = 0;
    for (int i = 1; i <= n; i++) {
        printf("%d", G[i].size());
        if (i != n) {
            printf(" ");
        } else {
            printf("\n");
        }
        if (G[i].size() % 2 == 0) {
            evenCnt++;
        }
    }
    DFS(1);
    if (evenCnt == n && cnt == n) {
        printf("Eulerian");
    } else if (evenCnt == n - 2 && cnt == n) {
        printf("Semi-Eulerian");
    } else {
        printf("Non-Eulerian");
    }
    return 0;
}
