/*

	En este programa se comprar si dos números tienen el mismo signo

*/

#include <iostream>

using namespace std;

int main(){
	int numero_1, numero_2;
	bool mismo_signo, situacion_1, situacion_2, situacion_3, situacion_4;
	bool mismo_signo_division;
	double signo_positivo_division, signo_negativo_division;

	cout << "Indica los números a comparar: ";
	cin >> numero_1 >> numero_2;
	
	situacion_1 = numero_1 > 0 && numero_2 > 0; //&& (
	situacion_2 = numero_1 < 0 && numero_2 < 0;
	situacion_3 = numero_1 > 0 && numero_2 < 0;
	//situacion_4 = numero_1 < 0 && numero_2 > 0;
	mismo_signo = (numero_1 > 0 && numero_2 > 0) || (numero_1 < 0 && numero_2 < 0);
	signo_positivo_division = numero_1 / numero_2*1.0 > 0;
	signo_negativo_division = numero_1 / numero_2*1.0 < 0;

	if (situacion_1){
		cout << "Son iguales, situacion 1" << endl;
	}else if (situacion_2){
		cout << "Son iguales, situacion 2" << endl;
	}else if (situacion_3){
		cout << "Son diferentes, situacion 3" << endl;
	}else{
		cout << "Son diferentes, situacion 4" << endl;
	}


	if (mismo_signo){
		cout << "Tienen el mismo signo, condicion mismo_signo" << endl;
	}else{
		cout << "No tienen el mismo signo, condicion mismo_signo" << endl;
	}

	if (signo_positivo_division){
		cout << "Tienen el mismo signo sin operadores logicos" << endl;
	}else if (signo_negativo_division){
		cout << "No tienen el mismo signo sin operadores logicos" << endl;
	}

	cout << mismo_signo << ": Si sale 1 = mismo signo. 0 = distinto signo" << endl;






}

