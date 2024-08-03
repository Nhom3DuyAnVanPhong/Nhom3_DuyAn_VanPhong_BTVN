#include <stdio.h>

// Hàm đệ quy tính giá trị của x(n)
int x_dequy(int n) {
	if (n == 0) {
		return 1; // x0 = 1
	}
	else if (n == 1) {
		return 2; // x1 = 2
	}
	else {
		int sum = 0;
		// Tính tổng của n*x0 + (n-1)*x1 + ... + x(n-1)
		for (int i = 0; i < n; i++) {
			sum += (n - i) * x_dequy(i);
		}
		return sum;
	}
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Gia tri n phai la so nguyen duong.\n");
	}
	else {
		int result = x_dequy(n);
		printf("Gia tri cua x(%d) la: %d\n", n, result);
	}

	return 0;
}
