#include <cstdio>

int main() {
    char* week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char str[4][61];
    for (int i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }
    int count = 1;
    int i = 0;
    while (str[0][i] != '\0' && str[1][i] != '\0') {
        if (str[0][i] == str[1][i]) {
            if (count == 1) {
                if (str[0][i] >= 'A' && str[0][i] <= 'G') {
                    printf("%s ", week[str[0][i] - 'A']);
                    count++;
                }
            } else if (count == 2) {
                if (str[0][i] >= '0' && str[0][i] <= '9') {
                    printf("0%c:", str[0][i]);
                    break;
                } else if (str[0][i] >= 'A' && str[0][i] <= 'N') {
                    printf("%d:", str[0][i] - 'A' + 10);
                    break;
                }
            }
        }
        i++;
    }
    i = 0;
    while (str[2][i] != '\0' && str[3][i] != '\0') {
        if (str[2][i] == str[3][i] && (str[2][i] >= 'A' && str[2][i] <= 'Z' || str[2][i] >= 'a' && str[2][i] <= 'z')) {
            printf("%02d", i);
            break;
        }
        i++;
    }
    return 0;
}
