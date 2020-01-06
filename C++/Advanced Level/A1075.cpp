#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int p[6];
int n, k, m;

struct User {
    int id;
    int score[6];
    int total = 0;
    int perfect_num = 0;
    bool pass = false;
} users[10001];

int cmp(User u1, User u2) {
    if (u1.total != u2.total) {
        return u1.total > u2.total;
    } else if (u1.perfect_num != u2.perfect_num) {
        return u1.perfect_num > u2.perfect_num;
    } else {
        return u1.id < u2.id;
    }
}

void printUser(int i) {
    printf(" %05d %d", users[i].id, users[i].total);
    for (int j = 1; j <= k; j++) {
        if (users[i].score[j] == -1) {
            printf(" -");
        } else {
            printf(" %d", users[i].score[j]);
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        users[i].id = i;
        memset(users[i].score, -1, sizeof(users[i].score));
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < m; i++) {
        int id;
        int p_id;
        int score;
        scanf("%d %d %d", &id, &p_id, &score);
        if (score != -1) {
            users[id].pass = true;
        }
        if (score == -1 && users[id].score[p_id] == -1) {
            users[id].score[p_id] = 0;
        }
        if (score == p[p_id] && users[id].score[p_id] < p[p_id]) {
            users[id].perfect_num++;
        }
        if (score > users[id].score[p_id]) {
            users[id].score[p_id] = score;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (users[i].score[j] != -1) {
                users[i].total += users[i].score[j];
            }
        }
    }
    sort(users + 1, users + n + 1, cmp);
    int rank = 1;
    printf("%d", rank);
    printUser(1);
    for (int i = 2; i <= n; i++) {
        if (users[i].pass) {
            if (users[i].total != users[i - 1].total) {
                rank = i;
            }
            printf("%d", rank);
            printUser(i);
        }
    }
    return 0;
}
