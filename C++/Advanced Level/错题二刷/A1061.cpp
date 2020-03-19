#include <cstdio>
#include <cstring>

const int maxn = 61;

int main() {
    char str[4][maxn];
    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for (int i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }
    int i, j, len1 = strlen(str[0]), len2 = strlen(str[1]), len3 = strlen(str[2]), len4 = strlen(str[3]);
    for (i = 0; i < len1 && i < len2; i++) {
        if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
            printf("%s ", week[str[0][i] - 'A']);
            break;
        }
    }
    for (i++; i < len1 && i < len2; i++) {
        if (str[0][i] == str[1][i]) {
            if (str[0][i] >= '0' && str[0][i] <= '9') {
                printf("%02d:", str[0][i] - '0');
                break;
            } else if (str[0][i] >= 'A' && str[0][i] <= 'N') {
                printf("%02d:", str[0][i] - 'A' + 10);
                break;
            }
        }
    }
    for (int i = 0; i < len3 && i < len4; i++) {
        if (str[2][i] == str[3][i] && (str[2][i] >= 'a' && str[2][i] <= 'z' || str[2][i] >= 'A' && str[2][i] <= 'Z')) {
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
