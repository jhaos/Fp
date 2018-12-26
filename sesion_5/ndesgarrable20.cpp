/*

	Dice si un numero introducido es desgarrable o no utilizando bucles y condicionales

*/

#include <iostream>
#include <cmath>

using namespace std;

const int MULTIPLICADOR = 10;

int main(){

	bool es_desgarrable = false;
	long int n, n_cifras = 0;
	long int modulo = 100;
	bool condicion_desgarrable;

	cout << "Introduce n ";
	cin >> n;

	while (n/modulo != 0){
		n_cifras++;
		modulo *= MULTIPLICADOR; 
	}

	modulo /= MULTIPLICADOR;
	
	while (n_cifras > 0 || !es_desgarrable){
		if (pow(n/modulo + n%modulo,2) == n){
			es_desgarrable = true;
		}
			n_cifras--;
			modulo /= MULTIPLICADOR;
	}

	cout << " 1 si es desgarrable, 0 si no lo es: " << es_desgarrable << endl;

}