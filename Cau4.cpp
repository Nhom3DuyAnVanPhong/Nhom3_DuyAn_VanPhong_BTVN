#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Hàm tạo ma trận vuông ngẫu nhiên
void taoMaTran(int a[MAX][MAX], int n, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}

// Hàm xuất các phần tử thuộc các đường chéo song song với đường chéo chính
void xuatDuongCheoSongSong(int a[MAX][MAX], int n) {
    printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
    for (int k = 1; k < n; k++) {
        printf("Duong cheo tren, lech %d: ", k);
        for (int i = 0; i < n - k; i++) {
            printf("%4d", a[i][i + k]);
        }
        printf("\n");
    }
    for (int k = 1; k < n; k++) {
        printf("Duong cheo duoi, lech %d: ", k);
        for (int i = k; i < n; i++) {
            printf("%4d", a[i][i - k]);
        }
        printf("\n");
    }
}

// Hàm tìm phần tử max thuộc tam giác trên của đường chéo chính
int maxTamGiacTrenDuongCheoChinh(int a[MAX][MAX], int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

// Hàm sắp xếp ma trận tăng dần theo kiểu zic-zắc
void sapXepZigZag(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int idx = 0;

    // Chuyển ma trận thành mảng tạm thời
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[idx++] = a[i][j];
        }
    }

    // Sắp xếp mảng tạm thời
    for (int i = 0; i < idx - 1; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Chuyển mảng tạm thời trở lại ma trận theo kiểu zic-zắc
    idx = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[idx++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[idx++];
            }
        }
    }
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
    int temp[MAX];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    // Sắp xếp mảng tạm thời
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Gán lại giá trị đã sắp xếp cho đường chéo chính
    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
}

// Hàm sắp xếp đường chéo phụ tăng dần/giảm dần
void sapXepDuongCheoPhu(int a[MAX][MAX], int n, int tangDan) {
    int temp[MAX];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][n - 1 - i];
    }

    // Sắp xếp mảng tạm thời
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && temp[i] > temp[j]) || (!tangDan && temp[i] < temp[j])) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Gán lại giá trị đã sắp xếp cho đường chéo phụ
    for (int i = 0; i < n; i++) {
        a[i][n - 1 - i] = temp[i];
    }
}

// Hàm sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void sapXepTheoChiSoDong(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        int temp[MAX];
        for (int j = 0; j < n; j++) {
            temp[j] = a[i][j];
        }

        if (i % 2 == 0) {  // Dòng chẵn
            for (int j = 0; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (temp[j] < temp[k]) {
                        int t = temp[j];
                        temp[j] = temp[k];
                        temp[k] = t;
                    }
                }
            }
        }
        else {  // Dòng lẻ
            for (int j = 0; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (temp[j] > temp[k]) {
                        int t = temp[j];
                        temp[j] = temp[k];
                        temp[k] = t;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            a[i][j] = temp[j];
        }
    }
}

// Hàm sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
void sapXepTheoChiSoCot(int a[MAX][MAX], int n) {
    for (int j = 0; j < n; j++) {
        int temp[MAX];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i][j];
        }

        if (j % 2 == 0) {  // Cột chẵn
            for (int i = 0; i < n - 1; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (temp[i] > temp[k]) {
                        int t = temp[i];
                        temp[i] = temp[k];
                        temp[k] = t;
                    }
                }
            }
        }
        else {  // Cột lẻ
            for (int i = 0; i < n - 1; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (temp[i] < temp[k]) {
                        int t = temp[i];
                        temp[i] = temp[k];
                        temp[k] = t;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            a[i][j] = temp[i];
        }
    }
}

// Hàm sắp xếp các phần tử trên đường chéo chính và các đường chéo song song với đường chéo chính
void sapXepDuongCheoChinhVaSongSong(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int idx = 0;

    // Sắp xếp đường chéo chính
    for (int i = 0; i < n; i++) {
        temp[idx++] = a[i][i];
    }

    // Sắp xếp mảng tạm thời
    for (int i = 0; i < idx - 1; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Gán lại giá trị đã sắp xếp cho đường chéo chính
    idx = 0;
    for (int i = 0; i < n; i++) {
        a[i][i] = temp[idx++];
    }

    // Sắp xếp các đường chéo song song
    for (int k = 1; k < n; k++) {
        idx = 0;
        for (int i = 0; i < n - k; i++) {
            temp[idx++] = a[i][i + k];
        }
        for (int i = 0; i < idx - 1; i++) {
            for (int j = i + 1; j < idx; j++) {
                if (temp[i] > temp[j]) {
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }
        idx = 0;
        for (int i = 0; i < n - k; i++) {
            a[i][i + k] = temp[idx++];
        }
    }

    for (int k = 1; k < n; k++) {
        idx = 0;
        for (int i = k; i < n; i++) {
            temp[idx++] = a[i][i - k];
        }
        for (int i = 0; i < idx - 1; i++) {
            for (int j = i + 1; j < idx; j++) {
                if (temp[i] > temp[j]) {
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }
        idx = 0;
        for (int i = k; i < n; i++) {
            a[i][i - k] = temp[idx++];
        }
    }
}

// Hàm di chuyển các phần tử chẵn lên trên, phần tử lẻ xuống dưới
void diChuyenChanLenTren(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int idxChan = 0, idxLe = 0;

    // Phân loại các phần tử chẵn và lẻ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                temp[idxChan++] = a[i][j];
            }
            else {
                temp[MAX * MAX - 1 - idxLe++] = a[i][j];
            }
        }
    }

    // Cập nhật ma trận với các phần tử chẵn ở trên và phần tử lẻ ở dưới
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (idx < idxChan) {
                a[i][j] = temp[idx++];
            }
            else {
                a[i][j] = temp[MAX * MAX - 1 - (idx - idxChan)];
            }
        }
    }
}

// Hàm kiểm tra đối xứng qua đường chéo chính
int kiemTraDoiXung(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;  // Không đối xứng
            }
        }
    }
    return 1;  // Đối xứng
}

// Hàm menu chính
void menu() {
    int a[MAX][MAX];
    int n, min, max;
    int choice;

    printf("Nhap cap cua ma tran vuong n (n >= 5): ");
    scanf_s("%d", &n);
    printf("Nhap gia tri nho nhat min: ");
    scanf_s("%d", &min);
    printf("Nhap gia tri lon nhat max: ");
    scanf_s("%d", &max);

    if (n < 5) {
        printf("Cap cua ma tran phai >= 5\n");
        return;
    }

    taoMaTran(a, n, min, max);

    do {
        printf("\nMenu:\n");
        printf("1. Tao/xuat ma tran vuong\n");
        printf("2. Xuat cac phan tu tren duong cheo chinh\n");
        printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
        printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
        printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
        printf("6. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
        printf("7. Sap xep duong cheo phu tang dan/giam dan\n");
        printf("8. Sap xep ma tran theo chi so dong\n");
        printf("9. Sap xep ma tran theo chi so cot\n");
        printf("10. Sap xep duong cheo chinh va song song\n");
        printf("11. Di chuyen cac phan tu chan len tren\n");
        printf("12. Kiem tra doi xung qua duong cheo chinh\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            taoMaTran(a, n, min, max);
            printf("Ma tran ngau nhien:\n");
            xuatMaTran(a, n);
            break;
        case 2:
            printf("Cac phan tu tren duong cheo chinh:\n");
            xuatDuongCheoChinh(a, n);
            break;
        case 3:
            printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
            xuatDuongCheoSongSong(a, n);
            break;
        case 4: {
            int maxTren = maxTamGiacTrenDuongCheoChinh(a, n);
            printf("Phan tu max thuoc tam giac tren cua duong cheo chinh: %d\n", maxTren);
            break;
        }
        case 5:
            printf("Sap xep ma tran tang dan theo kieu zic-zac:\n");
            sapXepZigZag(a, n);
            xuatMaTran(a, n);
            break;
        case 6:
            printf("Sap xep duong cheo chinh tang dan tu tren xuong duoi:\n");
            sapXepDuongCheoChinh(a, n);
            xuatMaTran(a, n);
            break;
        case 7: {
            int tangDan;
            printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
            scanf_s("%d", &tangDan);
            sapXepDuongCheoPhu(a, n, tangDan);
            printf("Sap xep duong cheo phu:\n");
            xuatMaTran(a, n);
            break;
        }
        case 8:
            printf("Sap xep ma tran theo chi so dong:\n");
            sapXepTheoChiSoDong(a, n);
            xuatMaTran(a, n);
            break;
        case 9:
            printf("Sap xep ma tran theo chi so cot:\n");
            sapXepTheoChiSoCot(a, n);
            xuatMaTran(a, n);
            break;
        case 10:
            printf("Sap xep duong cheo chinh va song song:\n");
            sapXepDuongCheoChinhVaSongSong(a, n);
            xuatMaTran(a, n);
            break;
        case 11:
            printf("Di chuyen cac phan tu chan len tren:\n");
            diChuyenChanLenTren(a, n);
            xuatMaTran(a, n);
            break;
        case 12:
            if (kiemTraDoiXung(a, n)) {
                printf("Ma tran doi xung qua duong cheo chinh.\n");
            }
            else {
                printf("Ma tran khong doi xung qua duong cheo chinh.\n");
            }
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
