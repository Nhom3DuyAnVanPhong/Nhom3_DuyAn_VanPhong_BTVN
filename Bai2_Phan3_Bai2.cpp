//#include <stdio.h>
//#include <stdlib.h>
//#define Max 100
//
//// Cấu trúc hỗn số
//typedef struct {
//	int phanNguyen;
//	int tuSo; // Tử số của phần phân số
//	int mauSo; // Mẫu số của phần phân số
//} HonSo;
//int timHonSo(HonSo b[], int n, HonSo x) {
//	for (int i = 0; i < n; i++) {
//		if (b[i].phanNguyen == x.phanNguyen &&
//			b[i].tuSo == x.tuSo && b[i].mauSo == x.mauSo) {
//			return i; // Trả về vị trí tìm thấy
//		}
//	}
//	return -1; // Không tìm thấy
//}
//void sapXepChanDauLeCuoi(HonSo b[], int n) {
//	HonSo temp;
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if ((b[i].phanNguyen % 2 != 0 && b[j].phanNguyen % 2 == 0) ||
//				(b[i].phanNguyen % 2 == b[j].phanNguyen % 2 && b[i].phanNguyen > b[j].phanNguyen)) {
//				temp = b[i];
//				b[i] = b[j];
//				b[j] = temp;
//			}
//		}
//	}
//}
//int soSanhHonSo(HonSo a, HonSo b) {
//	if (a.phanNguyen < b.phanNguyen) return -1;
//	if (a.phanNguyen > b.phanNguyen) return 1;
//	double giaTriA = (double)a.tuSo / a.mauSo;
//	double giaTriB = (double)b.tuSo / b.mauSo;
//	if (giaTriA < giaTriB) return -1;
//	if (giaTriA > giaTriB) return 1;
//	return 0;
//}
//
//int timHonSoBinarySearch(HonSo b[], int n, HonSo x) {
//	int left = 0, right = n - 1;
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		int soSanh = soSanhHonSo(b[mid], x);
//		if (soSanh == 0) return mid;
//		if (soSanh < 0) left = mid + 1;
//		else right = mid - 1;
//	}
//	return -1; // Không tìm thấy
//}
//void chiaMang(HonSo b[], int n, int s1[], double s2[]) {
//	for (int i = 0; i < n; i++) {
//		s1[i] = b[i].phanNguyen;
//		s2[i] = (double)b[i].tuSo / b[i].mauSo;
//	}
//}
//void xoaPhanTu(HonSo b[], int *n, int k) {
//	if (k < 0 || k >= *n) return; // Kiểm tra vị trí hợp lệ
//	for (int i = k; i < *n - 1; i++) {
//		b[i] = b[i + 1];
//	}
//	(*n)--;
//}
//void themHonSo(HonSo b[], int *n, HonSo x, int k) {
//	if (k < 0 || k > *n) return; // Kiểm tra vị trí hợp lệ
//	for (int i = *n; i > k; i--) {
//		b[i] = b[i - 1];
//	}
//	b[k] = x;
//	(*n)++;
//}
//void taoMangPhanSo(double c[], HonSo b[], int n) {
//	for (int i = 0; i < n; i++) {
//		c[i] = (double)b[i].tuSo / b[i].mauSo;
//	}
//}
//double tongHonSo(HonSo b[], int n) {
//	double tong = 0.0;
//	for (int i = 0; i < n; i++) {
//		tong += b[i].phanNguyen + (double)b[i].tuSo / b[i].mauSo;
//	}
//	return tong;
//}
//HonSo timHonSoLonNhat(HonSo b[], int n) {
//	HonSo max = b[0];
//	for (int i = 1; i < n; i++) {
//		if (soSanhHonSo(b[i], max) > 0) {
//			max = b[i];
//		}
//	}
//	return max;
//}
//
//HonSo timHonSoNhoNhat(HonSo b[], int n) {
//	HonSo min = b[0];
//	for (int i = 1; i < n; i++) {
//		if (soSanhHonSo(b[i], min) < 0) {
//			min = b[i];
//		}
//	}
//	return min;
//}
//void viTriPhanNguyenChan(HonSo b[], int n) {
//	for (int i = 0; i < n; i++) {
//		if (b[i].phanNguyen % 2 == 0) {
//			printf("Vi tri phan nguyen chan: %d\n", i);
//		}
//	}
//}
//void viTriHonSoLonNhat(HonSo b[], int n) {
//	HonSo max = timHonSoLonNhat(b, n);
//	for (int i = 0; i < n; i++) {
//		if (soSanhHonSo(b[i], max) == 0) {
//			printf("Vi tri phan tu lon nhat: %d\n", i);
//		}
//	}
//}
//
//void viTriHonSoNhoNhat(HonSo b[], int n) {
//	HonSo min = timHonSoNhoNhat(b, n);
//	for (int i = 0; i < n; i++) {
//		if (soSanhHonSo(b[i], min) == 0) {
//			printf("Vi tri phan tu nho nhat: %d\n", i);
//		}
//	}
//}
//int main() {
//	int n;
//	printf("Nhap so phan tu cua mang b: ");
//	scanf_s("%d", &n);
//
//	HonSo b[100]; // Khai báo mảng hỗn số với kích thước lớn hơn n
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan nguyen cua hon so thu %d: ", i + 1);
//		scanf_s("%d", &b[i].phanNguyen);
//		printf("Nhap tu so cua phan so thu %d: ", i + 1);
//		scanf_s("%d", &b[i].tuSo);
//		printf("Nhap mau so cua phan so thu %d: ", i + 1);
//		scanf_s("%d", &b[i].mauSo);
//	}
//
//	int choice;
//	do {
//		printf("\n--- MENU ---\n");
//		printf("1. Tim hon so x trong mang b\n");
//		printf("2. Sap xep b sao cho cac phan tu co phan nguyen chan len dau, phan tu co phan nguyen le o cuoi mang\n");
//		printf("3. Tim hon so x theo giai thuat binary search trong mang b da duoc sap xep\n");
//		printf("4. Chia mang b thanh 2 mang s1 va s2\n");
//		printf("5. Xoa phan tu thu k trong mang b\n");
//		printf("6. Them hon so x vao mang b tai vi tri k\n");
//		printf("7. Tao mang c chua cac phan tu la phan so duoc doi tu cac phan tu hon so cua mang b\n");
//		printf("8. Tinh tong cac phan tu cua mang b\n");
//		printf("9. Tim phan tu lon nhat/nho nhat cua b\n");
//		printf("10. Xuat vi tri phan tu co phan nguyen chan cua b\n");
//		printf("11. Xuat vi tri cua phan tu lon nhat/nho nhat cua b\n");
//		printf("0. Thoat\n");
//		printf("Nhap lua chon cua ban: ");
//		scanf_s("%d", &choice);
//
//		switch (choice) {
//		case 1: {
//					HonSo x;
//					printf("Nhap phan nguyen cua hon so can tim: ");
//					scanf_s("%d", &x.phanNguyen);
//					printf("Nhap tu so cua phan so can tim: ");
//					scanf_s("%d", &x.tuSo);
//					printf("Nhap mau so cua phan so can tim: ");
//					scanf_s("%d", &x.mauSo);
//					int viTri = timHonSo(b, n, x);
//					if (viTri != -1) {
//						printf("Tim thay hon so x tai vi tri %d\n", viTri);
//					}
//					else {
//						printf("Khong tim thay hon so x\n");
//					}
//					break;
//		}
//		case 2:
//			sapXepChanDauLeCuoi(b, n);
//			printf("Mang sau khi sap xep:\n");
//			for (int i = 0; i < n; i++) {
//				printf("%d %d/%d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
//			}
//			break;
//		case 3: {
//					HonSo x;
//					printf("Nhap phan nguyen cua hon so can tim (binary search): ");
//					scanf_s("%d", &x.phanNguyen);
//					printf("Nhap tu so cua phan so can tim (binary search): ");
//					scanf_s("%d", &x.tuSo);
//					printf("Nhap mau so cua phan so can tim (binary search): ");
//					scanf_s("%d", &x.mauSo);
//					int viTri = timHonSoBinarySearch(b, n, x);
//					if (viTri != -1) {
//						printf("Tim thay hon so x tai vi tri %d (binary search)\n", viTri);
//					}
//					else {
//						printf("Khong tim thay hon so x (binary search)\n");
//					}
//					break;
//		}
//		case 4: {
//					int s1[Max];
//					double s2[Max];
//					chiaMang(b, n, s1, s2);
//					printf("Mang s1 chua phan nguyen:\n");
//					for (int i = 0; i < n; i++) {
//						printf("%d ", s1[i]);
//					}
//					printf("\nMang s2 chua phan so:\n");
//					for (int i = 0; i < n; i++) {
//						printf("%.2lf ", s2[i]);
//					}
//					printf("\n");
//					break;
//		}
//		case 5: {
//					int k;
//					printf("Nhap vi tri phan tu can xoa: ");
//					scanf_s("%d", &k);
//					xoaPhanTu(b, &n, k);
//					printf("Mang sau khi xoa:\n");
//					for (int i = 0; i < n; i++) {
//						printf("%d %d/%d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
//					}
//					break;
//		}
//		case 6: {
//					HonSo x;
//					int k;
//					printf("Nhap phan nguyen cua hon so can them: ");
//					scanf_s("%d", &x.phanNguyen);
//					printf("Nhap tu so cua phan so can them: ");
//					scanf_s("%d", &x.tuSo);
//					printf("Nhap mau so cua phan so can them: ");
//					scanf_s("%d", &x.mauSo);
//					printf("Nhap vi tri can them: ");
//					scanf_s("%d", &k);
//					themHonSo(b, &n, x, k);
//					printf("Mang sau khi them:\n");
//					for (int i = 0; i < n; i++) {
//						printf("%d %d/%d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
//					}
//					break;
//		}
//		case 7: {
//					double c[Max];
//					taoMangPhanSo(c, b, n);
//					printf("Mang c chua cac phan so doi tu hon so:\n");
//					for (int i = 0; i < n; i++) {
//						printf("%.2lf ", c[i]);
//					}
//					printf("\n");
//					break;
//		}
//		case 8:
//			printf("Tong cac phan tu cua mang b: %.2lf\n", tongHonSo(b, n));
//			break;
//		case 9: {
//					HonSo max = timHonSoLonNhat(b, n);
//					HonSo min = timHonSoNhoNhat(b, n);
//					printf("Phan tu lon nhat: %d %d/%d\n", max.phanNguyen, max.tuSo, max.mauSo);
//					printf("Phan tu nho nhat: %d %d/%d\n", min.phanNguyen, min.tuSo, min.mauSo);
//					break;
//		}
//		case 10:
//			viTriPhanNguyenChan(b, n);
//			break;
//		case 11:
//			viTriHonSoLonNhat(b, n);
//			viTriHonSoNhoNhat(b, n);
//			break;
//		case 0:
//			printf("Thoat chuong trinh.\n");
//			break;
//		default:
//			printf("Lua chon khong hop le. Vui long chon lai.\n");
//			break;
//		}
//	} while (choice != 0);
//
//	return 0;
//}
