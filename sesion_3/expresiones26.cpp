/*

	Programa en el cual usamos variables booleanas para verificar las diferentes expresiones lógicas

*/
#include <iostream>

using namespace std;

int main(){

	char letra;
	bool letra_ok;
	int edad;
	bool edad_ok;
	int anio;
	bool bisiesto_ok;
	int adivine;
	bool adivine_ok;

	cout << "Indique la letra, la edad y el año a comprobar: ";
	cin >> letra >> edad >> adivine >> anio;

	 letra_ok = letra >= 'a' && letra <= 'z';
	 edad_ok = edad >= 65 || edad <= 18;
	 bisiesto_ok = anio%4 == 0 && anio%100 != 0 || anio%400 == 0;
	 adivine_ok = adivine <= 100 && adivine >= 1;

	 cout << letra_ok << " " << edad_ok << " " << adivine_ok << " " << bisiesto_ok << endl;

}