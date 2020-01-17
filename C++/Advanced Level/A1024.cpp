#include <cstdio>
#include <cstring>

struct bign {
    int d[200];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char n[]) {
    bign a;
    a.len = strlen(n);
    for (int i = 0; i < a.len; i++) {
        a.d[i] = n[a.len - 1 - i] - '0';
    }
    return a;
}

bign reverse(bign a) {
    bign b;
    b.len = a.len;
    for (int i = 0; i < a.len; i++) {
        b.d[i] = a.d[a.len - 1 - i];
    }
    return b;
}

bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        c.d[c.len++] = (a.d[i] + b.d[i] + carry) % 10;
        carry = (a.d[i] + b.d[i] + carry) / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bool if_palindromic(bign a) {
    for (int i = 0; i < a.len / 2; i++) {
        if (a.d[i] != a.d[a.len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void show_bign(bign a) {
    for (int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
        if (i == 0) {
            printf("\n");
        }
    }
}

int main() {
    char n[11];
    int k;
    scanf("%s %d", n, &k);
    bign a = change(n);
    if (a.len == 1) {
        printf("%d\n%d", a.d[0], 0);
    } else if (if_palindromic(a)) {
        show_bign(a);
        printf("%d", 0);
    } else {
        bign c;
        int i;
        for (i = 1; i <= k; i++) {
            c = add(a, reverse(a));
            if (if_palindromic(c)) {
                break;
            }
            a = c;
        }
        show_bign(c);
        if (i > k) {
            printf("%d", k);
        } else {
            printf("%d", i);
        }
    }
    return 0;
}
