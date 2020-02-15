#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int maxn = 20;
int n;

struct Node {
    int left;
    int right;
} node[maxn];

bool ifCBT(int root, int &last) {
    int count = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        if (temp == -1) {
            return count == n;
        } else {
            count++;
            last = temp;
            q.push(node[temp].left);
            q.push(node[temp].right);
        }
    }
}

int main() {
    int root;
    bool hash_table[maxn] = {false};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string left, right;
        cin >> left >> right;
        if (left[0] == '-') {
            node[i].left = -1;
        } else {
            node[i].left = stoi(left);
            hash_table[stoi(left)] = true;
        }
        if (right[0] == '-') {
            node[i].right = -1;
        } else {
            node[i].right = stoi(right);
            hash_table[stoi(right)] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (hash_table[i] == false) {
            root = i;
            break;
        }
    }
    int last = -1;
    bool if_CBT = ifCBT(root, last);
    if (if_CBT) {
        cout << "YES " << last;
    } else {
        cout << "NO " << root;
    }
    return 0;
}
