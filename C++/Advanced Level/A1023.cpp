#include <cstdio>
#include <cstring>

int hash_table[10] = {0};

struct bign {
    int d[21];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - 1 - i] - '0';
        hash_table[a.d[i]]++;
    }
    return a;
}

bign multi(bign a, int b) {
    bign c;
    int temp = 0;
    for (int i = 0; i < a.len; i++) {
        temp += a.d[i] * b;
        c.d[c.len++] = temp % 10;
        temp /= 10;
    }
    while (temp != 0) {
        c.d[c.len++] = temp % 10;
        temp /= 10;
    }
    return c;
}

int main() {
    char str[20];
    scanf("%s", str);
    bign a, c;
    a = change(str);
    c = multi(a, 2);
    bool flag = true;
    for (int i = 0; i < c.len; i++) {
        if (--hash_table[c.d[i]] < 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = c.len - 1; i >= 0; i--) {
        printf("%d", c.d[i]);
    }
    return 0;
}
