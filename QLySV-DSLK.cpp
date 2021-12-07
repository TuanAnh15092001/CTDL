#include "conio.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 1000
//cau truc du lieu
struct DATE{
	int ngay, thang, nam;
};
struct SINHVIEN{
	DATE ngaysinh;
	float diemtb;
	char mssv[11], holot[51], ten[16];
};
//nhap 1 danh sach cac sinh vien co toi da 30 sv
void Nhap1SV(SINHVIEN &s);
void Xuat1SV(SINHVIEN s);
void NhapDSSV(SINHVIEN dssv[], int &n);
void XuatDSSV(SINHVIEN dssv[], int n);
void Menu();
void Process();

int TimSinhVien(SINHVIEN dssv[], int n, char tentk[]);
//tra ve vi tri tim thay sv co ten trung voi tentk, neu ko tim thay
//tra ve -1
int TimSV_Thang(SINHVIEN dssv[], int n, int thang);
//tra ve vi tri tim thay sv đau tien co thang sinh nhat la 
//tham so thang, //neu ko tim thay tra ve -1
void XuatSVCoDiemTBLonNhat(SINHVIEN dssv[], int n);
//xuat thong tin cua cac sinh vien co diem trung binh lon nhat

//ham main
//void main()
int main()
{
    Process();
    return 0;
}
//viet đinh nghia ham con
int TimSinhVien(SINHVIEN dssv[], int n, char tentk[])
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(dssv[i].ten, tentk) == 0)
		{
			return i;
		}
	}
	return -1;
}
//**************************************************************
int TimSV_Thang(SINHVIEN dssv[], int n, int thang)
{
	for (int i = 0; i < n; i++)
	{
		if (dssv[i].ngaysinh.thang == thang)
			return i;
	}

	return -1;
}
//**************************************************************
void Nhap1SV(SINHVIEN &s)
{
    printf("Nhap ma so sinh vien: ");
	fflush(stdin);
	gets(s.mssv);
    printf("Nhap ho va ten lot sinh vien: ");
	fflush(stdin);
	gets(s.holot);
    printf("Nhap ten sinh vien: ");
	fflush(stdin);
	gets(s.ten);
    printf("Nhap ngay sinh: ");
    scanf("%d", &s.ngaysinh.ngay);
    printf("Nhap thang sinh: ");
    scanf("%d", &s.ngaysinh.thang);
    printf("Nhap nam sinh: ");
    scanf("%d", &s.ngaysinh.nam);
    printf("Nhap diem tb: ");
    scanf("%f", &s.diemtb);
}
//**************************************************************
void Xuat1SV(SINHVIEN s)
{
    printf("%-15s%-25s%-10s%10d/%d/%d%20.2f", s.mssv, s.holot, s.ten, s.ngaysinh.ngay, s.ngaysinh.thang, s.ngaysinh.nam, s.diemtb);
}
//**************************************************************
void NhapDSSV(SINHVIEN dssv[], int &n)
{
    do
	{
        printf("Ban hay cho biet so luong sinh vien: ");
		scanf("%d", &n);
	} while (n < 0);
    for (int i = 0; i < n; i++)
	{
        printf("***********************************\n");
        printf("Nhap thong tin sinh vien %d\n", i + 1);
        Nhap1SV(dssv[i]);
	}
}
//**************************************************************
void XuatDSSV(SINHVIEN dssv[], int n)
{
    printf("\n%-5s%-15s%-24s%-19s%-25s%s", "STT", "MA SO SV", "HO VA TEN LOT", "TEN", "NGAY SINH", "DIEM TB");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-5d", i + 1);
		Xuat1SV(dssv[i]);
	}
}
//**************************************************************
float KTraSVCoDiemTBLonNhat(SINHVIEN dssv[], int &n)
{
    float max = dssv[0].diemtb;
    for (int i = 1; i < n; i++)
    {
        if (dssv[i].diemtb > max)
        {
            max = dssv[i].diemtb;
        }
    }
    return max;
}
//**************************************************************
void XuatSVCoDiemTBLonNhat(SINHVIEN dssv[], int n)
{
    printf("Nhung Sinh Vien co diem trung binh lon nhat:");
    printf("\n%-15s%-24s%-19s%-25s%s", "MA SO SV", "HO VA TEN LOT", "TEN", "NGAY SINH", "DIEM TB");
    for (int i = 0; i < n; i++)
    {
        if (dssv[i].diemtb == KTraSVCoDiemTBLonNhat(dssv, n))
        {
            printf("\n ");
            Xuat1SV(dssv[i]);
        } 
    }
}
//**************************************************************
void Menu()
{
    printf("\n***************************************************");
	printf("\n*                       MENU                      *");
	printf("\n***************************************************");
    printf("\n* 1. Nhap danh sach sinh vien                     *");
	printf("\n* 2. Xuat danh sach sinh vien                     *");
    printf("\n* 3. Tim sinh vien theo thang                     *");
    printf("\n* 4. Tim sinh vien theo ten                       *");
    printf("\n* 5. Tim sinh vien diem tb cao I                  *");
    printf("\n* 0. Thoat chuong trinh                           *");
	printf("\n***************************************************");
}
//**************************************************************
void Process()
{
    SINHVIEN DSSV[MAX];
    char TENTK[MAX];
    int N;
    int THANG;
    int LuaChon;
    do
    {
        Menu();
        printf("\nBan hay lua chon mot chuc nang: ");
		scanf("%d", &LuaChon);
        switch (LuaChon)
        {
        case 1:
            NhapDSSV(DSSV, N);
            break;
        case 2:
            XuatDSSV(DSSV, N);
            break;
        case 3:
            printf("\nNhap Thang can Tim: ");
            scanf("%d", &THANG);
            printf("Vi tri sinh vien dau tien sinh vao thang %d la: %d", THANG, TimSV_Thang(DSSV, N, THANG));
            break;
        case 4:
            printf("Nhap ten sinh vien can tim: ");
            fflush(stdin);
            gets(TENTK);
            printf("Vi tri sinh vien dau tien ten %s la: %d", TENTK, TimSinhVien(DSSV, N, TENTK));
            break;
        case 5:
            XuatSVCoDiemTBLonNhat(DSSV, N);
            break;
        default:
            break;
        }
    } while (LuaChon != 0);
}
//**************************************************************
//**************************************************************