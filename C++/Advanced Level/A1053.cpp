#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100;
int n, m, s;

struct Node {
    int weight;
    vector<int> child;
} node[maxn];

vector<vector<int> > ans;
vector<int> temp;

void DFS(int root, int sum) {
    sum += node[root].weight;
    if (sum > s) {
        return;
    }
    temp.push_back(node[root].weight);
    if (node[root].child.size() == 0 && sum == s) {
        ans.push_back(temp);
    }
    for (int i = 0; i < node[root].child.size(); i++) {
        DFS(node[root].child[i], sum);
    }
    temp.pop_back();
}

int cmp(int n1, int n2) {
    return node[n1].weight > node[n2].weight;
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &node[i].weight);
    }
    for (int i = 0; i < m; i++) {
        int parent, num, child;
        scanf("%d %d", &parent, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &child);
            node[parent].child.push_back(child);
        }
        sort(node[parent].child.begin(), node[parent].child.end(), cmp);
    }
    DFS(0, 0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d", ans[i][j]);
            if (j != ans[i].size() - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
