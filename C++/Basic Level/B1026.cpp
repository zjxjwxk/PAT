#include <cstdio>

int main() {
    int C1, C2;
    double CLK_TCK = 100;
    scanf("%d %d", &C1, &C2);
    int time = (int) ((C2 - C1) / CLK_TCK + 0.5);
    int hour, min, sec;
    printf("%02d:%02d:%02d", time / 3600, time % 3600 / 60, time % 60);
    return 0;
}
