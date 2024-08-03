#include <stdio.h>

// Khai báo trước hàm đệ quy
int Y_dequy(int n);

// Hàm chính
int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n < 1) {
		printf("Gia tri n phai la so nguyen duong.\n");
	}
	else {
		// Tính giá trị của Y(n) bằng phương pháp đệ quy đơn giản
		int result = Y_dequy(n);
		printf("Gia tri cua Y(%d) theo phuong phap de quy la: %d\n", n, result);
	}

	return 0;
}

// Định nghĩa hàm đệ quy tính giá trị của Y(n)
int Y_dequy(int n) {
	if (n == 1) {
		return 1; // Y1 = 1
	}
	else if (n == 2) {
		return 2; // Y2 = 2
	}
	else if (n == 3) {
		return 3; // Y3 = 3
	}
	// Nếu n >= 4, sử dụng công thức đệ quy
	return Y_dequy(n - 1) + 2 * Y_dequy(n - 2) + 3 * Y_dequy(n - 3);
}
