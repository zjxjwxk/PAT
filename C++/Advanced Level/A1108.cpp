#include <cstdio>
#include <cstring>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    char str1[50], str2[50];
    double temp, sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", str1);
        sscanf(str1, "%lf", &temp);
        sprintf(str2, "%.2f", temp);
        bool flag = false;
        for (int i = 0; i < strlen(str1); i++) {
            if (str1[i] != str2[i]) {
                flag = true;
            }
        }
        if (flag || temp > 1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", str1);
        } else {
            sum += temp;
            count++;
        }
    }
    if (count == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (count == 1) {
        printf("The average of 1 number is %.2f", sum);
    } else {
        printf("The average of %d numbers is %.2f", count, sum / count);
    }
    return 0;
}
