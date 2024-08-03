#include <stdio.h>

// Hàm đệ quy tính giá trị phần tử thứ n của cấp số nhân
double capSoNhan_deQuy(int n, double a, double q) {
    if (n == 1) {
        return a;
    }
    else {
        return q * capSoNhan_deQuy(n - 1, a, q);
    }
}

// Hàm khử đệ quy tính giá trị phần tử thứ n của cấp số nhân
double capSoNhan_khuDeQuy(int n, double a, double q) {
    double Un = a;
    for (int i = 1; i < n; i++) {
        Un *= q;
    }
    return Un;
}

int main() {
    int n;
    double a, q;

    printf("Nhap gia tri cua a (hang dau): ");
    scanf_s("%lf", &a);

    printf("Nhap gia tri cua q (cong boi): ");
    scanf_s("%lf", &q);

    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Vui long nhap n >= 1.\n");
        return 1;
    }

    printf("Gia tri phan tu thu %d cua cap so nhan (de quy): %.2lf\n", n, capSoNhan_deQuy(n, a, q));
    printf("Gia tri phan tu thu %d cua cap so nhan (khu de quy): %.2lf\n", n, capSoNhan_khuDeQuy(n, a, q));

    return 0;
}
