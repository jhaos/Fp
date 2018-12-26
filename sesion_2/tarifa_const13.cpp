/*

	Se va a calcular el precio de un vuelo a partir de una base y un incremento por
	kilometro recorrido utilizando constantes

*/

#include <iostream>

using namespace std;

const double INCREMENTO = 0.1;
const double BASE = 150;

int main(){
	double final;
	int kilometros;

	cout << "Introduzca el número de kilometros: ";
	cin >> kilometros;

	final = BASE + kilometros*INCREMENTO;

	cout << "El precio final con los incrementos de distancia es " << final << endl;


	return 0;

}