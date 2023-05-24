#include <iostream>
using namespace std;
//ogrenci kayıt sistemi

struct node{
	int no;
	string ad;
	string soyad;
	int ort;
	bool durum;
	struct node * next;
};

struct node * ekle(struct node * head, int no, string ad, string soyad, int ort){

	struct node * ogrenci = new node();
	ogrenci->no = no;	
	ogrenci->ad = ad;	
	ogrenci->soyad = soyad;	
	ogrenci->ort = ort;	
	ogrenci->durum = ort >= 50 ? true : false ;	

	if(head == NULL){
		
		head = ogrenci;
		cout << head->no << " numarali ogrenci ilk olarak kayda eklendi"<< endl;
		head->next = NULL;
	}
	else
	{
		ogrenci->next=head;
		head = ogrenci;
	}
	
	return head;
	
}

struct node * bastanSil(struct node * head){
	if(head==NULL){
		cout << "liste boş, herhangi bir ogrenci kaydi yoktur" << endl;
	}
	else
	{
		if(head->next==NULL){
			cout << head->no << " numarali ogrenci listeden silindi"<< endl;
			delete head;
			head = NULL;
		}
		else{
			struct node * temp = head->next;
			delete head;
			head = temp;
			
		}
	}
	return head;
}


struct node * sondanSil(struct node * head){
	if(head==NULL){
		cout << "liste boş, herhangi bir ogrenci kaydi yoktur" << endl;
	}
	else
	{
		if(head->next==NULL){
			cout << head->no << " numarali ogrenci listeden silindi"<< endl;
			delete head;
			head = NULL;
		}
		else{
			struct node * temp = head;
			while(temp->next->next!=NULL){
				temp = temp->next;
			}
			
			cout<<temp->next->no<<" numarali ogrenci listeden silindi"<<endl;
			delete temp->next;
			temp->next=NULL;
			
		}
	}
	return head;
}


struct node * ara(struct node * head, int key){
	system("cls");

	
	bool sonuc = false;
	
	if(head==NULL){
		cout << "liste bos, herhangi bir ogrenci kaydi yoktur" << endl;
	}
	else
	{
		struct node * temp=head;
		while(temp!=NULL){
			if(temp->no==key){
				cout << key << " numarali ogrenci bilgileri: "<< endl;
				cout<<"adi	:"<< temp->ad<<endl;
				cout<<"soyad	:"<< temp->soyad<<endl;
				cout<<"ortalama:"<< temp->ort<<endl;
				cout<<"durum	:"<< temp->durum<<endl;
				
				sonuc = true;
				break;
			}
			temp=temp->next;
		}
		if(!sonuc){
			cout << key << " numarali kayit listede yoktur "<< endl;
		}
		
		
	}
	return head;
}

struct node * bilgileriGetir(struct node * head){
	
	system("cls");
		
	if(head==NULL){
		cout << "liste bos, herhangi bir ogrenci kaydi yoktur" << endl;
	}
	else
	{
		struct node * temp=head;
		while(temp!=NULL){
			cout << temp->no << " numarali ogrencinin adi: "<< temp->ad << ", soyad: "<< temp->soyad << ", ortalamasi: " << temp->ort<<" durum: "<< temp->durum<<endl;
			temp=temp->next;
		}
	}
	return head;
}

int main(){
	int no, ort, sayi, secim;
	string ad, soyad;
	bool durum;
	
	struct node * head =NULL;
	
	while(1){
		cout << "TYDBL Ogrenci Kayit Uygulamasi"<<endl;
		cout<< "1-- yeni kayit"<<endl;
		cout<< "2-- bastan sil"<<endl;
		cout<< "3-- sondan sil"<<endl;
		cout<< "4-- kayit ara"<<endl;
		cout<< "5-- tum bilgileri getir"<<endl;
		cout<< "0-- CIKIS"<<endl;
		cin>>secim;
		switch(secim){
			case 1: cout << " yeni kaydi yapilacak ogrencinin bilgilerini giriniz: "<<endl;
			cout<<"numara	:";cin>>no;
			cout << "ad	:";cin>>ad;
			cout << "soyad	:";cin>>soyad;
			cout << "ortalama:";cin>>ort;
			head = ekle(head, no, ad, soyad, ort);
			break;
			
			case 2: head = bastanSil(head);
			break;
			
			case 3: head= sondanSil(head);
			break;
			
			case 4: cout<<" ogrenci numarasi: "; cin>>no;
			head = ara(head, no);
			break;
			
			case 5: head=bilgileriGetir(head);
			break;
			
			case 0: cout << " programdan cikiliyor...";
			return 0;
			
			default: cout << "hatali secim yaptiniz!!!"<< endl;
			break;
		}
	}
	
}
