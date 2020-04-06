#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1000;

int main() {
    int np, ng, index, w[maxn], rank[maxn];
    scanf("%d %d", &np, &ng);
    queue<int> que;
    for (int i = 0; i < np; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < np; i++) {
        scanf("%d", &index);
        que.push(index);
    }
    int len = que.size(), nowRank;
    while (len > 1) {
        if (len % ng == 0) {
            nowRank = len / ng + 1;
        } else {
            nowRank = len / ng + 2;
        }
        for (int i = 0; i < len; i += ng) {
            int maxW = -1, maxI = -1;
            for (int j = i; j < i + ng && j < len; j++) {
                int tempI = que.front();
                if (w[tempI] > maxW) {
                    maxW = w[tempI];
                    maxI = tempI;
                }
                rank[tempI] = nowRank;
                que.pop();
            }
            que.push(maxI);
        }
        len = que.size();
    }
    rank[que.front()] = 1;
    for (int i = 0; i < np; i++) {
        printf("%d", rank[i]);
        if (i != np - 1) {
            printf(" ");
        }
    }
    return 0;
}
