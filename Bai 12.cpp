#include <stdio.h>

// Khai báo trước các hàm
int x_dequy(int n);
int y_dequy(int n);

// Hàm đệ quy tính số hạng thứ n của dãy x
int x_dequy(int n) {
	if (n == 0) {
		return 1;
	}
	return x_dequy(n - 1) + y_dequy(n - 1);
}

// Hàm đệ quy tính số hạng thứ n của dãy y
int y_dequy(int n) {
	if (n == 0) {
		return 0;
	}
	return 3 * x_dequy(n - 1) + 2 * y_dequy(n - 1);
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	printf("So hang thu %d cua day x la: %d\n", n, x_dequy(n));
	printf("So hang thu %d cua day y la: %d\n", n, y_dequy(n));

	return 0;
}
