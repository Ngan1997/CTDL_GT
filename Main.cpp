#include<iostream>
#include<fstream>
#include"CauTruc.h"
#include"GiaoDien.h"
#include"QuanLyChuyenBay.h"
using namespace std;
int main()
{
	fullscreen();
	KhungNgoai();
	Menu();
	DanhSach_MB mb;
	List cb;
	DocFileMB(mb);
	DocFileCB(cb);
//	cout << cb.pHead->data.SoHieuMB;
//	cout << mb.data[0]->SoHieuMB;
}
