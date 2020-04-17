#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10000;

struct Person {
    char name[9];
    int height;
} people[maxn];

int n, k;

int cmp(Person p1, Person p2) {
    if (p1.height != p2.height) {
        return p1.height > p2.height;
    } else {
        return strcmp(p1.name, p2.name) < 0;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", people[i].name, &people[i].height);
    }
    sort(people, people + n, cmp);
    int rowNum = n / k, cnt = 0;
    for (int i = 0; i < k; i++) {
        int m, row[maxn];
        if (i == 0) {
            m = rowNum + n % rowNum;
        } else {
            m = rowNum; 
        }
        int k = m / 2, j = k - 1;
        while (j >= 0 || k <= m - 1) {
            if (k <= m - 1) {
                row[k++] = cnt++;
            }
            if (j >= 0) {
                row[j--] = cnt++;
            }
        }
        for (int j = 0; j < m; j++) {
            printf("%s", people[row[j]].name);
            if (j != m - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
