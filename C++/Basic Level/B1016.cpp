#include <cstdio>

int main() {
    long long A, B, DA, DB, PA = 0, PB = 0;
    scanf("%lld %lld %lld %lld", &A, &DA, &B, &DB);
    while (A != 0 || B != 0) {
        if (A != 0 && A % 10 == DA) {
            if (PA == 0) {
                PA = DA;
            } else{
                PA = PA * 10 + DA;
            }
        }
        if (B != 0 && B % 10 == DB) {
            if (PB == 0) {
                PB = DB;
            } else{
                PB = PB * 10 + DB;
            }
        }
        A /= 10;
        B /= 10;
    }
    printf("%lld", PA + PB);
    return 0;
}
