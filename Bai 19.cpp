#include <stdio.h>

// Khai báo hàm đệ quy tính giá trị của A(n)
int A_dequy(int n);

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n < 1) {
		printf("Gia tri n phai la so nguyen duong.\n");
	}
	else {
		int result = A_dequy(n);
		printf("Gia tri cua A(%d) la: %d\n", n, result);
	}

	return 0;
}

// Hàm đệ quy tính giá trị của A(n)
int A_dequy(int n) {
	if (n == 1) {
		return 1; // A1 = 1
	}
	else if (n % 2 == 0) { // Nếu n là số chẵn
		int k = n / 2;
		return k + A_dequy(k) + 2;
	}
	else { // Nếu n là số lẻ
		int k = (n - 1) / 2;
		return k * k + A_dequy(k) * A_dequy(k + 1) + 1;
	}
}
