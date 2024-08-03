#include <stdio.h>

// Hàm đệ quy tính giá trị của An
int tinhAn(int n, int* A) {
    if (n == 1) return 1; // A1 = 1

    // Nếu giá trị chưa được tính, tính giá trị
    if (A[n] == -1) {
        if (n % 2 == 0) {
            // n là số chẵn: A_{2n} = n + A_n + 2
            A[n] = (n / 2) + tinhAn(n / 2, A) + 2;
        }
        else {
            // n là số lẻ: A_{2n+1} = n^2 + A_n * A_{n+1} + 1
            int n2 = (n - 1) / 2;
            A[n] = (n2 * n2) + tinhAn(n2, A) * tinhAn(n2 + 1, A) + 1;
        }
    }
    return A[n];
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Vui long nhap n >= 1.\n");
        return 1;
    }

    // Khởi tạo mảng để lưu trữ các giá trị của dãy A
    int A[100];
    for (int i = 0; i < 100; i++) {
        A[i] = -1; // Đánh dấu các giá trị chưa được tính
    }

    // Tính giá trị của An
    printf("Gia tri A(%d) (de quy): %d\n", n, tinhAn(n, A));

    return 0;
}
