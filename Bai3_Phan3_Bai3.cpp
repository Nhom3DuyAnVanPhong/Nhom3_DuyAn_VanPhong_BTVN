//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAX 100
//
//// Cấu trúc khách hàng
//typedef struct {
//	char hoTen[50];
//	char soDienThoai[15];
//	int soVeNguoiLon;
//	int soVeTreEm;
//	char tenPhim[100];
//	char phongChieu[20];
//	char xuatChieu[20];
//	int tienPhaiTra;
//} KhachHang;
//
//// Mảng danh sách khách hàng
//KhachHang dskh[MAX];
//int n = 0; // Số lượng khách hàng
//
//// Đọc danh sách khách hàng từ file
//void docDanhSachKhachHang(const char *filename) {
//	FILE *file;
//	errno_t err = fopen_s(&file, filename, "r");
//	if (err != 0) {
//		printf("Khong mo duoc file.\n");
//		return;
//	}
//	while (fscanf_s(file, "%[^,],%[^,],%d,%d,%[^,],%[^,],%[^,],%d\n",
//		dskh[n].hoTen,
//		dskh[n].soDienThoai,
//		&dskh[n].soVeNguoiLon,
//		&dskh[n].soVeTreEm,
//		dskh[n].tenPhim,
//		dskh[n].phongChieu,
//		dskh[n].xuatChieu,
//		&dskh[n].tienPhaiTra) == 8) {
//		n++;
//	}
//	fclose(file);
//}
//
//// Xuất danh sách khách hàng
//void xuatDanhSachKhachHang() {
//	printf("Danh sach khach hang:\n");
//	for (int i = 0; i < n; i++) {
//		printf("%s, %s, %d, %d, %s, %s, %s, %d\n",
//			dskh[i].hoTen,
//			dskh[i].soDienThoai,
//			dskh[i].soVeNguoiLon,
//			dskh[i].soVeTreEm,
//			dskh[i].tenPhim,
//			dskh[i].phongChieu,
//			dskh[i].xuatChieu,
//			dskh[i].tienPhaiTra);
//	}
//}
//
//// Tính tiền phải trả cho mỗi khách hàng
//void tinhTienPhaiTra() {
//	for (int i = 0; i < n; i++) {
//		dskh[i].tienPhaiTra = dskh[i].soVeNguoiLon * 40000 + dskh[i].soVeTreEm * 20000;
//	}
//}
//
//// Tính tổng doanh thu
//int tinhTongDoanhThu() {
//	int tongDoanhThu = 0;
//	for (int i = 0; i < n; i++) {
//		tongDoanhThu += dskh[i].tienPhaiTra;
//	}
//	return tongDoanhThu;
//}
//
//// Tính tổng doanh thu của từng phim
//void tinhDoanhThuTungPhim() {
//	int doanhThu[MAX] = { 0 };
//	char phimDaTinh[MAX][100] = { "" };
//	int dem = 0;
//
//	for (int i = 0; i < n; i++) {
//		int daTinh = 0;
//		for (int j = 0; j < dem; j++) {
//			if (strcmp(dskh[i].tenPhim, phimDaTinh[j]) == 0) {
//				daTinh = 1;
//				break;
//			}
//		}
//		if (!daTinh) {
//			for (int k = 0; k < n; k++) {
//				if (strcmp(dskh[i].tenPhim, dskh[k].tenPhim) == 0) {
//					doanhThu[dem] += dskh[k].tienPhaiTra;
//				}
//			}
//			strcpy_s(phimDaTinh[dem], dskh[i].tenPhim);
//			dem++;
//		}
//	}
//
//	printf("Doanh thu tung phim:\n");
//	for (int i = 0; i < dem; i++) {
//		printf("Phim: %s - Doanh thu: %d\n", phimDaTinh[i], doanhThu[i]);
//	}
//}
//
//// Xuất thông tin khách hàng của phòng chiếu x và xuất chiếu y
//void xuatKhachHangTheoPhongVaXuatChieu(const char *phong, const char *xuat) {
//	printf("Danh sach khach hang cua phong %s va xuat chieu %s:\n", phong, xuat);
//	for (int i = 0; i < n; i++) {
//		if (strcmp(dskh[i].phongChieu, phong) == 0 && strcmp(dskh[i].xuatChieu, xuat) == 0) {
//			printf("%s, %s, %d, %d, %s, %s, %s, %d\n",
//				dskh[i].hoTen,
//				dskh[i].soDienThoai,
//				dskh[i].soVeNguoiLon,
//				dskh[i].soVeTreEm,
//				dskh[i].tenPhim,
//				dskh[i].phongChieu,
//				dskh[i].xuatChieu,
//				dskh[i].tienPhaiTra);
//		}
//	}
//}
//
//// Sắp xếp danh sách theo số tiền phải trả tăng dần
//void sapXepTheoTienPhaiTra() {
//	// Ví dụ: Bubble Sort
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (dskh[j].tienPhaiTra > dskh[j + 1].tienPhaiTra) {
//				KhachHang temp = dskh[j];
//				dskh[j] = dskh[j + 1];
//				dskh[j + 1] = temp;
//			}
//		}
//	}
//}
//
//// Sắp xếp danh sách theo họ tên tăng dần
//void sapXepTheoHoTen() {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (strcmp(dskh[i].hoTen, dskh[j].hoTen) > 0) {
//				KhachHang temp = dskh[i];
//				dskh[i] = dskh[j];
//				dskh[j] = temp;
//			}
//		}
//	}
//}
//
//// Tìm khách hàng bằng Binary Search
//int timKhachHangTheoTen(const char *ten) {
//	int left = 0, right = n - 1;
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		int cmp = strcmp(dskh[mid].hoTen, ten);
//		if (cmp == 0) return mid;
//		if (cmp < 0) left = mid + 1;
//		else right = mid - 1;
//	}
//	return -1;
//}
//
//// Hàm main và menu điều khiển
//int main() {
//	docDanhSachKhachHang("dskh.txt");
//	xuatDanhSachKhachHang();
//	tinhTienPhaiTra();
//	xuatDanhSachKhachHang();
//	printf("Tong doanh thu: %d\n", tinhTongDoanhThu());
//	tinhDoanhThuTungPhim();
//
//	char phong[20], xuat[20];
//	printf("Nhap phong chieu: ");
//	scanf_s("%s", phong);
//	printf("Nhap xuat chieu: ");
//	scanf_s("%s", xuat);
//	xuatKhachHangTheoPhongVaXuatChieu(phong, xuat);
//
//	sapXepTheoTienPhaiTra();
//	printf("Danh sach sau khi sap xep theo tien phai tra:\n");
//	xuatDanhSachKhachHang();
//
//	sapXepTheoHoTen();
//	printf("Danh sach sau khi sap xep theo ho ten:\n");
//	xuatDanhSachKhachHang();
//
//	int viTri = timKhachHangTheoTen("Nguyen Van An");
//	if (viTri != -1) {
//		printf("Khach hang 'Nguyen Van An' tai vi tri %d\n", viTri);
//	}
//	else {
//		printf("Khong tim thay khach hang 'Nguyen Van An'\n");
//	}
//
//	return 0;
//}
