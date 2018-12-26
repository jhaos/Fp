/*

	En este programa se va a redondear numeros decimales según indicación del usuario


*/


#include <iostream>
#include <cmath>

using namespace std;


int main(){
	double numero;
	int decimal;
	int elevar;
	double elevado;
	double redondeado;

	cout << "Indique el numero decimal a redondear: ";
	cin >> numero;
	cout << "Dime que decimal hay que redondear: ";
	cin >> decimal;

	elevar = pow(10, decimal);
	elevado = round(numero * elevar);
	redondeado = elevado / elevar;

	cout << "El numero redondeado es: " << redondeado << endl;

	return 0;
}