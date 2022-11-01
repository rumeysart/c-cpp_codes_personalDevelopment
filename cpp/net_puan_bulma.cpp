#include <iostream>

#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	
	
	float td, tb, ty;
	
	//TÜRKÇE
	cout << "Türkçe'deki doğru sayısını girin: "<<endl;
	cin>> td;
	cout << "Türkçe'deki yanlış sayısını girin: "<< endl;
	cin >> ty;
	cout << "Türkçede boş bıraktığınız soru sayısını giriniz: " << endl;
	cin >> tb;

float tn;
float tp;	
if((td+ty+tb) == 25)
	{
	
	tp;	//türkçe puanı
	tp = 2*(td - (ty/4));
	tn = td-(ty/4);
}
else
	cout << "Tüekçe için eksik veya fazla soru sayısı girdiniz"<< endl;




float md, mb, my, mn;
float mp;
	//MATEMATİK 
	cout << "Matematik'teki doğru sayısını girin: "<<endl;
	cin>> md;
	cout << "Matematik'teki yanlış sayısını girin: "<< endl;
	cin >> my;
	cout << "Matematikte boş bıraktığınız soru sayısını giriniz: " << endl;
	cin >> mb;
	
	if((md+my+mb)== 25){
	mp = 5*(md-(my/4));
	mn = md-(my/4);
}
else
	cout << "Matematik için yanlış değerler girdiniz"<< endl;


float fd, fb, fy, fn;
float fp;

	//Fen 
	cout << "Fen'deki doğru sayısını girin: "<<endl;
	cin>> fd;
	cout << "Fen'deki yanlış sayısını girin: "<< endl;
	cin >> fy;
	cout << "Fendeki boş sayısını giriniz: "<< endl;
	cin >> fb;
	
if((fy+fd+fb)==25){

	fp = 4*(fd-(fy/4));
	fn = fd-(fy/4);
}
else
	cout << "Fen Bilgisi için yanlış değerler girdiniz"<< endl;

//TOPLAM
	cout << "Türkçe net: " << tn << "\n Türkçe puanınız: " << tp <<endl;
	cout << "Matematik netiniz: " << mn << "\n Matematik puanınız: " << mp << endl;
	cout << "Fen Bilgisi netiniz: " << fn << "\n Fen Bilgisi puanınız: " << fn << endl << endl;
	
	cout << "Toplam puanınız: " << fp+tp+mp<< "\n Toplam netiniz: " << fn+tn+mn;
	
	
}