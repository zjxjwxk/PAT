#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 10001;
vector<int> G[maxn], temp;
set<int> ans;
int n, maxLevel = 0, cnt = 0;
bool vis[maxn] = {false};

void DFS(int root, int level) {
    vis[root] = true;
    if (level > maxLevel) {
        maxLevel = level;
        temp.clear();
        temp.push_back(root);
    } else if (level == maxLevel) {
        temp.push_back(root);
    }
    for (int i = 0; i < G[root].size(); i++) {
        if (vis[G[root][i]] == false) {
            DFS(G[root][i], level + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    int v1, v2;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            cnt++;
            DFS(i, 1);
            if (i == 1) {
                for (int i = 0; i < temp.size(); i++) {
                    ans.insert(temp[i]);
                }
            }
        }
    }
    if (cnt != 1) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        memset(vis + 1, false, n);
        DFS(*(ans.begin()), 1);
        for (int i = 0; i < temp.size(); i++) {
            ans.insert(temp[i]);
        }
        for (auto it = ans.begin(); it != ans.end(); it++) {
            printf("%d\n", *it);
        }
    }
    return 0;
}
