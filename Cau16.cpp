#include <stdio.h>

#define MAX_N 100 // Giới hạn kích thước mảng

// Hàm đệ quy với lưu trữ kết quả đã tính
int tinhYn(int n, int* Y) {
    if (n == 1) return Y[0] = 1;
    if (n == 2) return Y[1] = 2;
    if (n == 3) return Y[2] = 3;

    // Nếu chưa tính giá trị của Yn, tính giá trị và lưu vào mảng
    if (Y[n - 1] == -1) {
        Y[n - 1] = tinhYn(n - 1, Y) + 2 * tinhYn(n - 2, Y) + 3 * tinhYn(n - 3, Y);
    }
    return Y[n - 1];
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Vui long nhap n >= 1.\n");
        return 1;
    }

    // Khởi tạo mảng để lưu trữ các giá trị của dãy Y
    int Y[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        Y[i] = -1; // Đánh dấu các giá trị chưa được tính
    }

    printf("Gia tri Y(%d) (de quy voi luu tru): %d\n", n, tinhYn(n, Y));

    return 0;
}
