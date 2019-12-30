#include <cstdio>
#include <stdlib.h>

struct {
    char name[11];
    char id[11];
    int score;
} temp, max_stu, min_stu;

int main() {
    int n;
    scanf("%d", &n);
    max_stu.score = 0;
    min_stu.score = 100;
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", &temp.name, &temp.id, &temp.score);
        if (temp.score > max_stu.score) {
            max_stu = temp;
        }
        if (temp.score < min_stu.score) {
            min_stu = temp;
        }
    }
    printf("%s %s\n", max_stu.name, max_stu.id);
    printf("%s %s\n", min_stu.name, min_stu.id);
    return 0;
}
