#include<iostream>
using namespace std;


class SoPhuc{
	private: 
		double dPhanThuc, dPhanAo;
		public:
			SoPhuc(){
				dPhanThuc = dPhanAo = 0;
			} 
			SoPhuc(double thuc, double ao){
				dPhanThuc = thuc;
				dPhanAo = ao;
			}
			~SoPhuc() {
				
			}
			void Nhap(){
				cout<<"Nhap phan thuc:"; cin>>dPhanThuc;
				cout<<"Nhap phan ao:"; cin>>dPhanAo;
			}
			void Xuat(){
				cout<<dPhanThuc<<" + "<<dPhanAo<<"i"<<endl;
			}
			SoPhuc& Cong(SoPhuc& sp)
			{
				SoPhuc kq;
				kq.dPhanThuc = dPhanThuc + sp.dPhanThuc;
				kq.dPhanAo = dPhanAo + sp.dPhanAo;
				return kq;
			}
			SoPhuc& Tru(SoPhuc& sp)
			{
				SoPhuc kq;
				kq.dPhanThuc = dPhanThuc - sp.dPhanThuc;
				kq.dPhanAo = dPhanAo - sp.dPhanAo;
				return kq;
			}
			SoPhuc& Nhan(SoPhuc& sp) {
				SoPhuc kq;
				kq.dPhanThuc = dPhanThuc * sp.dPhanThuc - dPhanAo * sp.dPhanAo;
				kq.dPhanAo = dPhanThuc * sp.dPhanAo + dPhanAo * sp.dPhanThuc;
			}
			SoPhuc& Chia(SoPhuc& sp ) {
				SoPhuc kq;
				double mauSo = sp.dPhanThuc * sp.dPhanThuc + sp.dPhanAo * sp.dPhanAo;
				kq.dPhanThuc = (dPhanThuc * sp.dPhanThuc + dPhanAo * sp.dPhanAo) / mauSo ;
				kq.dPhanAo = (sp.dPhanThuc * dPhanAo- dPhanThuc * sp.dPhanAo)/ mauSo ;	
			}
};
int main(){
	SoPhuc p1; p1.Nhap();
	SoPhuc p2; p2.Nhap();
	
	SoPhuc tong = p1.Cong(p2) ;tong.Xuat();
	SoPhuc hieu = p1.Tru(p2) ;hieu.Xuat();
	SoPhuc tich = p1.Nhan(p2) ;tich.Xuat();
	SoPhuc thuong = p1.Chia(p2); thuong.Xuat();
	
}
