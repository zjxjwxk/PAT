#include <cstdio>
#include <set>
using namespace std;

const int maxn = 26 * 26 * 26 * 10;
set<int> course[maxn];

int getID(char name[]) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    int n, k, index, num;
    scanf("%d %d", &n, &k);
    char name[5];
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &index, &num);
        for (int j = 0; j < num; j++) {
            scanf("%s", name);
            course[getID(name)].insert(index);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getID(name);
        printf("%s %d", name, course[id].size());
        for (auto it = course[id].begin(); it != course[id].end(); it++) {
            printf("% d", *it);
        }
        printf("\n");
    }
    return 0;
}
