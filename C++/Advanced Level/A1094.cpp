#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100;

vector<int> node[maxn];
int n, m, count[maxn], max_level = 0, max_count = 0;

void DFS(int root, int level) {
    count[level]++;
    if (count[level] > max_count) {
        max_count = count[level];
        max_level = level;
    }
    if (node[root].size() == 0) {
        return;
    } else {
        for (int i = 0; i < node[root].size(); i++) {
            DFS(node[root][i], level + 1);
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    int id, child_num, child;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &child_num);
        for (int j = 0; j < child_num; j++) {
            scanf("%d", &child);
            node[id].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d %d", max_count, max_level);
    return 0;
}
