#include <cstdio>

int main() {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    char mr[3], mg[3], mb[3];
    for (int i = 1; i >= 0; i--) {
        mr[i] = r % 13 < 10 ? r % 13 + '0' : r % 13 - 10 + 'A';
        mg[i] = g % 13 < 10 ? g % 13 + '0' : g % 13 - 10 + 'A';
        mb[i] = b % 13 < 10 ? b % 13 + '0' : b % 13 - 10 + 'A';
        r /= 13;
        g /= 13;
        b /= 13;
    }
    mr[2] = '\0';
    mg[2] = '\0';
    mb[2] = '\0';
    printf("#%s%s%s", mr, mg, mb);
    return 0;
}
