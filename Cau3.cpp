//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
//
//#define MAX 100
//
//// Hàm tạo ma trận ngẫu nhiên
//void taoMaTran(int a[MAX][MAX], int m, int n, int min, int max) {
//    srand(time(NULL));
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            a[i][j] = min + rand() % (max - min + 1);
//        }
//    }
//}
//
//// Hàm xuất ma trận
//void xuatMaTran(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%4d", a[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// Hàm tính và xuất tổng giá trị từng dòng
//void tongGiaTriTungDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        int tong = 0;
//        for (int j = 0; j < n; j++) {
//            tong += a[i][j];
//        }
//        printf("Tong gia tri dong %d: %d\n", i + 1, tong);
//    }
//}
//
//// Hàm tìm phần tử lớn nhất trên từng cột
//void phanTuLonNhatTrenTungCot(int a[MAX][MAX], int m, int n) {
//    for (int j = 0; j < n; j++) {
//        int max = a[0][j];
//        for (int i = 1; i < m; i++) {
//            if (a[i][j] > max) {
//                max = a[i][j];
//            }
//        }
//        printf("Phan tu lon nhat tren cot %d: %d\n", j + 1, max);
//    }
//}
//
//// Hàm xuất các phần tử trên đường biên
//void xuatPhanTuDuongBien(int a[MAX][MAX], int m, int n) {
//    printf("Phan tu duong bien:\n");
//    for (int j = 0; j < n; j++) {
//        printf("%4d", a[0][j]);
//    }
//    printf("\n");
//    for (int i = 1; i < m - 1; i++) {
//        printf("%4d%*s%4d\n", a[i][0], (n - 2) * 4, "", a[i][n - 1]);
//    }
//    for (int j = 0; j < n; j++) {
//        printf("%4d", a[m - 1][j]);
//    }
//    printf("\n");
//}
//
//// Hàm xuất các phần tử cực đại
//void xuatPhanTuCucDai(int a[MAX][MAX], int m, int n) {
//    printf("Phan tu cuc dai:\n");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            bool isMax = true;
//            for (int k = 0; k < m; k++) {
//                if (a[k][j] > a[i][j]) {
//                    isMax = false;
//                    break;
//                }
//            }
//            for (int k = 0; k < n; k++) {
//                if (a[i][k] > a[i][j]) {
//                    isMax = false;
//                    break;
//                }
//            }
//            if (isMax) {
//                printf("%4d", a[i][j]);
//            }
//        }
//    }
//    printf("\n");
//}
//
//// Hàm xuất dòng chỉ chứa số chẵn
//void xuatDongChiChuaSoChan(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        bool toanSoChan = true;
//        for (int j = 0; j < n; j++) {
//            if (a[i][j] % 2 != 0) {
//                toanSoChan = false;
//                break;
//            }
//        }
//        if (toanSoChan) {
//            printf("Dong %d chua toan so chan: ", i + 1);
//            for (int j = 0; j < n; j++) {
//                printf("%4d", a[i][j]);
//            }
//            printf("\n");
//        }
//    }
//}
//
//// Hàm sắp xếp mảng tăng theo từng dòng
//void sapXepMangTangTheoTungDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            for (int k = j + 1; k < n; k++) {
//                if (a[i][j] > a[i][k]) {
//                    int temp = a[i][j];
//                    a[i][j] = a[i][k];
//                    a[i][k] = temp;
//                }
//            }
//        }
//    }
//}
//
//
////1. Hàm xuất các cột chỉ chứa số lẻ
//void xuatCotChiChuaSoLe(int a[MAX][MAX], int m, int n) {
//    bool coCotSoLe = false;
//    for (int j = 0; j < n; j++) {
//        bool chiChuaSoLe = true;
//        for (int i = 0; i < m; i++) {
//            if (a[i][j] % 2 == 0) {
//                chiChuaSoLe = false;
//                break;
//            }
//        }
//        if (chiChuaSoLe) {
//            coCotSoLe = true;
//            printf("Cot %d chi chua so le: ", j + 1);
//            for (int i = 0; i < m; i++) {
//                printf("%4d", a[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    if (!coCotSoLe) {
//        printf("Khong co cot chi chua so le.\n");
//    }
//}
//
////2. Hàm tìm phần tử lớn nhất trên các phần tử biên của ma trận
//int phanTuLonNhatTrenDuongBien(int a[MAX][MAX], int m, int n) {
//    int max = a[0][0];
//    for (int j = 0; j < n; j++) {
//        if (a[0][j] > max) max = a[0][j];
//        if (a[m - 1][j] > max) max = a[m - 1][j];
//    }
//    for (int i = 1; i < m - 1; i++) {
//        if (a[i][0] > max) max = a[i][0];
//        if (a[i][n - 1] > max) max = a[i][n - 1];
//    }
//    return max;
//}
//
////3. Hàm đếm các phần tử có chữ số 2 xuất hiện trong các chữ số của nó
//int demPhanTuChuaChuSo2(int a[MAX][MAX], int m, int n) {
//    int dem = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            int num = a[i][j];
//            while (num > 0) {
//                if (num % 10 == 2) {
//                    dem++;
//                    break;
//                }
//                num /= 10;
//            }
//        }
//    }
//    return dem;
//}
//
////4. Hàm xuất các phần tử cực tiểu của ma trận
//void xuatPhanTuCucTieu(int a[MAX][MAX], int m, int n) {
//    printf("Phan tu cuc tieu: ");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            bool isMin = true;
//            for (int k = 0; k < m; k++) {
//                if (a[k][j] < a[i][j]) {
//                    isMin = false;
//                    break;
//                }
//            }
//            for (int k = 0; k < n; k++) {
//                if (a[i][k] < a[i][j]) {
//                    isMin = false;
//                    break;
//                }
//            }
//            if (isMin) {
//                printf("%4d", a[i][j]);
//            }
//        }
//    }
//    printf("\n");
//}
//
////5. Hàm sắp xếp ma trận theo yêu cầu
//void sapXepMaTranTheoDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            for (int k = j + 1; k < n; k++) {
//                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 == 1 && a[i][j] > a[i][k])) {
//                    int temp = a[i][j];
//                    a[i][j] = a[i][k];
//                    a[i][k] = temp;
//                }
//            }
//        }
//    }
//}
//
////6. Hàm sắp xếp ma trận theo yêu cầu
//void sapXepMaTranTheoCot(int a[MAX][MAX], int m, int n) {
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < m - 1; i++) {
//            for (int k = i + 1; k < m; k++) {
//                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 == 1 && a[i][j] < a[k][j])) {
//                    int temp = a[i][j];
//                    a[i][j] = a[k][j];
//                    a[k][j] = temp;
//                }
//            }
//        }
//    }
//}
//
////7. Hàm kiểm tra ma trận giảm dần theo dạng ziczac
//bool kiemTraZicZac(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            if ((i % 2 == 0 && a[i][j] < a[i][j + 1]) || (i % 2 == 1 && a[i][j] > a[i][j + 1])) {
//                return false;
//            }
//        }
//    }
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < m - 1; i++) {
//            if ((j % 2 == 0 && a[i][j] < a[i + 1][j]) || (j % 2 == 1 && a[i][j] > a[i + 1][j])) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
////8. Hàm liệt kê chỉ số các dòng chứa toàn giá trị chẵn
//void lietKeDongToanSoChan(int a[MAX][MAX], int m, int n) {
//    bool coDongToanChan = false;
//    for (int i = 0; i < m; i++) {
//        bool toanSoChan = true;
//        for (int j = 0; j < n; j++) {
//            if (a[i][j] % 2 != 0) {
//                toanSoChan = false;
//                break;
//            }
//        }
//        if (toanSoChan) {
//            coDongToanChan = true;
//            printf("Dong %d chua toan so chan.\n", i + 1);
//        }
//    }
//    if (!coDongToanChan) {
//        printf("Khong co dong chua toan so chan.\n");
//    }
//}
//
////9. Hàm liệt kê các dòng chứa giá trị giảm dần
//void lietKeDongGiamDan(int a[MAX][MAX], int m, int n) {
//    bool coDongGiamDan = false;
//    for (int i = 0; i < m; i++) {
//        bool giamDan = true;
//        for (int j = 0; j < n - 1; j++) {
//            if (a[i][j] < a[i][j + 1]) {
//                giamDan = false;
//                break;
//            }
//        }
//        if (giamDan) {
//            coDongGiamDan = true;
//            printf("Dong %d chua gia tri giam dan.\n", i + 1);
//        }
//    }
//    if (!coDongGiamDan) {
//        printf("Khong co dong chua gia tri giam dan.\n");
//    }
//}
//
////10. Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
//int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
//    int freq[MAX * MAX] = { 0 };
//    int maxFreq = 0;
//    int maxValue = a[0][0];
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            int value = a[i][j];
//            freq[value]++;
//            if (freq[value] > maxFreq) {
//                maxFreq = freq[value];
//                maxValue = value;
//            }
//        }
//    }
//    return maxValue;
//}
//
////11. Hàm tìm các chữ số xuất hiện nhiều nhất trong ma trận
//void timChuSoXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
//    int freq[10] = { 0 };
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            int num = a[i][j];
//            while (num > 0) {
//                freq[num % 10]++;
//                num /= 10;
//            }
//        }
//    }
//    int maxFreq = 0;
//    for (int i = 0; i < 10; i++) {
//        if (freq[i] > maxFreq) {
//            maxFreq = freq[i];
//        }
//    }
//    printf("Chu so xuat hien nhieu nhat: ");
//    for (int i = 0; i < 10; i++) {
//        if (freq[i] == maxFreq) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//}
//
////12. Hàm liệt kê các cột có tổng nhỏ nhất trong ma trận
//void lietKeCotTongNhoNhat(int a[MAX][MAX], int m, int n) {
//    int minSum = INT_MAX;
//    int sum[MAX] = { 0 };
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < m; i++) {
//            sum[j] += a[i][j];
//        }
//        if (sum[j] < minSum) {
//            minSum = sum[j];
//        }
//    }
//    printf("Cac cot co tong nho nhat: ");
//    for (int j = 0; j < n; j++) {
//        if (sum[j] == minSum) {
//            printf("%d ", j + 1);
//        }
//    }
//    printf("\n");
//}
//
////13. Hàm hoán vị hai cột i và j trong ma trận
//void hoanViCot(int a[MAX][MAX], int m, int n, int i, int j) {
//    for (int k = 0; k < m; k++) {
//        int temp = a[k][i];
//        a[k][i] = a[k][j];
//        a[k][j] = temp;
//    }
//}
//
////14. Hàm hoán vị hai dòng k và l trong ma trận
//void hoanViDong(int a[MAX][MAX], int m, int n, int k, int l) {
//    for (int j = 0; j < n; j++) {
//        int temp = a[k][j];
//        a[k][j] = a[l][j];
//        a[l][j] = temp;
//    }
//}
//void menu() {
//    int a[MAX][MAX];
//    int m, n;
//    int min, max;
//    int choice;
//
//    printf("Nhap so dong m: ");
//    scanf_s("%d", &m);
//    printf("Nhap so cot n: ");
//    scanf_s("%d", &n);
//    printf("Nhap gia tri nho nhat min: ");
//    scanf_s("%d", &min);
//    printf("Nhap gia tri lon nhat max: ");
//    scanf_s("%d", &max);
//
//    taoMaTran(a, m, n, min, max);
//
//    do {
//        printf("\nMenu:\n");
//        printf("1. Tao va xuat ma tran\n");
//        printf("2. Tinh va xuat tong gia tri tung dong\n");
//        printf("3. Xuat phan tu lon nhat tren tung cot\n");
//        printf("4. Xuat cac phan tu duong bien\n");
//        printf("5. Xuat cac phan tu cuc dai\n");
//        printf("6. Xuat dong chi chua so chan\n");
//        printf("7. Sap xep mang tang theo tung dong\n");
//        printf("8. Xuat cac cot chi chua so le\n");
//        printf("9. Tim phan tu lon nhat tren duong bien\n");
//        printf("10. Dem phan tu co chu so 2\n");
//        printf("11. Xuat cac phan tu cuc tieu\n");
//        printf("12. Sap xep ma tran theo dong\n");
//        printf("13. Sap xep ma tran theo cot\n");
//        printf("14. Kiem tra ma tran theo ziczac\n");
//        printf("15. Liet ke dong chua toan so chan\n");
//        printf("16. Liet ke dong chua gia tri giam dan\n");
//        printf("17. Tim gia tri xuat hien nhieu nhat\n");
//        printf("18. Tim chu so xuat hien nhieu nhat\n");
//        printf("19. Liet ke cot co tong nho nhat\n");
//        printf("20. Hoan vi hai cot\n");
//        printf("21. Hoan vi hai dong\n");
//        printf("22. Thoat\n");
//        printf("Chon chuc nang: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("Ma tran ngau nhien:\n");
//            xuatMaTran(a, m, n);
//            break;
//        case 2:
//            printf("Tong gia tri tung dong:\n");
//            tongGiaTriTungDong(a, m, n);
//            break;
//        case 3:
//            printf("Phan tu lon nhat tren tung cot:\n");
//            phanTuLonNhatTrenTungCot(a, m, n);
//            break;
//        case 4:
//            printf("Phan tu duong bien:\n");
//            xuatPhanTuDuongBien(a, m, n);
//            break;
//        case 5:
//            printf("Phan tu cuc dai:\n");
//            xuatPhanTuCucDai(a, m, n);
//            break;
//        case 6:
//            printf("Dong chi chua so chan:\n");
//            xuatDongChiChuaSoChan(a, m, n);
//            break;
//        case 7:
//            printf("Sap xep mang tang theo tung dong:\n");
//            sapXepMangTangTheoTungDong(a, m, n);
//            xuatMaTran(a, m, n);
//            break;
//        case 8:
//            printf("Xuat cot chi chua so le:\n");
//            xuatCotChiChuaSoLe(a, m, n);
//            break;
//        case 9:
//            printf("Phan tu lon nhat tren duong bien: %d\n", phanTuLonNhatTrenDuongBien(a, m, n));
//            break;
//        case 10:
//            printf("So phan tu co chu so 2: %d\n", demPhanTuChuaChuSo2(a, m, n));
//            break;
//        case 11:
//            printf("Phan tu cuc tieu:\n");
//            xuatPhanTuCucTieu(a, m, n);
//            break;
//        case 12:
//            printf("Sap xep ma tran theo dong:\n");
//            sapXepMaTranTheoDong(a, m, n);
//            xuatMaTran(a, m, n);
//            break;
//        case 13:
//            printf("Sap xep ma tran theo cot:\n");
//            sapXepMaTranTheoCot(a, m, n);
//            xuatMaTran(a, m, n);
//            break;
//        case 14:
//            printf("Ma tran theo ziczac: %s\n", kiemTraZicZac(a, m, n) ? "Hop le" : "Khong hop le");
//            break;
//        case 15:
//            lietKeDongToanSoChan(a, m, n);
//            break;
//        case 16:
//            lietKeDongGiamDan(a, m, n);
//            break;
//        case 17:
//            printf("Gia tri xuat hien nhieu nhat: %d\n", timGiaTriXuatHienNhieuNhat(a, m, n));
//            break;
//        case 18:
//            timChuSoXuatHienNhieuNhat(a, m, n);
//            break;
//        case 19:
//            lietKeCotTongNhoNhat(a, m, n);
//            break;
//        case 20: {
//            int i, j;
//            printf("Nhap chi so cot thu nhat: ");
//            scanf_s("%d", &i);
//            printf("Nhap chi so cot thu hai: ");
//            scanf_s("%d", &j);
//            hoanViCot(a, m, n, i - 1, j - 1);
//            xuatMaTran(a, m, n);
//            break;
//        }
//        case 21: {
//            int k, l;
//            printf("Nhap chi so dong thu nhat: ");
//            scanf_s("%d", &k);
//            printf("Nhap chi so dong thu hai: ");
//            scanf_s("%d", &l);
//            hoanViDong(a, m, n, k - 1, l - 1);
//            xuatMaTran(a, m, n);
//            break;
//        }
//        case 22:
//            printf("Thoat chuong trinh.\n");
//            break;
//        default:
//            printf("Lua chon khong hop le. Vui long chon lai.\n");
//        }
//    } while (choice != 22);
//}
//
//int main() {
//    menu();
//    return 0;
//}
//
//
