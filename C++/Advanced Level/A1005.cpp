#include <cstdio>

int main() {
    char* eng[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char n[102];
    int ans[4];
    scanf("%s", n);
    int i = 0, sum = 0;
    while (n[i] != '\0') {
        sum += n[i++] - '0';
    }
    i = 0;
    do {
        ans[i++] = sum % 10;
        sum /= 10;
    } while (sum != 0);
    for (int j = i - 1; j >= 0; j--) {
        printf("%s", eng[ans[j]]);
        if (j != 0) {
            printf(" ");
        }
    }
    return 0;
}
