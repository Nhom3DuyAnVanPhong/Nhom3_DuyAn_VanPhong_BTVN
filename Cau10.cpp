#include <stdio.h>

// Hàm tính số Fibonacci thứ n
unsigned long long fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    unsigned long long a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Hàm xuất dãy số Fibonacci thuộc đoạn [m, n]
void printFibonacciInRange(int m, int n) {
    int i = 1;
    unsigned long long fib;
    while (1) {
        fib = fibonacci(i);
        if (fib > n) {
            break;
        }
        if (fib >= m) {
            printf("%llu ", fib);
        }
        i++;
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Nhap m: ");
    scanf_s("%d", &m);
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (m > n || m < 1 || n < 1) {
        printf("Vui long nhap m va n sao cho m <= n va m, n >= 1.\n");
    }
    else {
        printf("Day so Fibonacci trong khoang [%d, %d] la:\n", m, n);
        printFibonacciInRange(m, n);
    }

    return 0;
}
