#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    char str[50];
    double total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int len = strlen(str), index = -1;
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (str[i] == '.') {
                if (i < len - 3 || index != -1) {
                    flag = false;
                    break;
                }
                index = i;
            } else if ((str[i] < '0' || str[i] > '9') && !(i == 0 && str[i] == '-')) {
                flag = false;
            }
        }
        if (!flag) {
            printf("ERROR: %s is not a legal number\n", str);
        } else {
            double num = stod(str);
            if (num < -1000 || num > 1000) {
                printf("ERROR: %s is not a legal number\n", str);
            } else {
                cnt++;
                total += num;
            }
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (cnt == 1) {
        printf("The average of 1 number is %.2f", total / cnt);
    } else {
        printf("The average of %d numbers is %.2f", cnt, total / cnt);
    }
    return 0;
}
