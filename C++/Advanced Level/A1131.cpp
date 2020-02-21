#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int maxn = 10000, INF = 1000000000;
int n, k, total = 0, start, end1, minCnt = INF, minTransfer = INF;
bool vis[maxn] = {false};
map<int, int> line;
vector<int> temp, ans, v[maxn];

int transferCnt(vector<int> path) {
    int preLine = 0, cnt = -1;
    for (int i = 0; i < path.size() - 1; i++) {
        if (line[path[i] * maxn + path[i + 1]] != preLine) {
            cnt++;
        }
        preLine = line[path[i] * maxn + path[i + 1]];
    }
    return cnt;
}

void DFS(int root, int cnt) {
    if (root == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(temp) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(temp);
        ans = temp;
    }
    if (root == end1) {
        return;
    }
    for (int i = 0; i < v[root].size(); i++) {
        if (vis[v[root][i]] == false) {
            vis[v[root][i]] = true;
            temp.push_back(v[root][i]);
            DFS(v[root][i], cnt + 1);
            vis[v[root][i]] = false;
            temp.pop_back();
        }
    }
}

int main() {
    scanf("%d", &n);
    int num, pre, cur;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &num, &pre);
        for (int j = 1; j < num; j++) {
            scanf("%d", &cur);
            v[pre].push_back(cur);
            v[cur].push_back(pre);
            line[pre * maxn + cur] = line[cur * maxn + pre] = i;
            pre = cur;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &start, &end1);
        minCnt = minTransfer = INF;
        temp.clear();
        temp.push_back(start);
        vis[start] = true;
        DFS(start, 0);
        vis[start] = false;
        printf("%d\n", minCnt);
        int preLine = line[start * maxn + ans[1]], preTransfer = start;
        for (int j = 1; j <= minCnt; j++) {
            if (j == minCnt || line[ans[j] * maxn + ans[j + 1]] != preLine) {
                printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, ans[j]);
                preLine = line[ans[j] * maxn + ans[j + 1]];
                preTransfer = ans[j];
            }
        }
    }
    return 0;
}
