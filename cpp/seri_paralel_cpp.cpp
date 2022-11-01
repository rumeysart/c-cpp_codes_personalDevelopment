#include <iostream>
using namespace std;

int main()
{
	float a, b;
	cout << "Direnc degerlerini giriniz: "<< endl;
	cin >> a;
	cin >> b;
	
	char x;
	cout << "Baglanti tipini girin: "<< endl;
	cin >> x;
	
	float esdeger;
	int z;
	if(x == 's')
	{
		esdeger = a + b;
		cout << "Es deger direnc "<< esdeger << " ohm"<< endl;
	}

	else if(x == 'p')
	{
		esdeger = (a * b) / (a + b);
		cout << "Es deger direnc  "<< esdeger << " ohm"<< endl;
	}
	
	else
		cout << "Baglanma tipini yanlis girdiniz, tekrar deneyiniz" << endl;
	
}