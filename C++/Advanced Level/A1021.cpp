#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10001;
int n, parent[maxn], root[maxn] = {0}, max_level = 0;
vector<int> G[maxn], temp, ans;

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int findParent(int i) {
    int j = i;
    while (i != parent[i]) {
        i = parent[i];
    }
    while (j != parent[j]) {
        int k = j;
        j = parent[j];
        parent[k] = i;
    }
    return i;
}

void Union(int a, int b) {
    int p1 = findParent(a);
    int p2 = findParent(b);
    if (p1 != p2) {
        parent[p2] = p1;
    }
}

int getNumber() {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (root[i] == 1) {
            num++;
        }
    }
    return num;
}

void DFS(int root, int pre, int level) {
    if (level == max_level) {
        temp.push_back(root);
    } else if (level > max_level) {
        max_level = level;
        temp.clear();
        temp.push_back(root);
    }
    for (int i = 0; i < G[root].size(); i++) {
        if (pre != G[root][i]) {
            DFS(G[root][i], root, level + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    int v1, v2;
    init();
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
        Union(v1, v2);
    }
    for (int i = 1; i <= n; i++) {
        root[findParent(i)] = 1;
    }
    int num = getNumber();
    if (getNumber() > 1) {
        printf("Error: %d components\n", num);
    } else {
        DFS(1, -1, 1);
        ans = temp;
        DFS(ans[0], -1, 1);
        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0 || i > 0 && ans[i] != ans[i - 1]) {
                printf("%d\n", ans[i]);
            }
        }
    }
    return 0;
}
