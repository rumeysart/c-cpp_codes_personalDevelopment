#include <iostream>
using namespace std;

int main()
{
	int sayi;
	cout << "Uc basamakli bir sayi giriniz: "<< endl;
	cin >> sayi;
	int a, b, c;
	if((sayi>=0)&& sayi <= 999){
	
	a = sayi%10;		// birler basamağını verir 
	b = (sayi%100)-a;	// onlar basamağını verir
	c = 100*(sayi/100);	// yüzler basamağını verir
	
	cout << "Yuzler Basamagi: " << c << endl;
	cout << "Onlar Basamagi: " << b << endl;
	cout << "Birler Basamagi: " << a << endl;
}

else
	cout << "Uc basamakli bir sayi girmediniz, lütfen tekrar deneyiniz";


}