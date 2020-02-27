#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
    int m, n, key, u, v, a;
    scanf("%d %d", &m, &n);
    map<int, bool> flags;
    vector<int> pre;
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        pre.push_back(key);
        flags[key] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (flags[u] == true && flags[v] == true) {
            for (int j = 0; j < pre.size(); j++) {
                if (pre[j] >= u && pre[j] <= v || pre[j] >= v && pre[j] <= u) {
                    a = pre[j];
                    break;
                }
            }
            if (a == u || a == v) {
                printf("%d is an ancestor of %d.\n", a == u ? u : v, a == u ? v : u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, a);
            }
        } else if (flags[u] == false && flags[v] == false) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else {
            printf("ERROR: %d is not found.\n", flags[u] == false ? u : v);
        }
    }
    return 0;
}
