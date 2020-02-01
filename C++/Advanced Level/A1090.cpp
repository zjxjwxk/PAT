#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100000;

vector<int> node[maxn];
int n, num = 0;
double p, r, max_p;

void DFS(int root, double p) {
    if (node[root].size() == 0) {
        if (p == max_p) {
            num++;
        } else if (p > max_p) {
            max_p = p;
            num = 1;
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
    int id, root;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (id == -1) {
            root = i;
        } else {
            node[id].push_back(i);
        }
    }
    DFS(root, p);
    printf("%.2lf %d", max_p, num);
    return 0;
}
