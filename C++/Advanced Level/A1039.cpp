#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 26 * 26 * 26 * 10 + 1;
vector<int> choice[maxn];

int getID(char name[]) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id * 26 + name[i] - 'A';
    }
    id = id * 10 + name[3] - '0';
    return id;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int course, num;
        scanf("%d %d", &course, &num);
        for (int j = 0; j < num; j++) {
            char name[4];
            scanf("%s", name);
            choice[getID(name)].push_back(course);
        }
    }
    for (int i = 0; i < n; i++) {
        char name[4];
        scanf("%s", name);
        int id = getID(name);
        sort(choice[id].begin(), choice[id].end());
        printf("%s %d", name, choice[id].size());
        for (int j = 0; j < choice[id].size(); j++) {
            printf(" %d", choice[id][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
map<string, vector<int> > ans;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int course, num;
        scanf("%d %d", &course, &num);
        vector<int> stu;
        string name;
        name.resize(4);
        for (int j = 0; j < num; j++) {
            scanf("%s", &name[0]);
            ans[name].push_back(course);
        }
    }
    map<string, vector<int> >::iterator it;
    for (it = ans.begin(); it != ans.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    for (int i = 0; i < n; i++) {
        string name;
        name.resize(4);
        scanf("%s", &name[0]);
        if (ans.count(name) != 0) {
            printf("%s %d", name.c_str(), ans[name].size());
            for (int i = 0; i < ans[name].size(); i++) {
                printf(" %d", ans[name][i]);
            }
        } else {
            printf("%s 0", name.c_str());
        }
        printf("\n");
    }
    return 0;
}
*/
