/*

	Cálculo de la aproximación de PI usando Wallis

*/


#include <iostream>
#include <cmath>
using namespace std;

const int COTA_MAXIMA = 100000;
const int COTA_MINIMA = 0;
const int POR_DOS = 2;

int main(){

	cout.precision(15);
	double numerador = 2.0, denominador = 1.0;
	double total = POR_DOS; //
	bool es_denominador_dos_mas = denominador < numerador;
	int tope, contador = 0;
	double num_anterior;


	do{

	cout << "Diga el número tope de la aproximación ";
	cin >> tope; 

	}while (tope < COTA_MINIMA || tope > COTA_MAXIMA);

	for (int i = 0; i < tope; i++){

		total = total * (numerador/denominador);
		num_anterior = numerador;
		numerador = denominador + 1;
		denominador = num_anterior + 1;
	}

	cout << total << endl;
	
}