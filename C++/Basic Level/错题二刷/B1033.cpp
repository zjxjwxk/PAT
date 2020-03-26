#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100001;

int main() {
    int hash_table[256] = {0};
    char wrong[257], input[maxn];
    cin.getline(wrong, 257);
    int len = strlen(wrong);
    for (int i = 0; i < len; i++) {
        if (wrong[i] >= 'A' && wrong[i] <= 'Z') {
            wrong[i] = wrong[i] - 'A' + 'a';
        }
        hash_table[wrong[i]] = 1;
    }
    cin.getline(input, maxn);
    len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            int low = input[i] - 'A' + 'a';
            if (hash_table[low] == 0 && hash_table['+'] == 0) {
                printf("%c", input[i]);
            }
        } else if (hash_table[input[i]] == 0) {
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}
