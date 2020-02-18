#include <cstdio>
#include <map>
using namespace std;

int n, m;
map<int, int> couple;
map<int, bool> ans;

int main() {
    scanf("%d", &n);
    int id1, id2, query, num = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id1, &id2);
        couple[id1] = id2;
        couple[id2] = id1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &query);
        if (ans.count(couple[query]) == 0) {
            ans[query] = true;
            num++;
        } else {
            ans[couple[query]] = false;
            ans[query] = false;
            num--;
        }
    }
    printf("%d\n", num);
    for (map<int, bool>::iterator it = ans.begin(); it != ans.end(); it++) {
        if (it->second == true) {
            printf("%05d", it->first);
            cnt++;
            if (cnt != num) {
                printf(" ");
            }
        }
    }
    return 0;
}
