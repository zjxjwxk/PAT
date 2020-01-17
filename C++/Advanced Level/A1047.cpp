#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 2501;
vector<string> stu[maxn];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        string name;
        name.resize(4);
        scanf("%s", &name[0]);
        int num;
        scanf("%d", &num);
        int course;
        for (int j = 0; j < num; j++) {
            scanf("%d", &course);
            stu[course].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, stu[i].size());
        sort(stu[i].begin(), stu[i].end());
        for (int j = 0; j < stu[i].size(); j++) {
            printf("%s\n", stu[i][j].c_str());
        }
    }
    return 0;
}

/*
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 40000;
const int maxc = 2501;
char stu[maxn][5];
vector<int> course_stu[maxc];

int cmp(int a, int b) {
    return strcmp(stu[a], stu[b]) < 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int num, course;
        scanf("%s %d", stu[i], &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &course);
            course_stu[course].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course_stu[i].size());
        sort(course_stu[i].begin(), course_stu[i].end(), cmp);
        for (int j = 0; j < course_stu[i].size(); j++) {
            printf("%s\n", stu[course_stu[i][j]]);
        }
    }
    return 0;
}
*/
