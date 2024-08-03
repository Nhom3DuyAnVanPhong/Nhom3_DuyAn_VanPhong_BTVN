#include <stdio.h>

// Hàm đệ quy tính giá trị của X(n)
int X_dequy(int n) {
	if (n == 1) {
		return 1; // X1 = 1
	}
	else if (n == 2) {
		return 1; // X2 = 1
	}
	else if (n >= 3) {
		// Xn = X(n-1) + (n-1) * X(n-2)
		return X_dequy(n - 1) + (n - 1) * X_dequy(n - 2);
	}
	return 0; // Trường hợp mặc định, không nên xảy ra
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n < 1) {
		printf("Gia tri n phai la so nguyen duong.\n");
	}
	else {
		int result = X_dequy(n);
		printf("Gia tri cua X(%d) la: %d\n", n, result);
	}

	return 0;
}
