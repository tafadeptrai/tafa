#include <iostream>
using namespace std;
class Candidate {
	
	private: 
		string sMa, sTen, sNgaySinh;
		float fDiemToan, fDiemVan, fDiemAnh;
	public:
		Candidate();
		Candidate(string , string, string, float, float, float);
		~Candidate();
		void Nhap();
		void Xuat();
		float LayTongDiem();
		
};

class TestCandidate {
	public:
		void NhapDanhSach( int, Candidate[]);
		void XuatDanhSach( int, Candidate[]);
};
//dung ham getline de lay chuoi, khong dung cin

Candidate::Candidate() {
	
}
Candidate::Candidate(string ma , string ten, string ns , float toan, float van, float anh){
	sMa = ma;			sTen = ten; 		sNgaySinh = ns;
	fDiemToan = toan; 	fDiemVan = van;		fDiemAnh = anh;
}
Candidate::~Candidate(){
	
}
void Candidate::Nhap() {
	cout<<"Ma so thi sinh:"; getline(cin, sMa);
	cout<<"Ho va ten:"; getline(cin, sTen);
	cout<<"Ngay Sinh:"; getline(cin, sNgaySinh);
	
	cout<<"Diem mon Toan:"; cin>>fDiemToan;
	while(fDiemToan < 0 || fDiemToan > 10){
		cout<<"Nhap lai diem mon toan:" ;cin>>fDiemToan;
	}
	
	cout<<"Diem mon Van:"; cin>>fDiemVan;
	while(fDiemVan < 0 || fDiemVan > 10){
		cout<<"Nhap lai diem mon Van:" ;cin>>fDiemVan;
	}

	cout<<"Diem mon Anh:"; cin>>fDiemAnh;
	while(fDiemAnh < 0 || fDiemAnh > 10){
		cout<<"Nhap lai diem mon Anh:" ;cin>>fDiemAnh;
	}
}
float Candidate::LayTongDiem() {
	return fDiemToan + fDiemVan + fDiemAnh;
}

void Candidate::Xuat() {
	cout<<"Ma so thi sinh:"<<sMa<<endl;
	cout<<"Ho va ten     :"<<sTen<<endl;
	cout<<"Ngay Sinh     :"<<sNgaySinh<<endl;
	cout<<"Diem mon Toan :"<<fDiemToan<<endl;
	cout<<"Diem mon Van  :"<<fDiemVan<<endl;	
	cout<<"Diem mon Anh  :"<<fDiemAnh<<endl;
	cout<<"Tong Diem     :"<<LayTongDiem()<<endl;
	
}
void TestCandidate::NhapDanhSach(int n, Candidate ds[]) {
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap thi sinh thu"<<i + 1<<endl;
		cin.ignore();
		ds[i].Nhap();
	}
}
void TestCandidate::XuatDanhSach(int n, Candidate ds[]) {
	cout<<"Danh sach thi sinh tren 15 diem:"<<endl;
		for( int i = 0 ; i < n ; i++){
			if(ds[i].LayTongDiem() > 15){
				ds[i].Xuat();
			}
		}
	}
int main() {
	Candidate *ts;
	TestCandidate test;
	int n;
	cout<<"so luong thi sinh can nhap:" ; cin>>n;
	ts = new Candidate[n];
	test.NhapDanhSach(n, ts);
	test.XuatDanhSach(n, ts);
}
