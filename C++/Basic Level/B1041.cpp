#include <cstdio>

struct stu {
    char id[17];
    int seat;
} stu[1010];

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char id[16];
        int seat1;
        int seat2;
        scanf("%s %d %d", &id, &seat1, &seat2);
        for (int i = 0; i < 17; i++) {
            stu[seat1].id[i] = id[i];
        }
        stu[seat1].seat = seat2;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int seat1;
        scanf("%d", &seat1);
        printf("%s %d\n", stu[seat1].id, stu[seat1].seat);
    }
    return 0;
}
