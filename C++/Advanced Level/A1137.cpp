#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Stu {
    string id;
    int prog, mid, final, total;
};

int p, m, n;
map<string, Stu> scores;
vector<Stu> ans;

int cmp(Stu s1, Stu s2) {
    if (s1.total != s2.total) {
        return s1.total > s2.total;
    } else {
        return s1.id < s2.id;
    }
}

int main() {
    scanf("%d %d %d", &p, &m, &n);
    string id;
    int score;
    for (int i = 0; i < p; i++) {
        cin >> id >> score;
        if (score >= 200) {
            scores[id] = Stu{id, score, -1, -1, 0};
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> id >> score;
        if (scores.count(id) != 0) {
            scores[id].mid = score;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> id >> score;
        if (scores.count(id) != 0) {
            scores[id].final = score;
        }
    }
    for (auto it = scores.begin(); it != scores.end(); it++) {
        double total;
        if (it->second.mid < it->second.final) {
            total = it->second.final;
        } else {
            total = it->second.mid * 0.4 + it->second.final * 0.6;
        }
        if ((int) (total + 0.5) >= 60) {
            ans.push_back(Stu{it->first, it->second.prog, it->second.mid, it->second.final, (int) (total + 0.5)});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].prog, ans[i].mid, ans[i].final, ans[i].total);
    }
    return 0;
}
