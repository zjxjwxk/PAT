#include <cstdio>
#include <map>
#include <vector>
using namespace std;

const int maxn = 1000;
map<int, vector<int> > map1;

int main() {
    int n, m, v1, v2, num;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v1, &v2);
        map1[v1].push_back(v2);
        map1[v2].push_back(v1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        int v[maxn], flag = 1, a[100000] = {0};
        for (int j = 0; j < num; j++) {
            scanf("%d", &v[j]);
            a[v[j]] = 1;
        }
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < map1[v[j]].size(); k++) {
                if (a[map1[v[j]][k]] == 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
