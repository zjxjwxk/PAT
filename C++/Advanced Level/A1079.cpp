#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 100000;

struct Node {
    int level;
    vector<int> child;
    int product_num;
} node[maxn];

int n, child_num, child_id;
double p, r, ans = 0;

void BFS(int id) {
    queue<int> q;
    q.push(id);
    node[id].level = 0;
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        vector<int> childs = node[parent].child;
        if (childs.size() == 0) {
            ans += node[parent].product_num * p * pow(1.0 + r / 100, node[parent].level);
        } else {
            for (int i = 0; i < childs.size(); i++) {
                node[childs[i]].level = node[parent].level + 1;
                q.push(childs[i]);
            }
        }
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &child_num);
        if (child_num == 0) {
            scanf("%d", &node[i].product_num);
        } else {
            for (int j = 0; j < child_num; j++) {
                scanf("%d", &child_id);
                node[i].child.push_back(child_id);
            }
        }
    }
    BFS(0);
    printf("%.1lf", ans);
    return 0;
}
