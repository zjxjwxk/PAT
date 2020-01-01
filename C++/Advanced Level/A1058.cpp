#include <cstdio>

const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
    long long g1, s1, k1, g2, s2, k2;
    long long m1, m2, ans;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
    m1 = g1 * Galleon + s1 * Sickle + k1;
    m2 = g2 * Galleon + s2 * Sickle + k2;
    ans = m1 + m2;
    printf("%lld.%lld.%lld", ans / Galleon, ans % Galleon / Sickle, ans % Sickle);
    return 0;
}
