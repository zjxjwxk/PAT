#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int maxn = 10000;
int n, m, k;
vector<int> friends[maxn];
unordered_map<int, bool> relation;

struct Pair {
    int first, second;
};

int cmp(Pair p1, Pair p2) {
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        string id1, id2;
        cin >> id1 >> id2;
        if (id1.length() == id2.length()) {
            friends[abs(stoi(id1))].push_back(abs(stoi(id2)));
            friends[abs(stoi(id2))].push_back(abs(stoi(id1)));
        }
        relation[abs(stoi(id1)) * maxn + abs(stoi(id2))] = relation[abs(stoi(id2)) * maxn + abs(stoi(id1))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        vector<Pair> ans;
        int a, b, c, d;
        scanf("%d %d", &a, &b);
        for (int u = 0; u < friends[abs(a)].size(); u++) {
            for (int v = 0; v < friends[abs(b)].size(); v++) {
                c = friends[abs(a)][u], d = friends[abs(b)][v];
                if (c == abs(b) || d == abs(a)) {
                    continue;
                }
                if (relation[c * maxn + d] == true) {
                    ans.push_back(Pair{c, d});
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int j = 0; j < ans.size(); j++) {
            printf("%04d %04d\n", ans[j].first, ans[j].second);
        }
    }
    return 0;
}
