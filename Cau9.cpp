#include <stdio.h>

// Hàm đệ quy tính S1(n)
double S1_recursive(int n) {
    if (n == 0) {
        return 0.0;
    }
    return 1.0 / (n * (n + 1) * (n + 2)) + S1_recursive(n - 1);
}

// Hàm đệ quy tính S2(n)
int S2_recursive(int n) {
    if (n == 0) {
        return 0;
    }
    return n * n + S2_recursive(n - 1);
}

// Hàm đệ quy tính S3(n)
int S3_recursive(int n) {
    if (n == 0) {
        return 0;
    }
    return (n * (n + 1)) / 2 + S3_recursive(n - 1);
}

#include <stdio.h>

// Hàm tính giai thừa sử dụng double
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Hàm đệ quy tính S4(n)
double S4_recursive(int n) {
    if (n == 0) {
        return 0.0;
    }
    double term = (double)(2 * n - 1 + 2 * n) / factorial(2 * n);
    if (n % 2 == 0) {
        return term + S4_recursive(n - 1);
    }
    else {
        return -term + S4_recursive(n - 1);
    }
}

int main() {
    int choice, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tinh S1(n) = 1/(1*2*3) + 1/(2*3*4) + ... + 1/(n*(n+1)*(n+2))\n");
        printf("2. Tinh S2(n) = 1^2 + 2^2 + ... + n^2\n");
        printf("3. Tinh S3(n) = 1 + (1+2) + (1+2+3) + ... + (1+2+...+n)\n");
        printf("4. Tinh S4(n) = - (1+2)/2! + (3+4)/4! - (5+6)/6! + ... + (-1)^n * (2n-1 + 2n) / (2n)!\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        if (choice == 5) {
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Nhap so nguyen duong n: ");
            scanf_s("%d", &n);

            if (n <= 0) {
                printf("Vui long nhap mot so nguyen duong.\n");
                continue;
            }

            switch (choice) {
            case 1:
                printf("S1(n) theo cach de quy: %.6f\n", S1_recursive(n));
                break;
            case 2:
                printf("S2(n) theo cach de quy: %d\n", S2_recursive(n));
                break;
            case 3:
                printf("S3(n) theo cach de quy: %d\n", S3_recursive(n));
                break;
            case 4:
                printf("S4(n) theo cach de quy: %.6f\n", S4_recursive(n));
                break;
            }
        }
        else {
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

