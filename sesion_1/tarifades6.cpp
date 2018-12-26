/* 
	
	En este ejercicio vamos a aplicar un descuento del 2% y del 4% a un precio de billete

*/ 

#include <iostream>

using namespace std;

int main(){
	double precio;	
	double descuento4 = 0.04;
	double descuento2 = 0.02;
	double descuento4_total;
	double descuento2_total;

	cout << "Diga el precio del billete: ";
	cin >> precio;

	descuento4_total = precio - precio*descuento4;
	descuento2_total = precio - precio*descuento2;

	cout << "El precio con descuento del 4\%" << " es: " << descuento4_total << endl;
	cout << "El precio con descuento del 2\%" << " es: " << descuento2_total << endl;




	return 0;
}

