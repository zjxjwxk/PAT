#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100000;

vector<int> node[maxn];

int n, min_count;
double p, r, min_price = 1e10;

void DFS(int root, double p) {
    if (node[root].size() == 0) {
        if (p == min_price) {
            min_count++;
        } else if (p < min_price) {
            min_price = p;
            min_count = 1;
        }
    } else {
        for (int i = 0; i < node[root].size(); i++) {
            DFS(node[root][i], p * (1 + r));
        }
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int child_num, child;
    for (int i = 0; i < n; i++) {
        scanf("%d", &child_num);
        if (child_num != 0) {
            for (int j = 0; j < child_num; j++) {
                scanf("%d", &child);
                node[i].push_back(child);
            }
        }
    }
    DFS(0, p);
    printf("%.4lf %d", min_price, min_count);
    return 0;
}
