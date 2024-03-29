#include <iostream>
#include <algorithm>
using namespace std;
class PhanSo{
	private:
		int iTuSo;
		int iMauSo;
	public:
		PhanSo();
		PhanSo( int, int );
		~PhanSo();
		void Nhap();
		void Xuat();
		void ToiGian();
		PhanSo& Cong(PhanSo& );
		PhanSo& Tru(PhanSo& );
		PhanSo& Nhan(PhanSo& );
		PhanSo& Chia(PhanSo& );
};
PhanSo::PhanSo() {
	iTuSo = 0; 
	iMauSo = 1;
}
PhanSo::PhanSo(int tu, int mau) {
	iTuSo = tu;
	if( mau == 0 )
		iMauSo = 1;
	else 
		iMauSo = mau;
} 
PhanSo::~PhanSo(){
	
}

void PhanSo::Nhap(){
	cout<<"Nhap tu so: "; cin>>iTuSo;
	cout<<"Nhap mau so:"; cin>>iMauSo;
	while(iMauSo == 0 ) {
		cout<<"Nhap lai mau so khac 0:"; cin>>iMauSo;
	}
}
void PhanSo::Xuat() {
	cout<<iTuSo<<"/"<<iMauSo<<endl;
}
void PhanSo::ToiGian()
{
	int UCLN = __gcd(iMauSo, iTuSo);
	iMauSo /= UCLN;
	iTuSo /= UCLN;
	if (iMauSo < 0) iMauSo = -iMauSo, iTuSo = -iTuSo;
	if(iTuSo == 0) iMauSo = 1;
}
PhanSo& PhanSo::Cong(PhanSo& ps) {
	PhanSo ketqua;
	ketqua.iTuSo = iTuSo * ps.iMauSo + iMauSo * ps.iTuSo;
	ketqua.iMauSo = iMauSo * ps.iMauSo;
	ketqua.ToiGian();
	return ketqua;
}
PhanSo& PhanSo::Tru(PhanSo& ps) {
	PhanSo ketqua;
	ketqua.iTuSo = iTuSo * ps.iMauSo - iMauSo * ps.iTuSo;
	ketqua.iMauSo = iMauSo * ps.iMauSo;
	ketqua.ToiGian();
	return ketqua;
}
PhanSo& PhanSo::Nhan(PhanSo& ps) {
	PhanSo ketqua;
	ketqua.iTuSo = iTuSo * ps.iTuSo;
	ketqua.iMauSo = iMauSo * ps.iMauSo;
	ketqua.ToiGian();
	return ketqua;
}
PhanSo& PhanSo::Chia(PhanSo& ps) {
	PhanSo ketqua;
	ketqua.iTuSo = iTuSo * ps.iMauSo;
	ketqua.iMauSo = iMauSo * ps.iTuSo;
	ketqua.ToiGian();
	return ketqua;
}

int main(){
	PhanSo ps1;   ps1.Nhap();
	PhanSo ps2;   ps2.Nhap();
	PhanSo tong = ps1.Cong(ps2); tong.Xuat();
	PhanSo hieu = ps1.Tru(ps2); hieu.Xuat();
	PhanSo tich = ps1.Nhan(ps2); tich.Xuat();
	PhanSo thuong = ps1.Chia(ps2); thuong.Xuat();
	
	return 0 ;
}
