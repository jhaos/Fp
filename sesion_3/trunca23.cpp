/*

	En este programa pediremos un real que deberemos truncar a partir de un entero combinando valores int y double

*/

#include <iostream>
#include <cmath>

using namespace std;

const double REAL = 1.0;

int main(){
	double real;
	int entero;
	int cuadrado;
	int multiplicacion;
	double resultado;

	cout << "Indica el número real a truncar: ";
	cin >> real;
	cout << "Indica el truncador: ";
	cin >> entero;

	cuadrado = pow(10, entero);
	cout<<cuadrado<<endl;

	multiplicacion = real * cuadrado;
	resultado = multiplicacion / (cuadrado*REAL);

	cout << "El valor final del real truncado es: " << resultado << endl;





}