#include <cstdio>
#include <queue>
using namespace std;

const int maxk = 1001, maxn = 21, maxTime = 540;
int n, m, k, q, t[maxk], ans[maxk] = {0};

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &t[i]);
    }
    queue<int> que[maxn];
    int time = 0, index = 0, query;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            que[j].push(++index);
            if (index == k) {
                break;
            }
        }
        if (index == k) {
            break;
        }
    }
    while (time != maxTime - 1) {
        time++;
        for (int i = 1; i <= n; i++) {
            if (que[i].size() > 0) {
                int front = que[i].front();
                if (t[front] > 0) {
                    t[front]--;
                    if (t[front] == 0) {
                        que[i].pop();
                        ans[front] = time;
                        if (index != k) {
                            que[i].push(++index);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (que[i].size() > 0) {
            int front = que[i].front();
            ans[front] = time + t[front];
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &query);
        if (ans[query] != 0) {
            printf("%02d:%02d\n", 8 + ans[query] / 60, ans[query] % 60);
        } else {
            printf("Sorry\n");
        }
    }
    return 0;
}
