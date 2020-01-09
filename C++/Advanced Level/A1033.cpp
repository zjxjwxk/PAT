#include <cstdio>
#include <algorithm>
using namespace std;

struct Station {
    double p;
    double d;
} s[500];

int cmpByD(Station s1, Station s2) {
    return s1.d < s2.d;
}

int main() {
    double c_max, d, d_avg;
    int n;
    scanf("%lf %lf %lf %d", &c_max, &d, &d_avg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &s[i].p, &s[i].d);
    }
    sort(s, s + n, cmpByD);
    if (s[0].d != 0) {
        printf("The maximum travel distance = 0.00");
    } else {
        double total = 0;
        int i = 0;
        double d_now = 0, c_now = 0;
        while (d_now < d) {
            if (d - d_now <= c_now * d_avg) {
                d_now = d;
                break;
            } else {
                if (i == n - 1) {
                    if (c_max * d_avg >= d - d_now) {
                        total += (d - d_now) / d_avg * s[i].p;
                        d_now = d;
                    } else {
                        d_now += c_max * d_avg;
                    }
                    break;
                } else {
                    if (c_max * d_avg < (s[i + 1].d - d_now)) {
                        d_now += c_max * d_avg;
                        break;
                    } else {
                        double min_price = s[i].p, sec_price;
                        int min_index = i, sec_index;
                        if (s[i + 1].p > min_price) {
                            sec_price = s[i + 1].p;
                            sec_index = i + 1;
                        } else {
                            sec_price = s[i].p;
                            sec_index = i;
                        }
                        for (int j = i + 1; j < n; j++) {
                            if (s[j].d - d_now <= c_max * d_avg) {
                                if (s[j].p < min_price) {
                                    min_price = s[j].p;
                                    min_index = j;
                                    break;
                                } else if (s[j].p < sec_price) {
                                    sec_price = s[j].p;
                                    sec_index = j;
                                }
                            }
                        }
                        if (min_index == i) {
                            if (c_max * d_avg >= d - d_now) {
                                total += (d - d_now) / d_avg * s[i].p;
                                d_now = d;
                                break;
                            }
                            total += (c_max - c_now) * s[i].p;
                            c_now = c_max;
                            c_now -= (s[sec_index].d - d_now) / d_avg;
                            d_now = s[sec_index].d;
                            i = sec_index;
                        } else {
                            double c_need = (s[min_index].d - d_now) / d_avg;
                            if (c_now < c_need) {
                                total += (c_need - c_now) * s[i].p;
                                c_now = c_need;
                            }
                            c_now -= c_need;
                            d_now = s[min_index].d;
                            i = min_index;
                        }
                    }
                }
            }
        }
        if (d_now == d) {
            printf("%.2lf", total);
        } else {
            printf("The maximum travel distance = %.2lf", d_now);
        }
    }
    return 0;
}
