#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 40000, maxs = 100, maxk = 5;
int n, m, k;

struct Stu {
    int id, ge, gi, gf, rank, choices[maxk];
} stus[maxn];

int quota[maxs];
vector<int> schs[maxs];

int cmp(Stu s1, Stu s2) {
    if (s1.gf != s2.gf) {
        return s1.gf > s2.gf;
    } else {
        return s1.ge > s2.ge;
    }
}

int cmpById(int a, int b) {
    return stus[a].id < stus[b].id;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &stus[i].ge, &stus[i].gi);
        for (int j = 0; j < k; j++) {
            scanf("%d", &stus[i].choices[j]);
        }
        stus[i].gf = stus[i].ge + stus[i].gi;
        stus[i].id = i;
    }
    sort(stus, stus + n, cmp);
    stus[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if (stus[i].gf == stus[i - 1].gf && stus[i].gi == stus[i - 1].gi) {
            stus[i].rank = stus[i - 1].rank;
        } else {
            stus[i].rank = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int choice = stus[i].choices[j];
            if (schs[choice].size() < quota[choice] || stus[i].rank == stus[schs[choice][schs[choice].size() - 1]].rank) {
                schs[choice].push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        sort(schs[i].begin(), schs[i].end(), cmpById);
        for (int j = 0; j < schs[i].size(); j++) {
            printf("%d", stus[schs[i][j]].id);
            if (j != schs[i].size() - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
