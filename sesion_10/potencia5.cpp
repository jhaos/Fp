#include <iostream>

using namespace std;


int potencia(int a_elevar, int num_potencia){

	int potencia = 1;
	int resultado;

	while (num_potencia > 0){
		potencia *= a_elevar;
		num_potencia--;
	}
	

	return potencia;
}

int main (){

	int numero_a_elevar;
	int potencial;
	int cuadrado;
	

	cin >> numero_a_elevar;
	cout << "paso a_elevar"<< endl;
	cin >> potencial;
	cout << "paso potencial " << endl;

	cuadrado = potencia(numero_a_elevar, potencial);

	cout << cuadrado;
}