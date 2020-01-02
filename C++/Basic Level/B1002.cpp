#include <cstdio>

int main() {
    char* a[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char n[110];
    char* ans[4];
    scanf("%s", n);
    int sum = 0;
    int i = 0;
    while (n[i] != '\0') {
        sum += n[i] - '0';
        i++;
    }
    i = 0;
    while (sum != 0) {
        ans[i++] = a[sum % 10];
        sum /= 10;
    }
    ans[i] = '\0';
    for (int j = i - 1; j >= 0; j--) {
        printf("%s", ans[j]);
        if (j != 0) {
            printf(" ");
        }
    }
    return 0;
}
