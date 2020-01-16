#include <cstdio>
#include <cstring>

struct bign {
    int d[1000];
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
    }
    return a;
}

bign divide(bign a, int b, int& r) {
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        c.d[i] = r / b;
        r = r % b;
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

int main() {
    bign a, c;
    int b, r = 0;
    char str[1000];
    scanf("%s %d", str, &b);
    a = change(str);
    c = divide(a, b, r);
    for (int i = c.len - 1; i >= 0; i--) {
        printf("%d", c.d[i]);
    }
    printf(" %d", r);
    return 0;
}
