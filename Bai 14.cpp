#include <stdio.h>

// Hàm đệ quy tính giá trị của U(n)
int U_dequy(int n) {
	if (n < 6) {
		return n;
	}
	return U_dequy(n - 5) + U_dequy(n - 4) + U_dequy(n - 3) + U_dequy(n - 2) + U_dequy(n - 1);
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Gia tri n phai la so nguyen duong.\n");
	}
	else {
		int result = U_dequy(n);
		printf("Gia tri cua U(%d) la: %d\n", n, result);
	}

	return 0;
}
