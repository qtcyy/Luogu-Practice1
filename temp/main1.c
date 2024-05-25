#include<stdio.h>

int main() {
	int i, j, k, n, a[15][15];

	scanf("%d",&n);
	k = 1;

	for (i = 0; i < n / 2; i++){
		for (j = i; j < n - 1 - i; j++) {
			a[i][j] = k++;
		}	
		for (j = i; j < n - 1 - i; j++) {
			a[j][n - 1 - i] = k++;
		}
		for (j = n - i - 1; j > i; j--) {
			a[n - i - 1][j] = k++;
		}
		for (j = n - i - 1; j > i; j--) {
			a[j][i] = k++;
		}
	}

	if (n % 2 == 1) {
		a[n / 2][n / 2] = k;
	}

	for (i = 0; i <= n - 1; i++) {
		for (j = 0; j <= n - 1; j++) {
			if (j == n - 1) {
				printf("%d\n", a[i][j]);
			}
			else {
				printf("%d ", a[i][j]);
			}
		}
	}
		
	return 0;
}