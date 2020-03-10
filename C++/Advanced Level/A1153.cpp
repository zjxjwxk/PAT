#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int n, m;

struct Node {
    string str;
    int value;
} nodes[maxn];

int cmp(const Node &n1, const Node &n2) {
    if (n1.value != n2.value) {
        return n1.value > n2.value;
    } else {
        return n1.str < n2.str;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].str >> nodes[i].value;
    }
    int type;
    string s;
    for (int i = 1; i <= m; i++) {
        cin >> type >> s;
        printf("Case %d: %d %s\n", i, type, s.c_str());
        vector<Node> ans;
        int cnt = 0, sum = 0;
        if (type == 1) {
            for (int j = 0; j < n; j++) {
                if (nodes[j].str[0] == s[0]) {
                    ans.push_back(nodes[j]);
                }
            }
        } else if (type == 2) {
            for (int j = 0; j < n; j++) {
                if (nodes[j].str.substr(1, 3) == s) {
                    cnt++;
                    sum += nodes[j].value;
                }
            }
            if (cnt != 0) {
                printf("%d %d\n", cnt, sum);
            }
        } else {
            unordered_map<string, int> siteMap;
            for (int j = 0; j < n; j++) {
                if (nodes[j].str.substr(4, 6) == s) {
                    siteMap[nodes[j].str.substr(1, 3)]++;
                }
            }
            for (auto it : siteMap) {
                ans.push_back({it.first, it.second});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int j = 0; j < ans.size(); j++) {
            printf("%s %d\n", ans[j].str.c_str(), ans[j].value);
        }
        if (((type == 1 || type == 3) && ans.size() == 0) || (type == 2 && cnt == 0)) {
            printf("NA\n");
        }
    }
    return 0;
}
