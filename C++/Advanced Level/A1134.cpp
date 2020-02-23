#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10000;
int n, m, k;
vector<int> edge[maxn];

int main() {
    scanf("%d %d", &n, &m);
    int v1, v2, num, cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        edge[v1].push_back(i);
        edge[v2].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &num);
        int v;
        bool flag[maxn] = {false}, ans = true;
        for (int j = 0; j < num; j++) {
            scanf("%d", &v);
            for (int t = 0; t < edge[v].size(); t++) {
                flag[edge[v][t]] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (flag[i] == false) {
                ans = false;
                break;
            }
        }
        if (ans == true) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
