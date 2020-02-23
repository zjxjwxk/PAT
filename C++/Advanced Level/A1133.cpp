#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100000;

struct Node {
    int address, data, next;
} nodes[maxn];

vector<int> ans;

int main() {
    int root, n, k, address;
    scanf("%d %d %d", &root, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        nodes[address].address = address;
        scanf("%d %d", &nodes[address].data, &nodes[address].next);
    }
    int cur = root;
    while (cur != -1) {
        if (nodes[cur].data < 0) {
            ans.push_back(cur);
        }
        cur = nodes[cur].next;
    }
    cur = root;
    while (cur != -1) {
        if (nodes[cur].data >= 0 && nodes[cur].data <= k) {
            ans.push_back(cur);
        }
        cur = nodes[cur].next;
    }
    cur = root;
    while (cur != -1) {
        if (nodes[cur].data > k) {
            ans.push_back(cur);
        }
        cur = nodes[cur].next;
    }
    for (int i = 0; i < ans.size(); i++) {
        printf("%05d %d ", nodes[ans[i]].address, nodes[ans[i]].data);
        if (i != ans.size() - 1) {
            printf("%05d\n", nodes[ans[i + 1]].address);
        } else {
            printf("-1");
        }
    }
    return 0;
}
