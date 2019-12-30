#include <cstdio>

struct Person {
    char name[11];
    char gender;
    char ID[11];
    int grade;
} temp, girl, boy;

int main() {
    int n;
    scanf("%d", &n);
    girl.grade = 0;
    girl.gender = '0';
    boy.grade = 100;
    boy.gender = '0';
    for (int i = 0; i < n; i++) {
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.ID, &temp.grade);
        if (temp.gender == 'F' && temp.grade > girl.grade) {
            girl = temp;
        }
        if (temp.gender == 'M' && temp.grade < boy.grade) {
            boy = temp;
        }
    }
    if (girl.gender == '0') {
        printf("Absent\n");
    } else {
        printf("%s %s\n", girl.name, girl.ID);
    }
    if (boy.gender == '0') {
        printf("Absent\n");
    } else {
        printf("%s %s\n", boy.name, boy.ID);
    }
    if (girl.gender == '0' || boy.gender == '0') {
        printf("NA");
    } else {
        printf("%d", girl.grade - boy.grade);
    }
    return 0;
}
