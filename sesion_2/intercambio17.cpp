#include <iostream>

using namespace std;

int main(){
	double numero_1, numero_2, numero_3;
	double intercambiador;

	cout << "Indique el valor de tres números: ";
	cin >> numero_1 >> numero_2 >> numero_3;

	intercambiador = numero_3;
	numero_3 = numero_2;
	numero_2 = numero_1;
	numero_1 = intercambiador;

	cout << numero_1 << " " << numero_2 << " " << numero_3 << endl;
	



}