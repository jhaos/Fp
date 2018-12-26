/* 
	
	En este ejercicio vamos a aplicar un descuento del 2% y del 4% a un precio de billete utilizando constantes

*/ 

#include <iostream>

using namespace std;

const double IND_DESC_4 = 1 - 4.0/100.0;
const double IND_DESC_2 = 1 - 2.0/100.0;

int main(){
	double precio;	
	double descuento4_total;
	double descuento2_total;

	cout << "Diga el precio del billete: ";
	cin >> precio;

	descuento4_total = precio * IND_DESC_4;
	descuento2_total = precio * IND_DESC_2;

	cout << "El precio con descuento del 4\%" << " es: " << descuento4_total << endl;
	cout << "El precio con descuento del 2\%" << " es: " << descuento2_total << endl;




	return 0;
}

