#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
int quota[100];

struct Student {
    int id;
    int ge;
    int gi;
    int rank;
    int sum;
    int choice[6];
} stu[40000];

struct School {
    int admission[40000];
    int admit_num = 0;
} schools[100];

int cmp(Student s1, Student s2) {
    if (s1.sum != s2.sum) {
        return s1.sum > s2.sum;
    } else {
        return s1.ge > s2.ge;
    }
}

int cmpID(int a, int b) {
    return stu[a].id < stu[b].id;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < n; i++) {
        stu[i].id = i;
        scanf("%d %d ", &stu[i].ge, &stu[i].gi);
        stu[i].sum = stu[i].ge + stu[i].gi;
        for (int j = 0; j < k; j++) {
            scanf("%d", &stu[i].choice[j]);
        }
    }
    sort(stu, stu + n, cmp);
    stu[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if (stu[i].sum != stu[i - 1].sum) {
            stu[i].rank = i + 1;
        } else if (stu[i].ge != stu[i - 1].ge) {
            stu[i].rank = i + 1;
        } else {
            stu[i].rank = stu[i - 1].rank;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int choice = stu[i].choice[j];
            int num = schools[choice].admit_num;
            int last = schools[choice].admission[num - 1];
            if (num < quota[choice] || (num > 0 && stu[i].rank == stu[last].rank)) {
                schools[choice].admission[schools[choice].admit_num++] = i;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) { 
        sort(schools[i].admission, schools[i].admission + schools[i].admit_num, cmpID);
        for (int j = 0; j < schools[i].admit_num; j++) {
            printf("%d", stu[schools[i].admission[j]].id);
            if (j != schools[i].admit_num - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
