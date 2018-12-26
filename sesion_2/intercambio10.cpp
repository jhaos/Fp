/*

	En este programa se va a realizar un intercambio entre dos variables de entrada

*/


#include <iostream>

using namespace std;

int main(){
	double caja_izda;
	double caja_dcha;
	double apoyo;					// variable de apoyo para realizar el intercambio

	cout << "Introduzca el valor de la caza de la izquierda: ";
	cin >> caja_izda;
	cout << "Introduzca el valor de la caza de la derecha: ";
	cin >> caja_dcha;

	apoyo = caja_dcha;
	caja_dcha = caja_izda;
	caja_izda = apoyo;

	cout << "El valor de la caja izquierda ahora es: " << caja_izda << endl;
	cout << "El valor de la caja derecha ahora es: " << caja_dcha << endl;



	return 0;
}