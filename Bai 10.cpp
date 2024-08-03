#include <stdio.h>

// Hàm đệ quy tính số Fibonacci thứ n
long long Fibonacci(int n) {
	if (n <= 2) {
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Hàm xuất các số Fibonacci trong đoạn [m, n]
void XuatFibonacciTrongDoan(int m, int n) {
	int i = 1;
	long long fib;

	printf("Cac so Fibonacci trong doan [%d, %d] la: ", m, n);
	while (1) {
		fib = Fibonacci(i);
		if (fib > n) {
			break;
		}
		if (fib >= m) {
			printf("%lld ", fib);
		}
		i++;
	}
	printf("\n");
}

int main() {
	int m, n;

	printf("Nhap gia tri m: ");
	scanf_s("%d", &m);
	printf("Nhap gia tri n: ");
	scanf_s("%d", &n);

	if (m > n) {
		printf("Gia tri m phai nho hon hoac bang n.\n");
	}
	else {
		XuatFibonacciTrongDoan(m, n);
	}

	return 0;
}
