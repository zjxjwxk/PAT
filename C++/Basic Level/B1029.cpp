#include <cstdio>

int main() {
    char ori[81];
    char out[81];
    scanf("%s", ori);
    scanf("%s", out);
    bool hash_table[128] = {false};
    int i = 0, j = 0;
    while (out[j] != '\0') {
        char c1 = ori[i], c2 = out[j];
        if (c1 >= 'a' && c1 <= 'z') {
            c1 -= 32;
        }
        if (c2 >= 'a' && c2 <= 'z') {
            c2 -= 32;
        }
        if (c1 != c2) {
            if (hash_table[c1] == false) {
                printf("%c", c1);
                hash_table[c1] = true;
            }
        } else {
            j++;
        }
        i++;
    }
    while (ori[i] != '\0') {
        char c = ori[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        if (hash_table[c] == false) {
            printf("%c", c);
            hash_table[c] == true;
        }
        i++;
    }
    return 0;
}
