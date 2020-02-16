#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int n, fathers[maxn], m[maxn] = {0}, estates[maxn] = {0}, areas[maxn] = {0};
bool flag[maxn] = {false};

struct Family {
    int ID = 0;
    int m = 0;
    double avg_sets = 0;
    double avg_area = 0;
} families[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        fathers[i] = i;
    }
}

int getFather(int i) {
    int j = i;
    while (i != fathers[i]) {
        i = fathers[i];
    }
    while (j != fathers[j]) {
        int k = j;
        j = fathers[j];
        fathers[j] = i;
    }
    return i;
}

void Union(int i, int j) {
    int father1 = getFather(i), father2 = getFather(j);
    if (father1 != father2) {
        if (father2 < father1) {
            swap(father1, father2);
        }
        fathers[father2] = father1;
        m[father1] += m[father2];
        m[father2] = 0;
        estates[father1] += estates[father2];
        areas[father1] += areas[father2];
    }
}

int cmp(Family f1, Family f2) {
    if (f1.avg_area != f2.avg_area) {
        return f1.avg_area > f2.avg_area;
    } else {
        return f1.ID < f2.ID;
    }
}

void addM(int ID) {
    if (flag[ID] == false) {
        m[getFather(ID)]++;
        flag[ID] = true;
    }
}

int main() {
    scanf("%d", &n);
    init();
    int ID, father, mother, k, child, estate, area, cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &ID, &father, &mother, &k);
        addM(ID);
        if (father != -1) {
            addM(father);
            Union(ID, father);
        }
        if (mother != -1) {
            addM(mother);
            Union(ID, mother);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            addM(child);
            Union(ID, child);
        }
        scanf("%d %d", &estate, &area);
        estates[getFather(ID)] += estate;
        areas[getFather(ID)] += area;
    }
    for (int i = 0; i < maxn; i++) {
        if (m[i] > 0) {
            cnt++;
            families[i].ID = i;
            families[i].m = m[i];
            families[i].avg_sets = 1.0 * estates[i] / m[i];
            families[i].avg_area = 1.0 * areas[i] / m[i];
        }
    }
    printf("%d\n", cnt);
    sort(families, families + maxn, cmp);
    for (int i = 0; i < maxn; i++) {
        if (families[i].m > 0) {
            printf("%04d %d %.3f %.3f\n", families[i].ID, families[i].m, families[i].avg_sets, families[i].avg_area);
        } else {
            break;
        }
    }
    return 0;
}
