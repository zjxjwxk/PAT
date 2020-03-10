#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

const int maxn = 10000, maxk = 100;
int n, m, k;
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    int v1, v2, colors[maxn];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        unordered_set<int> colorSet;
        for (int j = 0; j < n; j++) {
            scanf("%d", &colors[j]);
            colorSet.insert(colors[j]);
        }
        int flag = 1;
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < G[j].size(); t++) {
                if (colors[j] == colors[G[j][t]]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 1) {
            printf("%d-coloring\n", colorSet.size());
        } else {
            printf("No\n");
        }
    }
    return 0;
}
