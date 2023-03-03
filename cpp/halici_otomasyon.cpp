#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

/* Rümeysa TATAR, 2112721031 ve halıcı otomasyonu */

/*menü, dosyalanan veriler üzerinde kayıt, arama, düzeltme,
 silme, listeleme ve gerekiyorsa konuyla ilgili hesaplamaları
 yapabilecek fonksiyonlardan oluşmalıdır.
*/

using namespace std;

struct Olcu{
	
	char metre[7];
	char cm[7];
	
};


struct Hali{
	
	Olcu en;
	Olcu boy;
	char renk[50];
	char adet[80];
	char tur[45];	
	char fiyat[10];
	char dikim[80];
	char iplik[80];
	char hali_kod[80];
	char garanti[10];
	
};

Hali hali;
void HaliEkle();
void HaliArama();
void HaliSilme();
void HaliDuzeltme();
void HaliListeleme();

int main(){
	setlocale(LC_ALL, "Turkish");
	
	char secim;
	do{
	
	system("cls");
	
	cout << "----------Hosgeldiniz---------"<< endl;
	
	cout << "|----Lutfen Secim Yapiniz----|"<< endl;
	
	cout << "------------------------------" << endl;

	cout << "1) Hali Ekleme"<< endl;

	cout << "2) Urun Listeleme"<< endl;
	
	cout << "3) Urun Arama"<< endl;

	cout << "4) Urun Silme"<< endl;

	cout << "5) Urun Duzeltme"<< endl;


	
	cout << "------------------------------"<< endl;

		cout << "Secimi Giriniz:" << endl;
secim=getche();

switch(secim){
	case '1':
		{
			HaliEkle();
			break;
		}
	case '2':
		{
			HaliListeleme();
			break;
		}
	case '3':
		{
			HaliArama();
			break;
		}
	case '4':
		{
			HaliSilme();
			break;
		}
	case '5':
		{
			HaliDuzeltme();
			break;
		}
}	
cout << endl;
		cout << "Ana Menuye Donmek Ister misin (e/h)";
		secim = getche();
}while(secim=='e' || secim == 'E');

	
	
	
	
	
	
	
return 0;	
}


void HaliEkle()
{
	
	ofstream yaz("hali.dat", ios::binary | ios::app);
	char secim;
	
	do{
		cout << "\nHali Cesidini Giriniz: "<< endl;
		cin >>hali.tur;
		cout << "Bu Halinin Adedini Giriniz: "<< endl;
		cin >> hali.adet;
		cout << "Halinin Dikim Turunu Giriniz: "<< endl;
		cin >> hali.dikim;
		cout << "Halinin Kodunu Giriniz: " << endl;
		cin >> hali.hali_kod;
		cout << "Hali Iplik Turunu Giriniz: "<< endl;
		cin >> hali.iplik;
		cout << "Halinin Rengini Giriniz: " << endl;
		cin >> hali.renk;
		cout << "Halinin enini once metre sonra santimetre olarak ayri ayri giriniz: "<< endl;
		cin>> hali.en.metre;
		cin >> hali.en.cm;
		cout << "Halinin boyunu once metre sonra santimetre olarak ayri ayri giriniz: "<< endl;
		cin>> hali.boy.metre;
		cin >> hali.boy.cm;
		cout << "Halinin Adet Fiyatini Giriniz: "<< endl;
		cin >> hali.fiyat;
		cout << "Halinin Garanti Suresi(ay): " << endl;
		cin >> hali.garanti;
		
		yaz.write((char*)&hali,sizeof(hali));
		
		
		
	cout << "\n Hali Eklemek Ister Misiniz (e/h)";	
	secim = getche();
	}while(secim == 'e' || secim == 'E');
	
	yaz.close();	
	
	
}

void HaliListeleme(){
	ifstream oku("hali.dat", ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	
	int kayits =oku.tellg()/sizeof(hali);	//tellg toplam byteı söylüyor
	
	cout << "\nToplam Hali Kayit Sayisi: " << kayits << endl;
	
	if(kayits>0){
		for(int i = 0; i< kayits ; i++){
			
			oku.seekg(i*sizeof(hali));

			oku.read((char*)&hali, sizeof(hali));
			cout << endl;
			
			cout << i+1 << 	". Halinin Bilgileri"<< endl;
			cout << "Halinin Cesidi: " << hali.tur<<endl;
			cout << "Halinin Kodu: " << hali.hali_kod<< endl;
			cout << "Halinin Dikim Turu: " << hali.dikim<<endl;
			cout << "Bu Halinin Sayisi: " << hali.adet << endl;
			cout << "Halinin Iplik Turu: " << hali.iplik<<endl;
			cout << "Halinin Rengi: " << hali.renk<<endl;
			cout << "Halinin Eni: " << hali.en.metre<< " metre "<< hali.en.cm << " santimetre"<<endl;
			cout << "Halinin Boyu: " << hali.boy.metre << " metre "<< hali.boy.cm << " santimetre"<<endl;
			cout << "Halinin Fiyati: "<< hali.fiyat << endl;
			cout << "Halinin Garanti Suresi: " << hali.garanti << endl;


			cout << "---------------" << endl;
		}
		oku.close();
		
		
	}
	else
		cout << "Kayit Bulunamadi"<< endl;
	
	
	
}


void HaliArama(){
	ifstream oku("hali.dat", ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	
	int kayits =oku.tellg()/sizeof(hali);	//tellg toplam byteı söylüyor
	char halikod[20];
	
	cout << "\nAranacak halinin numarasini giriniz: " << endl;
	cin >> halikod;
	
	if(kayits>0){
		for(int i = 0; i< kayits ; i++){
			oku.seekg(i*sizeof(hali));
			oku.read((char*)&hali, sizeof(hali));
			cout << endl;
	
			
			if(strcmp(hali.hali_kod,halikod)==0){
			
			cout << "Bulunan Halinin Bilgileri"<< endl;
			cout << "Halinin Cesidi: " << hali.tur<<endl;
			cout << "Halinin Kodu: "<< hali.hali_kod<< endl;
			cout << "Halinin Dikim Turu: " << hali.dikim<<endl;
			cout << "Bu Halinin Sayisi: " << hali.adet << endl;
			cout << "Halinin Iplik Turu: " << hali.iplik<<endl;
			cout << "Halinin Rengi: " << hali.renk<<endl;
			cout << "Halinin Eni: " << hali.en.metre<< " metre "<< hali.en.cm << " santimetre"<<endl;
			cout << "Halinin Boyu: " << hali.boy.metre << " metre "<< hali.boy.cm << " santimetre"<<endl;
			cout << "Halinin Fiyati: "<< hali.fiyat << endl;
			cout << "Halinin Garanti Suresi: "<< hali.garanti<< endl;


			cout << "---------------" << endl;
		}
		
		}
		oku.close();
		
		
	}
	else
		cout << "Kayit Bulunamadi"<< endl;
	
	
	
}

void HaliSilme(){
	
	ifstream oku("hali.dat", ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	
	int kayits =oku.tellg()/sizeof(hali);	//tellg toplam byteı söylüyor
	char halikod[20];
	char secim;
	
	cout << "\nSilinecek halinin numarasini giriniz: " << endl;
	cin >> halikod;
	bool var = false;
	
	if(kayits>0){
		for(int i = 0; i< kayits ; i++){
			oku.seekg(i*sizeof(hali));
			oku.read((char*)&hali, sizeof(hali));
			cout << endl;
	
			
			if(strcmp(hali.hali_kod,halikod)==0){
			
			cout << "Silinecek Halinin Bilgileri"<< endl;
			cout << "Halinin Cesidi: " << hali.tur<<endl;
			cout << "Halinin Kodu: "<< hali.hali_kod<< endl;
			cout << "Halinin Dikim Turu: " << hali.dikim<<endl;
			cout << "Bu Halinin Sayisi: " << hali.adet << endl;
			cout << "Halinin Iplik Turu: " << hali.iplik<<endl;
			cout << "Halinin Rengi: " << hali.renk<<endl;
			cout << "Halinin Eni: " << hali.en.metre<< " metre "<< hali.en.cm << " santimetre"<<endl;
			cout << "Halinin Boyu: " << hali.boy.metre << " metre "<< hali.boy.cm << " santimetre"<<endl;
			cout << "Halinin Fiyati: "<< hali.fiyat << endl;
			cout << "Halinin Garanti Suresi: " << hali.garanti << endl;
			cout << "---------------" << endl;
			cout << "Silinecek Hali Bu Mu? e/h"<< endl;
			
			secim = getche();
			if(secim == 'h'|| secim == 'H'){
			
			ofstream y_yaz("Yedek.dat", ios::app | ios::binary);
			
			y_yaz.write((char*)&hali,sizeof(hali));
			y_yaz.close();
			}

		
			
			else if(secim == 'E' || secim == 'e'){
				var = true;
			}	
		}
		
		else{
			//Silinmeyecek Halılar
			
			ofstream y_yaz("Yedek.dat", ios::app | ios::binary);
			
			y_yaz.write((char*)&hali,sizeof(hali));
			y_yaz.close();
		}
		
		}	
		oku.close();
		if(var){
			remove("hali.dat");
			rename("Yedek.dat", "hali.dat");
			cout << "\nKayit Silindi"<< endl;
			
		}
		else{
			remove("Yedek.dat");
			cout << "Kayit Bulunamadi"<< endl;
		}
	}
	else
		cout << "Kayit Bulunamadi"<< endl;
}

void HaliDuzeltme(){
	
	ifstream oku("hali.dat", ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	
	int kayits =oku.tellg()/sizeof(hali);	//tellg toplam byteı söylüyor
	char halikod[20];
	char secim;
	
	cout << "\nDuzeltilecek halinin numarasini giriniz: " << endl;
	cin >> halikod;
	bool var = false;
	
	if(kayits>0){
		for(int i = 0; i< kayits ; i++){
			oku.seekg(i*sizeof(hali));
			oku.read((char*)&hali, sizeof(hali));
			cout << endl;
	
			
			if(strcmp(hali.hali_kod,halikod)==0){
			
			cout << "Duzeltilecek Halinin Bilgileri"<< endl;
			cout << "Halinin Cesidi: " << hali.tur<<endl;
			cout << "Halinin Kodu: "<< hali.hali_kod<< endl;
			cout << "Halinin Dikim Turu: " << hali.dikim<<endl;
			cout << "Bu Halinin Sayisi: " << hali.adet << endl;
			cout << "Halinin Iplik Turu: " << hali.iplik<<endl;
			cout << "Halinin Rengi: " << hali.renk<<endl;
			cout << "Halinin Eni: " << hali.en.metre<< " metre "<< hali.en.cm << " santimetre"<<endl;
			cout << "Halinin Boyu: " << hali.boy.metre << " metre "<< hali.boy.cm << " santimetre"<<endl;
			cout << "Halinin Fiyati: "<< hali.fiyat << endl;
			cout << "Halinin Garanti Suresi: " << hali.garanti << endl;
			cout << "---------------" << endl;
			cout << "Duzeltilecek Ogrenci Bu Mu? e/h"<< endl;
			
			secim = getche();
			if(secim == 'h'|| secim == 'H'){
			
			ofstream y_yaz("Yedek.dat", ios::app | ios::binary);
			
			y_yaz.write((char*)&hali,sizeof(hali));
			y_yaz.close();
			}

		
			
			else if(secim == 'E' || secim == 'e'){
				var = true;
				
				ofstream y_yaz("Yedek.dat", ios::app | ios::binary);
				
					cout << "\nHali Cesidini Giriniz: "<< endl;
					cin >>hali.tur;
					cout << "Bu Halinin Adedini Giriniz: "<< endl;
					cin >> hali.adet;
					cout << "Halinin Dikim Turunu Giriniz: "<< endl;
					cin >> hali.dikim;
					cout << "Halinin Kodunu Giriniz: " << endl;
					cin >> hali.hali_kod;
					cout << "Hali Iplik Turunu Giriniz: "<< endl;
					cin >> hali.iplik;
					cout << "Halinin Rengini Giriniz: " << endl;
					cin >> hali.renk;
					cout << "Halinin enini once metre sonra santimetre olarak ayri ayri giriniz: "<< endl;
					cin>> hali.en.metre;
					cin >> hali.en.cm;
					cout << "Halinin boyunu once metre sonra santimetre olarak ayri ayri giriniz: "<< endl;
					cin>> hali.boy.metre;
					cin >> hali.boy.cm;
					cout << "Halinin Adet Fiyatini Giriniz: "<< endl;
					cin >> hali.fiyat;
					cout << "Halinin Garanti Suresi: " <<  endl;
					cin >> hali.garanti;
					
				y_yaz.write((char*)&hali,sizeof(hali));
				y_yaz.close();
			}	
		}
		
		else{
			//Duzeltilecek Olan Halilar
			
			ofstream y_yaz("Yedek.dat", ios::app | ios::binary);
			
			y_yaz.write((char*)&hali,sizeof(hali));
			y_yaz.close();
		}
		
		}	
		oku.close();
		if(var){
			remove("hali.dat");
			rename("Yedek.dat", "hali.dat");
			cout << "Kayit Duzeltildi"<< endl;
			
		}
		else{
			remove("Yedek.dat");
			cout << "Kayit Bulunamadi"<< endl;
		}
	}
	else
		cout << "Kayit Bulunamadi"<< endl;
}







