#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> node[maxn];
int n, m, count[maxn], max_level = 0;

void DFS(int root, int level) {
    if (level > max_level) {
        max_level = level;
    }
    if (node[root].size() == 0) {
        count[level]++;
    } else {
        for (int i = 0; i < node[root].size(); i++) {
            DFS(node[root][i], level + 1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int child_num, id, child;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &child_num);
        for (int j = 0; j < child_num; j++) {
            scanf("%d", &child);
            node[id].push_back(child);
        }
    }
    DFS(1, 1);
    for (int i = 1; i <= max_level; i++) {
        printf("%d", count[i]);
        if (i != max_level) {
            printf(" ");
        }
    }
    return 0;
}
