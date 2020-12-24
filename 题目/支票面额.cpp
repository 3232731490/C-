//ÍøÉÏÕÒµÄ´ğ°¸


#include<iostream>
using namespace std;
int main(void) {
	int f, y, n;
	int flag = 0;
	scanf_s("%d", &n);
	for (y = 0; y < 100; ++y) {
		for (f = 0; f < 100; ++f) {
			if (n + 2 * f + 200 * y == y + 100 * f) {
				printf("%d.%d\n", y, f);
				flag = 1;
			}
		}
	}
	if (!flag)
		printf("No Solution\n");
	return 0;
}
