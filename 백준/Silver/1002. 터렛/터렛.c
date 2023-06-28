#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int x1, y1, x2, y2, r1, r2;
	int T, cnt = 0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		cnt = location(x1, y1, r1, x2, y2, r2);
		printf("%d\n", cnt);
	}

	return 0;
}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt((double)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
int location(int x1, int y1, int r1, int x2, int y2, int r2) {
	if (x1 == x2 && y1 == y2 && r1 == r2)
		return -1;
	double dist = distance(x1, y1, x2, y2);
	if (dist == r1 + r2)
		return 1;
	if (dist < r1 + r2 && dist > (r1 > r2 ? r1 - r2 : r2 - r1))
		return 2;
	if (dist > r1 + r2 || dist < (r1 > r2 ? r1 - r2 : r2 - r1))
		return 0;
	return 1;
}