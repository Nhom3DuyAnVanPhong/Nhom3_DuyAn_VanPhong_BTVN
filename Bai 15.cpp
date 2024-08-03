#include <stdio.h>

int An_dequy(int n);
// Hàm đệ quy tính tổng của các giá trị từ A1 đến A(n-1)
int TongAn(int n) {
	if (n == 1) {
		return 1; // A1 = 1
	}
	return TongAn(n - 1) + An_dequy(n - 1);
}

// Hàm đệ quy tính giá trị của A(n)
int An_dequy(int n) {
	if (n == 1) {
		return 1; // A1 = 1
	}
	return n * TongAn(n);
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n < 1) {
		printf("Gia tri n phai la so nguyen duong.\n");
	}
	else {
		int result = An_dequy(n);
		printf("Gia tri cua A(%d) la: %d\n", n, result);
	}

	return 0;
}
