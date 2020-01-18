#include <cstdio>
#include <set>
using namespace std;

set<int> sets[51];

int main() {
    int n;
    scanf("%d", &n);
    int m, v;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &v);
            sets[i].insert(v);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int common = 0, total = 0;
        set<int>::iterator it1 = sets[a].begin(), it2 = sets[b].begin();
        while (it1 != sets[a].end() && it2 != sets[b].end()) {
            if (*it1 < *it2) {
                it1++;
            } else if (*it1 > *it2) {
                it2++;
            } else {
                it1++;
                it2++;
                common++;
            }
            total++;
        }
        while (it1 != sets[a].end()) {
            it1++;
            total++;
        }
        while (it2 != sets[b].end()) {
            it2++;
            total++;
        }
        printf("%.1lf%\n", (1.0 * common / total) * 100);
    }
    return 0;
}
