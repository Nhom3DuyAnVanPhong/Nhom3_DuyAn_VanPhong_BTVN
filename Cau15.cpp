#include <stdio.h>

#define MAX_N 100 // Giới hạn kích thước mảng

// Hàm đệ quy tính tổng từ A1 đến An-1
int tinhTong(int n, int* A) {
    if (n == 1) {
        return A[0]; // A1 = 1
    }
    return tinhTong(n - 1, A) + A[n - 1];
}

// Hàm đệ quy tính giá trị của An
int tinhAn(int n, int* A) {
    if (n == 1) {
        A[0] = 1; // A1 = 1
        return A[0];
    }

    // Tính giá trị của An bằng cách gọi đệ quy
    int tong = tinhTong(n - 1, A);
    A[n - 1] = n * tong;
    return A[n - 1];
}

int main() {
    int n;
    printf("Nhap so nguyen duong n (n <= %d): ", MAX_N);
    scanf_s("%d", &n);

    if (n < 1 || n > MAX_N) {
        printf("Vui long nhap n >= 1 va n <= %d.\n", MAX_N);
        return 1;
    }

    // Khởi tạo mảng để lưu trữ các giá trị của dãy A
    int A[MAX_N] = { 0 }; // Sử dụng mảng tĩnh

    // Tính giá trị của An
    printf("Gia tri A(%d) (de quy): %d\n", n, tinhAn(n, A));

    return 0;
}
