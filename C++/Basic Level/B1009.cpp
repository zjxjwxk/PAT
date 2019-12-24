#include <cstdio>

int main() {
    char sentence[90][90];
    int i = 0;
    while (scanf("%s", sentence[i]) != EOF) {
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
        printf("%s", sentence[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    return 0;
}
