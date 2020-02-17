#include <cstdio>

const int maxn = 10010;
int n, q, father[maxn], cnt[maxn] = {0};
bool vis[maxn] = {false};

void init() {
    for (int i = 1; i <= maxn; i++) {
        father[i] = i;
    }
}

int findFather(int i) {
    int j = i;
    while (i != father[i]) {
        i = father[i];
    }
    while (j != father[j]) {
        int k = j;
        j = father[j];
        father[k] = i;
    }
    return i;
}

void Union(int i, int j) {
    int father1 = findFather(i), father2 = findFather(j);
    if (father1 != father2) {
        father[father2] = father1;
    }
}

int main() {
    scanf("%d", &n);
    init();
    int k, id, temp, tree_num = 0, bird_num = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &k, &id);
        vis[id] = true;
        for (int j = 1; j < k; j++) {
            scanf("%d", &temp);
            Union(id, temp);
            vis[temp] = true;
        }
    }
    for (int i = 1; i <= maxn; i++) {
        if (vis[i] == true) {
            cnt[findFather(i)]++;
        }
    }
    for (int i = 1; i <= maxn; i++) {
        if (cnt[i] > 0) {
            tree_num++;
            bird_num += cnt[i];
        }
    }
    printf("%d %d\n", tree_num, bird_num);
    scanf("%d", &q);
    int id1, id2;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &id1, &id2);
        if (findFather(id1) == findFather(id2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
