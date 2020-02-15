#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10000;

struct Stu {
    char name[9];
    int height;
} stu[maxn];

int cmp(Stu stu1, Stu stu2) {
    if (stu1.height != stu2.height) {
        return stu1.height > stu2.height;
    } else {
        return strcmp(stu1.name, stu2.name) < 0;
    }
}

void printRow(char names[][9], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", names[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char name[9];
    int height;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", stu[i].name, &stu[i].height);
    }
    sort(stu, stu + n, cmp);
    double temp = 1.0 * n / k;
    int m = temp - 0.5 < n / k ? n / k : n / k + 1;
    int last = n % m + m, num;
    for (int i = 0; i < n; i += num) {
        num = i == 0 ? last : m;
        int index = num / 2, flag = -1;
        char names[num][9];
        for (int j = 0; j < num; j++) {
            strcpy(names[index], stu[i + j].name);
            index += flag * (j + 1);
            flag = -flag;
        }
        printRow(names, num);
    }
    return 0;
}
