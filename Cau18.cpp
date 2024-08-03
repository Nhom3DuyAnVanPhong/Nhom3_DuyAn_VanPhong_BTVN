#include <stdio.h>

// Hàm đệ quy tính giá trị của xn
int tinhXn(int n, int* x) {
    if (n == 0) return x[0];
    if (n == 1) return x[1];

    // Tính tổng của x0, x1, ..., x_(n-1)
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += x[i];
    }

    x[n] = n * x[0] + (n - 1) * x[1] + tong;
    return x[n];
}

int main() {
    int n;
    printf("Nhap so nguyen duong n (n >= 0): ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Vui long nhap n >= 0.\n");
        return 1;
    }

    // Khởi tạo mảng để lưu trữ các giá trị của dãy x
    int x[100] = { 1, 2 }; // Khởi tạo giá trị ban đầu

    // Tính giá trị của xn
    printf("Gia tri x(%d) (de quy): %d\n", n, tinhXn(n, x));

    return 0;
}
