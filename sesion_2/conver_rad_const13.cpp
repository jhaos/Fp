/*

	Conversión de grados a radianes usando constantes

*/
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 6 * asin(0.5);
const double TO_RADIANES = PI / 180;

int main(){
	double grado1;
	double grado2;
	double radianes1;
	double radianes2;
	
	cout << "Introduce el valor del primer grado: ";
	cin >> grado1;
	cout << "Introduce el valor del segundo grado: ";
	cin >> grado2;
	
	radianes1 = grado1 * TO_RADIANES;
	radianes2 = grado2 * TO_RADIANES;
	
	cout << "La transformación en radianes del primer grado introducido es : " << radianes1 << endl;
	cout << "La transformación en radianes del primer grado introducido es : " << radianes2 << endl;
	
	
	
	
	return 0;	
}
