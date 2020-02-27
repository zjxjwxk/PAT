#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct School {
    string name;
    int tws, ns;
};

int cmp(School s1, School s2) {
    if (s1.tws != s2.tws) {
        return s1.tws > s2.tws;
    } else if (s1.ns != s2.ns) {
        return s1.ns < s2.ns;
    } else {
        return s1.name < s2.name;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    double score;
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for (int i = 0; i < n; i++) {
        string id, name;
        double score;
        cin >> id >> score >> name;
        for (int j = 0; j < name.length(); j++) {
            name[j] = tolower(name[j]);
        }
        if (id[0] == 'B') {
            score = score / 1.5;
        } else if (id[0] == 'T') {
            score = score * 1.5;
        }
        sum[name] += score;
        cnt[name]++;
    }
    vector<School> ans;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        ans.push_back(School{it->first, (int) sum[it->first], cnt[it->first]});
    }
    sort(ans.begin(), ans.end(), cmp);
    int rank = 1;
    printf("%d\n", ans.size());
    printf("1 %s %d %d\n", ans[0].name.c_str(), ans[0].tws, ans[0].ns);
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i].tws != ans[i - 1].tws) {
            rank = i + 1;
        }
        printf("%d %s %d %d\n", rank, ans[i].name.c_str(), ans[i].tws, ans[i].ns);
    }
    return 0;
}
