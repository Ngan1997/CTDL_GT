#pragma once
#define MAXLIST 300
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Date
{
	
	int Ngay;
	int Thang;
	int Nam;
	int Gio;
};

struct MayBay
{
	string SoHieuMB;
	string LoaiMayBay;
	int SoDay;
	int SoDong;
};
struct DanhSach_MB
{
	MayBay* data[MAXLIST];
	int SoLuong;
};

struct DanhSachVe
{
	string CMND;
	string MaVe;
};
struct ChuyenBay
{
	string MaCB;
	Date NgayKhoiHanh;
	string SanBayDen;
	string SoHieuMB;
	int TrangThai;//0:huy chuyen,1:con ve ,2:het ve ,3:hoan tat
	DanhSachVe* data;
};
struct DanhSach_CB
{
	ChuyenBay data;
	DanhSach_CB* pNext=NULL;
};
struct List
{
	DanhSach_CB* pHead=NULL;
	DanhSach_CB* pTail=NULL;
};

struct HanhKhach
{
	string CMND;
	string Ho;
	string Ten;
	bool Phai;
};
struct NODE_TREE
{
	HanhKhach data;
	NODE_TREE* pLeft = NULL;
	NODE_TREE* pRight =NULL;
};
typedef NODE_TREE* TREE;

void Them1ChuyenBayVao_Cuoi_DanhSach(List &dscb ,DanhSach_CB *cb)
{    // neu danh sach rong 
    if(dscb.pHead == NULL && dscb.pTail == NULL)
    {
    		dscb.pHead = new DanhSach_CB;
    		dscb.pTail = new DanhSach_CB;
    	    dscb.pHead = cb; // node dau cung chinh la node cuoi va la node cb
    	    dscb.pTail = cb;
//		  	cout << cb->data.SoHieuMB;
	}
	else 
	{
		dscb.pTail->pNext = new DanhSach_CB;
		dscb.pTail->pNext= cb;// cho con tro pTail lien ket den node cb
     	dscb.pTail = cb;// cap nhat lai cb la node pTail
	}
     
} /*
int ChuoiThanhSo(string a)
{
	int so = 0;
	for (int i = 0; i < a.length(); i++)
	{
		so = so*10 + a[i]-48;
	}
	return so;
}
*/
// ham doc file cua May Bay 
void DocFileMB(DanhSach_MB &mb)
{
	int dem = 0;
	ifstream filein;
	filein.open("Danhsachmaybay.txt");
	filein >> mb.SoLuong;
	while (!filein.eof())
	{
		mb.data[dem] = new MayBay;
		filein >> mb.data[dem]->SoHieuMB;
		filein >> mb.data[dem]->LoaiMayBay;
		filein >> mb.data[dem]->SoDay;
		filein >> mb.data[dem]->SoDong;
		dem++;
	}
}
void DocFileCB(List & cb)
{
	ifstream filein;
	filein.open("Danhsachchuyenbay.txt");
	string tam;
	DanhSach_CB *temp;
	while (!filein.eof())
	{
		temp = NULL;
		temp = new DanhSach_CB;
//		cout << temp << " ";
		filein >> temp->data.MaCB;
//		cout << (temp->data.MaCB) << " ";
		filein >> temp->data.NgayKhoiHanh.Ngay;
		filein >> temp->data.NgayKhoiHanh.Thang;
		filein >> temp->data.NgayKhoiHanh.Nam;
		filein >> temp->data.NgayKhoiHanh.Gio;
		filein >> temp->data.SanBayDen;
		filein >> temp->data.SoHieuMB;
//		cout << temp->data.SoHieuMB << " ";
//		cout << temp->data.SanBayDen;
		filein >> temp->data.TrangThai;
//		cout << temp->data.TrangThai << " ";
		Them1ChuyenBayVao_Cuoi_DanhSach(cb,temp);
	}
}

