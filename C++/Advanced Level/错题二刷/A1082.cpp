#include <cstdio>

char nums[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char unit[3][5] = {"Qian", "Bai", "Shi"};

void printNum(int num, bool preFlag) {
    int temp = 1000;
    bool flag = false, ifPrint = false;
    if (preFlag == true) {
        printf(" ");
    }
    for (int i = 0; i < 4; i++) {
        if (num / temp != 0) {
            if (i > 0) {
                if (ifPrint == true && flag == false) {
                    printf(" ling ");
                } else if (ifPrint == false && preFlag == true) {
                    printf("ling ");
                }
            }
            if (flag == true) {
                printf(" ");
            }
            printf("%s", nums[num / temp]);
            if (i != 3) {
                printf(" %s", unit[i]);
            }
            flag = true;
            ifPrint = true;
        } else {
            flag = false;
        }
        num %= temp;
        temp /= 10;
    }
}

int main() {
    int n, a, b, c;
    scanf("%d", &n);
    if (n == 0) {
        printf("ling");
        return 0;
    }
    if (n < 0) {
        printf("Fu ");
        n = -n;
    }
    a = n / 100000000;
    if (a != 0) {
        printf("%s Yi", nums[a]);
    }
    b = n % 100000000 / 10000;
    if (b != 0) {
        printNum(b, a != 0);
        printf(" Wan");
    }
    c = n % 10000;
    if (c != 0) {
        printNum(c, a != 0 || b != 0);
    }
    return 0;
}
