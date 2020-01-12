// Solution on book
#include <cstdio>
#include <cstring>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char str[101];
        scanf("%s", str);
        int len = strlen(str);
        int num_p = 0, num_t = 0, other = 0;
        int loc_p = -1, loc_t = -1;
        for (int i = 0; i < len; i++) {
            if (str[i] == 'P') {
                num_p++;
                loc_p = i;
            } else if (str[i] == 'T') {
                num_t++;
                loc_t = i;
            } else if (str[i] != 'A') {
                other++;
            }
        }
        if ((num_p != 1) || (num_t != 1) || (other != 0) || (loc_t - loc_p <= 1)) {
            printf("NO\n");
            continue;
        }
        int x = loc_p, y = loc_t - loc_p - 1, z = len - loc_t - 1;
        if (z - x * (y - 1) == x) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

/*
// My solution
#include <cstdio>
#include <cstring>

int correct[9][2];
int count = 0;

bool is_correct(char str[], int len) {
    int a = 0, b = 0, c = 0;
    int i;
    for (i = 0; i < len - 2; i++) {
        if (str[i] == 'A') {
            a++;
        } else if (str[i] == 'P') {
            break;
        } else {
            return false;
        }
    }
    if (i == len - 2) {
        return false;
    }
    for (i = i + 1; i < len; i++) {
        if (str[i] == 'A') {
            b++;
        } else if (str[i] == 'T') {
            break;
        } else {
            return false;
        }
    }
    if (b == 0 || i == len) {
        return false;
    }
    for (i = i + 1; i < len; i++) {
        if (str[i] == 'A') {
            c++;
        } else {
            return false;
        }
    }
    if (b == 1 && a == c) {
        return true;
    } else {
        c -= (b - 1) * a;
        if (a == c) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    char str[20][101];
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++) {
        int len = strlen(str[i]);
        if (is_correct(str[i], len)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
*/
