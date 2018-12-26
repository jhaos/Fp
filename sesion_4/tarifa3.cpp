/*

	Problema de las tarifas usando condicionales

*/
#include <iostream> 

using namespace std;

const int TOPE = 300;
const int BASE = 150;
const double INCREMENTO = 0.1;

int main(){
	double final;
	int kilometros;
	int kilometros_de_mas;

	cout << "Introduzca el número de kilometros: ";
	cin >> kilometros;

	final = BASE;
	kilometros_de_mas = kilometros - TOPE;

	if (kilometros > TOPE)
	final = BASE + INCREMENTO*kilometros_de_mas;

	cout << "El precio final con los incrementos de distancia es " << final << endl;


	return 0;


}