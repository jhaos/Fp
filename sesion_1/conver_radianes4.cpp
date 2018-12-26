/*

	Convertir de grados a radianes

*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double grado1;
	double grado2;
	double pi = 3.14159;
	double radianes1;
	double radianes2;
	
	cout << "Introduce el valor del primer grado: ";
	cin >> grado1;
	cout << "Introduce el valor del segundo grado: ";
	cin >> grado2;
	
	radianes1 = grado1 * (pi / 180);
	radianes2 = grado2 * (pi / 180);
	
	cout << "La transformación en radianes del primer grado introducido es : " << radianes1 << endl;
	cout << "La transformación en radianes del primer grado introducido es : " << radianes2 << endl;
	
	
	
	
	return 0;	
}
