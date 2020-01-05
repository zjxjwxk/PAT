#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person {
    char name[9];
    int age;
    int worth;
} p[100000];

int cmp(Person p1, Person p2) {
    if (p1.worth != p2.worth) {
        return p1.worth > p2.worth;
    } else if (p1.age != p2.age) {
        return p1.age < p2.age;
    } else {
        return strcmp(p1.name, p2.name) < 0;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < k; i++) {
        int m, amin, amax, count = 0;
        scanf("%d %d %d", &m, &amin, &amax);
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            if (p[j].age >= amin && p[j].age <= amax) {
                printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
                count++;
                if (count == m) {
                    break;
                }
            }
        }
        if (count == 0) {
            printf("None\n");
        }
    }
    return 0;
}
