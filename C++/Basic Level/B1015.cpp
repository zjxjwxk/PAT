#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Person {
    char id[9];
    int virtue;
    int talent;
    int type;
    int total;
} people[100000];

int cmp(Person p1, Person p2) {
    if (p1.type != p2.type) {
        return p1.type > p2.type;
    } else if (p1.total != p2.total) {
        return p1.total > p2.total;
    } else if (p1.virtue != p2.virtue) {
        return p1.virtue > p2.virtue;
    } else {
        return atoi(p1.id) < atoi(p2.id);
    }
}

int main() {
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    int m = n;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", people[i].id, &people[i].virtue, &people[i].talent);
        people[i].total = people[i].virtue + people[i].talent;
        if (people[i].virtue < l || people[i].talent < l) {
            people[i].type = 0;
            m--;
        } else if (people[i].virtue >= h && people[i].talent >= h) {
            people[i].type = 4;
        } else if (people[i].virtue >= h && people[i].talent < h) {
            people[i].type = 3;
        } else if (people[i].virtue < h && people[i].talent < h && people[i].virtue >= people[i].talent) {
            people[i].type = 2;
        } else {
            people[i].type = 1;
        }
    }
    sort(people, people + n, cmp);
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%s %d %d\n", people[i].id, people[i].virtue, people[i].talent);
    }
    return 0;
}
