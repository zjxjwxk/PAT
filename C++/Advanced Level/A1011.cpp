#include <cstdio>

int main() {
    double max = 0;
    int index = 0;
    double sum = 1;
    double odd;
    char results[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &odd);
            if (odd > max) {
                max = odd;
                index = j;
            }
        }
        printf("%c ", results[index]);
        sum *= max;
        max = 0;
    }
    printf("%.2lf", (sum * 0.65 - 1) * 2);
    return 0;
}
