#include <cstdio>

int main() {
	int n, id, score;
	const int maxn = 100000;
	int school[maxn] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &id, &score);
		school[id] += score;
	}
	int k = 1; int max = -1;
	for (int i = 1; i <= n; i++) {
		if (school[i] > max) {
			max = school[i];
			k = i;
		}
	}
	printf("%d %d", k, max);
	return 0;
}
