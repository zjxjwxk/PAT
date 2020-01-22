#include <cstdio>
#include <algorithm>
using namespace std;

struct Fraction {
    long long numerator;
    long long denominator;
};

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
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
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduction(result);
}

Fraction difference(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduction(result);
}

Fraction product(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduction(result);
}

Fraction quotient(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return reduction(result);
}

void print_fraction(Fraction f) {
    f = reduction(f);
    if (f.numerator < 0) {
        printf("(");
    }
    if (f.denominator == 1) {
        printf("%lld", f.numerator);
    } else if (abs(f.numerator) > f.denominator) {
        printf("%lld %lld/%lld", f.numerator / f.denominator, abs(f.numerator) % f.denominator, f.denominator);
    } else {
        printf("%lld/%lld", f.numerator, f.denominator);
    }
    if (f.numerator < 0) {
        printf(")");
    }
}

int main() {
    Fraction f1, f2;
    scanf("%lld/%lld %lld/%lld", &f1.numerator, &f1.denominator, &f2.numerator, &f2.denominator);
    print_fraction(f1);printf(" + ");print_fraction(f2);printf(" = ");print_fraction(add(f1, f2));printf("\n");
    print_fraction(f1);printf(" - ");print_fraction(f2);printf(" = ");print_fraction(difference(f1, f2));printf("\n");
    print_fraction(f1);printf(" * ");print_fraction(f2);printf(" = ");print_fraction(product(f1, f2));printf("\n");
    print_fraction(f1);printf(" / ");print_fraction(f2);printf(" = ");
    if (f2.numerator == 0) {
        printf("Inf");
    } else {
        print_fraction(quotient(f1,f2));
    }
    return 0;
}
