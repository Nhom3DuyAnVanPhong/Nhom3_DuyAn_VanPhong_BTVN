#include <stdio.h>

// Hàm đệ quy tính giá trị phần tử thứ n của cấp số nhân
double Un_dequy(int n, double a, double q) {
	if (n == 1) {
		return a;
	}
	return q * Un_dequy(n - 1, a, q);
}

int main() {
	int n;
	double a, q;

	printf("Nhap gia tri a (hang dau): ");
	scanf_s("%lf", &a);
	printf("Nhap gia tri q (cong boi): ");
	scanf_s("%lf", &q);
	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	double result = Un_dequy(n, a, q);
	printf("Gia tri phan tu thu %d cua cap so nhan la: %.2lf\n", n, result);

	return 0;
}
