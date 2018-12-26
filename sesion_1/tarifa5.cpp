/*

	Se va a calcular el precio de un vuelo a partir de una base y un incremento por
	kilometro recorrido

*/

#include <iostream>

using namespace std;

int main(){
	int base = 150;
	double incremento = 0.1;
	double final;
	int kilometros;

	cout << "Introduzca el número de kilometros: ";
	cin >> kilometros;

	final = base + kilometros*incremento;

	cout << "El precio final con los incrementos de distancia es " << final << endl;


	return 0;

}