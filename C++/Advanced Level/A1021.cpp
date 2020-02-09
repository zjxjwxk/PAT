#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10001;
int n;
vector<int> G[maxn];
bool total_vis[maxn];

bool DFS(int root, int pre, bool vis[], int level, int &max_level) {
    vis[root] = true;
    total_vis[root] = true;
    if (level > max_level) {
        max_level = level;
    }
    for (int i = 0; i < G[root].size(); i++) {
        int v = G[root][i];
        if (v != pre) {
            if (vis[v] == false) {
                if (DFS(v, root, vis, level + 1, max_level) == false) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int v1, v2;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int max = 0, deepest[maxn], num = 0, k = 1;
    bool isTree = true;
    for (int i = 1; i <= n; i++) {
        bool vis[maxn] = {false};
        int max_level = 0;
        if (i > 1 && total_vis[i] == false) {
            isTree = false;
            k++;
        }
        if (DFS(i, 0, vis, 0, max_level) == false) {
            isTree = false;
        }
        if (isTree) {
            if (max_level == max) {
                deepest[num++] = i;
            } else if (max_level > max) {
                max = max_level;
                num = 0;
                deepest[num++] = i;
            }
        }
    }
    sort(deepest, deepest + num);
    if (isTree) {
        for (int i = 0; i < num; i++) {
            printf("%d\n", deepest[i]);
        }
    } else {
        printf("Error: %d components", k);
    }
    return 0;
}
