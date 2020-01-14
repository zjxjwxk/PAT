#include <cstdio>
#include <stdlib.h>

struct Fraction {
    long long numerator;
    long long denominator;
};

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Fraction reduction(Fraction f) {
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    if (f.numerator == 0) {
        f.denominator = 1;
    } else {
        int d = gcd(abs(f.numerator), abs(f.denominator));
        f.numerator /= d;
        f.denominator /= d;
    }
    return f;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction ret;
    ret.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    ret.denominator = f1.denominator * f2.denominator;
    return reduction(ret);
}

void printResult(Fraction f) {
    f = reduction(f);
    if (f.denominator == 1) {
        printf("%lld", f.numerator);
    } else if (abs(f.numerator) > f.denominator) {
        printf("%lld %lld/%lld", f.numerator / f.denominator, abs(f.numerator) % f.denominator, f.denominator);
    } else {
        printf("%lld/%lld", f.numerator, f.denominator);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Fraction ans;
    ans.numerator = 0, ans.denominator = 1;-+
    for (int i = 0; i < n; i++) {
        Fraction temp;
        long long numerator, denominator;
        scanf("%lld/%lld", &temp.numerator, &temp.denominator);
        ans = add(ans, temp);
    }
    printResult(ans);
    return 0;
}
