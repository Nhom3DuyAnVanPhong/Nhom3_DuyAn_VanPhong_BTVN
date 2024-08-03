#include <stdio.h>
#include <stdlib.h>

// Hàm đệ quy tính giá trị của U(n)
int tinhU_deQuy(int n, int* U) {
    if (n < 6) {
        return n;
    }

    if (U[n] != -1) {
        return U[n];
    }

    // Tính giá trị U(n) bằng cách gọi đệ quy
    U[n] = tinhU_deQuy(n - 5, U) + tinhU_deQuy(n - 4, U) + tinhU_deQuy(n - 3, U) + tinhU_deQuy(n - 2, U) + tinhU_deQuy(n - 1, U);
    return U[n];
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Vui long nhap n >= 1.\n");
        return 1;
    }

    // Khởi tạo mảng để lưu trữ các giá trị đã tính
    int* U = (int*)malloc((n + 1) * sizeof(int));
    if (U == NULL) {
        printf("Loi cap phat bo nho.\n");
        return 1;
    }

    // Gán giá trị -1 để đánh dấu các giá trị chưa được tính
    for (int i = 0; i <= n; i++) {
        U[i] = -1;
    }

    // Tính giá trị U(n) bằng đệ quy
    printf("Gia tri U(%d) (de quy): %d\n", n, tinhU_deQuy(n, U));

    // Giải phóng bộ nhớ đã cấp phát
    free(U);
    return 0;
}
