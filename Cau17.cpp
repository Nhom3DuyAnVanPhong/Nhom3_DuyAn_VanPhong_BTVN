#include <stdio.h>

// Hàm đệ quy tính giá trị của Xn
int tinhXn(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return tinhXn(n - 1) + (n - 1) * tinhXn(n - 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n (n >= 1): ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Vui long nhap n >= 1.\n");
        return 1;
    }

    printf("Gia tri X(%d) (de quy): %d\n", n, tinhXn(n));

    return 0;
}
