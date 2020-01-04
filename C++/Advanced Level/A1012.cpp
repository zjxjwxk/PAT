#include <cstdio>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int grade[4];
} stu[2000];

int now;
int Rank[1000000][4] = {0};
int c[4] = {'A', 'C', 'M', 'E'};

int cmp(Student stu1, Student stu2) {
    return stu1.grade[now] > stu2.grade[now];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0 + 0.5;
    }
    for (now = 0; now < 4; now++) {
        sort(stu, stu + n, cmp);
        Rank[stu[0].id][now] = 1;
        for (int i = 1; i < n; i++) {
            if (stu[i].grade[now] == stu[i - 1].grade[now]) {
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
            } else {
                Rank[stu[i].id][now] = i + 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        if (Rank[id][0] == 0) {
            printf("N/A\n");
        } else {
            int k = 0;
            for (int j = 1; j < 4; j++) {
                if (Rank[id][j] < Rank[id][k]) {
                    k = j;
                }
            }
            printf("%d %c\n", Rank[id][k], c[k]);
        }
    }
    return 0;
}
