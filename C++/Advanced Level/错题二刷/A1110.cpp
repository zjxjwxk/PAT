#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int maxn = 20;
int n;

struct Node {
    int left, right;
} nodes[maxn];

bool BFS(int root, int &last) {
    int cnt = 0;
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int index = que.front();
        que.pop();
        if (index == -1) {
            return cnt == n;
        }
        cnt++;
        last = index;
        que.push(nodes[index].left);
        que.push(nodes[index].right);
    }
}

int main() {
    bool flag[maxn] = {false};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char str1[3], str2[3];
        int left, right;
        scanf("%s %s", str1, str2);
        if (str1[0] != '-') {
            left = stoi(str1);
            nodes[i].left = left;
            flag[left] = true;
        } else {
            nodes[i].left = -1;
        }
        if (str2[0] != '-') {
            right = stoi(str2);
            nodes[i].right = right;
            flag[right] = true;
        } else {
            nodes[i].right = -1;
        }
    }
    int root, last = -1;
    for (int i = 0; i < n; i++) {
        if (flag[i] == false) {
            root = i;
            break;
        }
    }
    bool ifCBT = BFS(root, last);
    printf("%s %d", ifCBT ? "YES" : "NO", ifCBT ? last : root);
    return 0;
}
