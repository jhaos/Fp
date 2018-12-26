
#include <iostream>
#include <cmath>

using namespace std;

int potencia (double a_elevar, int num_potencia){
	double potencia = 1;
	double resultado;

	while (num_potencia > 0){
		potencia *= a_elevar;
		num_potencia--;
	}

	return potencia;
}

double redondear(double numero, int decimal){
	int elevar;
	double a_redondear;
	double redondeado;

	elevar = potencia (10, decimal);
	a_redondear = round(numero * elevar);
	redondeado = a_redondear / elevar;

	return redondeado;
}

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

	redondeado = redondear(numero, decimal);

	cout << "El numero redondeado es: " << redondeado << endl;

	return 0;
}