#include <cstdio>
#include <cstring>

struct Student {
    char name[11];
    char id[11];
    int grade = -1;
} stu[101];

int main() {
    int n, grade1, grade2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[11];
        char id[11];
        int grade;
        scanf("%s %s %d", name, id, &grade);
        strcpy(stu[grade].name, name);
        strcpy(stu[grade].id, id);
        stu[grade].grade = grade;
    }
    scanf("%d %d", &grade1, &grade2);
    bool flag = false;
    for (int i = grade2; i >= grade1; i--) {
        if (stu[i].grade != -1) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }
    if (!flag) {
        printf("NONE");
    }
    return 0;
}
