#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1001;
int n, l;
vector<int> childs[maxn];

int BFS(int root) {
    int ans = 0, level[maxn] = {0};
    bool inq[maxn] = {false};
    queue<int> q;
    q.push(root);
    inq[root] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < childs[v].size(); i++) {
            int u = childs[v][i];
            if (inq[u] == false && level[v] + 1 <= l) {
                q.push(u);
                inq[u] = true;
                level[u] = level[v] + 1;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &l);
    int m, parent, k, root;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &parent);
            childs[parent].push_back(i);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &root);
        printf("%d\n", BFS(root));
    }
    return 0;
}
