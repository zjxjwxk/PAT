#include <cstdio>
#include <algorithm>
using namespace std;

struct Num {
    long long a, b;
} temp, ans;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void simplify(Num &n) {
    if (n.b < 0) {
        n.a = -n.a;
        n.b = -n.b;
    }
    if (n.a == 0) {
        n.b = 1;
    } else {
        int d = gcd(abs(n.a), abs(n.b));
        n.a /= d;
        n.b /= d;
    }
}

Num add(Num &n1, Num &n2) {
    Num ret;
    ret.a = n1.a * n2.b + n2.a * n1.b;
    ret.b = n1.b * n2.b;
    simplify(ret);
    return ret;
}

int main() {
    int n;
    scanf("%d %lld/%lld", &n, &ans.a, &ans.b);
    simplify(ans);
    for (int i = 1; i < n; i++) {
        scanf("%lld/%lld", &temp.a, &temp.b);
        ans = add(ans, temp);
    }
    if (ans.b == 1) {
        printf("%lld", ans.a);
    } else if (ans.a > ans.b) {
        printf("%lld %lld/%lld", ans.a / ans.b, ans.a % ans.b, ans.b);
    } else {
        printf("%lld/%lld", ans.a, ans.b);
    }
    return 0;
}
