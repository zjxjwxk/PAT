#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1001;
int n, m, k, degree[maxn] = {0};
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        degree[v2]++;
    }
    scanf("%d", &k);
    bool flag = false;
    for (int i = 0; i < k; i++) {
        int temp_degree[maxn], v[maxn];
        for (int j = 1; j <= n; j++) {
            temp_degree[j] = degree[j];
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        for (int j = 0; j < n - 1; j++) {
            if (temp_degree[v[j]] != 0) {
                if (flag == false) {
                    flag = true;
                } else {
                    printf(" ");
                }
                printf("%d", i);
                break;
            } else {
                for (int t = 0; t < G[v[j]].size(); t++) {
                    temp_degree[G[v[j]][t]]--;
                }
            }
        }
    }
    return 0;
}
