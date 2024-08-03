#include <stdio.h>

// Hàm đệ quy tìm số Fibonacci lớn nhất nhỏ hơn n
double dequyFibonacci(double n, double a, double b) {
    if (b >= n) {
        return a;
    }
    return dequyFibonacci(n, b, a + b);
}

// Hàm khử đệ quy tìm số Fibonacci lớn nhất nhỏ hơn n
double khudequyFibonacci(double n) {
    double a = 0, b = 1;
    while (b < n) {
        double temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    double n;
    printf("Nhap so nguyen duong n (double): ");
    scanf_s("%lf", &n);

    if (n <= 1) {
        printf("Khong co so Fibonacci nho hon %.2f.\n", n);
    }
    else {
        printf("So Fibonacci lon nhat nho hon %.2f (de quy): %.2f\n", n, dequyFibonacci(n, 0, 1));
        printf("So Fibonacci lon nhat nho hon %.2f (khong de quy): %.2f\n", n, khudequyFibonacci(n));
    }

    return 0;
}
