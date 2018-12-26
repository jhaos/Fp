/*

	En este programa pedimos una letra mayúsucula y su equivalencia en número a partir del número 0
	
*/

#include <iostream>

using namespace std;

const int INTERVALO = 65;
int main(){

	char mayuscula;
	int transformar;

	cout << "Introduzca una mayscula: " << endl;
	cin >> mayuscula;

	transformar = mayuscula - INTERVALO;

	cout << transformar << endl;



}