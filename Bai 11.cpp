#include <stdio.h>

// Hàm đệ quy tính số Fibonacci thứ n
long long Fibonacci(int n) {
	if (n <= 2) {
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Hàm đệ quy tìm số Fibonacci lớn nhất nhỏ hơn n
long long TimFibonacciLonNhatNhoHonN_Dequy(int n, int i) {
	long long fib = Fibonacci(i);
	if (fib >= n) {
		return Fibonacci(i - 1);
	}
	return TimFibonacciLonNhatNhoHonN_Dequy(n, i + 1);
}
// Hàm khử đệ quy tìm số Fibonacci lớn nhất nhỏ hơn n
long long TimFibonacciLonNhatNhoHonN_KhuDequy(int n) {
	long long a = 1, b = 1, c = 1;
	if (n <= 1) {
		return -1; // Không có số Fibonacci nhỏ hơn 1
	}

	while (b < n) {
		c = a + b;
		if (c >= n) {
			return b;
		}
		a = b;
		b = c;
	}

	return b;
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);
	printf("Phuong phap co de quy \n");

	if (n <= 1) {
		printf("Khong co so Fibonacci nho hon %d.\n", n);
	}
	else {
		long long fib = TimFibonacciLonNhatNhoHonN_Dequy(n, 1);
		printf("So Fibonacci lon nhat nho hon %d la: %lld\n", n, fib);
	}

	printf("Phuong phap khu de quy \n");

	if (n <= 1) {
		printf("Khong co so Fibonacci nho hon %d.\n", n);
	}
	else {
		long long fib = TimFibonacciLonNhatNhoHonN_KhuDequy(n);
		printf("So Fibonacci lon nhat nho hon %d la: %lld\n", n, fib);
	}

	return 0;
}
