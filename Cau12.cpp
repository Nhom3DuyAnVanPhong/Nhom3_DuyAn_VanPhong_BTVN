#include <stdio.h>

// Ham tinh so hang thu n cua day x va y bang phuong phap khu de quy
void tinhDay(int n, int* x_n, int* y_n) {
    if (n == 0) {
        *x_n = 1;
        *y_n = 0;
        return;
    }

    int xTruoc = 1, yTruoc = 0;  // x_0 va y_0

    for (int i = 1; i <= n; i++) {
        int xHienTai = xTruoc + yTruoc;
        int yHienTai = 3 * xTruoc + 2 * yTruoc;

        xTruoc = xHienTai;
        yTruoc = yHienTai;
    }

    *x_n = xTruoc;
    *y_n = yTruoc;
}

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Vui long nhap n >= 0.\n");
        return 1;
    }

    int x_n, y_n;
    tinhDay(n, &x_n, &y_n);

    printf("So hang thu %d cua day x: %d\n", n, x_n);
    printf("So hang thu %d cua day y: %d\n", n, y_n);

    return 0;
}
