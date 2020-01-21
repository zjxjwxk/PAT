#include <cstdio>
#include <queue>
using namespace std;

struct Mice {
    int weight;
    int rank;
} mices[1000];

int main() {
    int np, ng;
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; i++) {
        scanf("%d", &mices[i].weight);
    }
    int order;
    queue<int> q;
    for (int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    while (q.size() > 1) {
        int count, num = q.size();
        int group = num % ng == 0 ? (num / ng) : (num / ng + 1);
        while (num > 0) {
            count = num < ng ? num : ng;
            num -= count;
            int max_weight = -1;
            int max_id;
            while (count--) {
                int id = q.front();
                q.pop();
                mices[id].rank = group + 1;
                if (mices[id].weight > max_weight) {
                    max_weight = mices[id].weight;
                    max_id = id;
                }
            }
            q.push(max_id);
        }
    }
    mices[q.front()].rank = 1;
    for (int i = 0; i < np; i++) {
        printf("%d", mices[i].rank);
        if (i != np - 1) {
            printf(" ");
        }
    }
    return 0;
}
