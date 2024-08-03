#include <stdio.h>
#include <math.h>

// Hàm đệ quy tính S1(n)
double Tinh_S1_Dequy(int n) {
	if (n == 1) {
		return 1.0 / (1 * 2 * 3);
	}
	return 1.0 / (n * (n + 1) * (n + 2)) + Tinh_S1_Dequy(n - 1);
}

// Hàm đệ quy tính S2(n)
int Tinh_S2_Dequy(int n) {
	if (n == 1) {
		return 1 * 1;
	}
	return n * n + Tinh_S2_Dequy(n - 1);
}

// Hàm đệ quy tính S3(n)
int Tinh_S3_Dequy(int n) {
	if (n == 1) {
		return 1;
	}
	return (n * (n + 1)) / 2 + Tinh_S3_Dequy(n - 1);
}

// Hàm tính giai thừa (đệ quy)
long long Giaithua(int k) {
	if (k == 0 || k == 1) {
		return 1;
	}
	return k * Giaithua(k - 1);
}

// Hàm đệ quy tính S4(n)
double Tinh_S4_Dequy(int n) {
	if (n == 1) {
		return -1.0 * (1 + 2) / Giaithua(2);
	}
	// Sử dụng (double) để ép kiểu cho tham số truyền vào pow
	return pow(-1.0, (double)n) * ((2 * n - 1) + 2 * n) / (double)Giaithua(2 * n) + Tinh_S4_Dequy(n - 1);
}

// Hàm chính
int main() {
	int luaChon, n;

	while (1) {
		printf("\nMenu:\n");
		printf("1. Tinh S1(n) = 1/(1.2.3) + 1/(2.3.4) + ... + 1/(n.(n + 1).(n + 2))\n");
		printf("2. Tinh S2(n) = 1^2 + 2^2 + ... + n^2\n");
		printf("3. Tinh S3(n) = 1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + 2 + 3 + ... + n)\n");
		printf("4. Tinh S4(n) = -(1 + 2)/2! + (3 + 4)/4! - (5 + 6)/6! + ... + (−1)^n ((2n − 1) + (2n))/(2n)!\n");
		printf("5. Thoat\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &luaChon);

		if (luaChon == 5) {
			printf("Thoat chuong trinh.\n");
			break;
		}

		printf("Nhap gia tri n: ");
		scanf_s("%d", &n);

		switch (luaChon) {
		case 1:
			printf("Tinh_S1_Dequy(%d) = %lf\n", n, Tinh_S1_Dequy(n));
			break;
		case 2:
			printf("Tinh_S2_Dequy(%d) = %d\n", n, Tinh_S2_Dequy(n));
			break;
		case 3:
			printf("Tinh_S3_Dequy(%d) = %d\n", n, Tinh_S3_Dequy(n));
			break;
		case 4:
			printf("Tinh_S4_Dequy(%d) = %lf\n", n, Tinh_S4_Dequy(n));
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	}

	return 0;
}
