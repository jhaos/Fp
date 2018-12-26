/*

	Cálculo de la aproximación de PI, con errores logicos. Revisar con profesor

*/


#include <iostream>
#include <cmath>
using namespace std;

const int COTA_MAXIMA = 100000;
const int COTA_MINIMA = 0;
const int POR_PI_PARTIDO = 6;

int main(){

	cout.precision(15);
	double numerador = 2.0, denominador = 1.0;
	double total_positivo = 0, total_negativo = 0, total_exponente = 1; //
	bool es_denominador_dos_mas = denominador < numerador;
	int tope, contador = 0;
	double num_anterior;
	double formula_positiva, formula_negativa, formula_exponente;
	double total = 0;
	do{

	cout << "Diga el número tope de la aproximación ";
	cin >> tope; 

	}while (tope < COTA_MINIMA || tope > COTA_MAXIMA);

	for (int i = 0; i < tope; i += 2){
		formula_positiva = 1 / (2*i + 1);
		for (int j = 0; j < 2*i + 1; j++){
			formula_exponente = 1/sqrt(3);
			total_exponente *= formula_exponente; 
		} 
		total += formula_positiva * total_exponente;
	}

	/*for (int i = 1; i < tope; i += 2){
		formula_negativa = -1 / (2*i + 1);
		for (int j = 0; j < 2*i + 1; j++){
			formula_exponente = 1/sqrt(3);
			total_exponente *= formula_exponente; 
		} 
		total_negativo += formula_negativa * total_exponente;
	}
	total = total_positivo + formula_negativa;
*/
	cout << total * POR_PI_PARTIDO << endl;
	
}