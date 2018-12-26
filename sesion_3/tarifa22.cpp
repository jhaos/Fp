/* 
	
	En este ejercicio vamos a aplicar un descuento del 2% y del 4% a un precio de billete utilizando constantes además, 
	también pediremos el precio de billete y el descuento que le vamos a aplicar combinando valores int y double

*/


#include <iostream>

using namespace std;

const double CENTENAR = 100.0;
const int UNIDAD = 1;

int main(){
	double precio;
	int descuento_4, descuento_2;	
	double descuento4_total;
	double descuento2_total;

	cout << "Diga el precio del billete: ";
	cin >> precio;
	cout << "A continuación señale el descuento del 4\% y el descuento del 2\%: ";
	cin >> descuento_4;
	cin >> descuento_2;

	double ind_desc_4 = UNIDAD - descuento_4/CENTENAR;
	double ind_desc_2 = UNIDAD - descuento_2/CENTENAR;

	descuento4_total = precio * ind_desc_4;
	descuento2_total = precio * ind_desc_2;

	cout << "El precio con descuento del 4\%" << " es: " << descuento4_total << endl;
	cout << "El precio con descuento del 2\%" << " es: " << descuento2_total << endl;




	return 0;
}

