#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[9];
    int grade;
} stu[100000];

int c;

int cmp(Student stu1, Student stu2) {
    int temp;
    if (c == 2) {
        if ((temp = strcmp(stu1.name, stu2.name)) != 0) {
            return temp < 0;
        }
    } else if (c == 3) {
        if (stu1.grade != stu2.grade) {
            return stu1.grade < stu2.grade;
        }
    }
    return stu1.id < stu2.id;
}

int main() {
    int n;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    return 0;
}
