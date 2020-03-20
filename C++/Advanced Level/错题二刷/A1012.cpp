#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2000;

struct Stu {
    int id;
    int score[4] = {0};
} stus[maxn];

int n, m, q, ranks[1000000][4] = {0}, index;
char ch[4] = {'A', 'C', 'M', 'E'};

int cmp(Stu s1, Stu s2) {
    return s1.score[index] > s2.score[index];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stus[i].id);
        for (int j = 1; j <= 3; j++) {
            scanf("%d", &stus[i].score[j]);
            stus[i].score[0] += stus[i].score[j];
        }
    }
    for (index = 0; index < 4; index++) {
        sort(stus, stus + n, cmp);
        ranks[stus[0].id][index] = 1;
        for (int i = 1; i < n; i++) {
            if (stus[i].score[index] == stus[i - 1].score[index]) {
                ranks[stus[i].id][index] = ranks[stus[i - 1].id][index];
            } else {
                ranks[stus[i].id][index] = i + 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &q);
        if (ranks[q][0] == 0) {
            printf("N/A\n");
        } else {
            int minRank = 2000, minIndex;
            for (int j = 0; j < 4; j++) {
                if (ranks[q][j] < minRank) {
                    minRank = ranks[q][j];
                    minIndex = j;
                }
            }
            printf("%d %c\n", minRank, ch[minIndex]);
        }
    }
    return 0;
}
