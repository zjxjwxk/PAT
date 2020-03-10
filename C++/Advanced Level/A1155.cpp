#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1001;
int n, nodes[maxn], ifMin = 1, ifMax = 1;
vector<int> path;

void printPath() {
    for (int i = 0; i < path.size(); i++) {
        printf("%d", path[i]);
        if (i != path.size() - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

void DFS(int root) {
    path.push_back(nodes[root]);
    if (root * 2 + 1 > n && root * 2 > n) {
        printPath();
        path.pop_back();
        return;
    }
    if (root * 2 + 1 <= n) {
        DFS(root * 2 + 1);
    }
    DFS(root * 2);
    path.pop_back();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nodes[i]);
    }
    DFS(1);
    for (int i = 2; i <= n; i++) {
        if (nodes[i] > nodes[i / 2]) {
            ifMax = 0;
        } else if (nodes[i] < nodes[i / 2]) {
            ifMin = 0;
        }
    }
    if (ifMax == 1) {
        printf("Max Heap\n");
    } else if (ifMin == 1) {
        printf("Min Heap\n");
    } else {
        printf("Not Heap\n");
    }
    return 0;
}
