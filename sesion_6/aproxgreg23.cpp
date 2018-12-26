/*

	Cálculo de la aproximación de PI usando Gregory

*/


#include <iostream>
#include <cmath>
using namespace std;

const int COTA_MAXIMA = 100000;
const int COTA_MINIMA = 0;
const int DIVISOR_PI_APROXIMACION = 4;

int main(){

	cout.precision(15);

	int tope;
	double calculo = 0, calculo_sin_pow = 0, calculo_sin_pow_2 = 0;
	double formula, formula_2, formula_3;

	do{

	cout << "Diga el número tope de la aproximación ";
	cin >> tope; 

	}while (tope < COTA_MINIMA || tope > COTA_MAXIMA);
		
	for (int i = 0; i <= tope; i++){
		formula = pow(-1,i) / (2*i + 1);
		calculo += formula;
	}
	
	for (int i = 0; i <= tope; i++){
		
		if (i%2 == 1){								//MIRAR ESTO DE NUEVO FALTA LA SEGUNDA PARTE
			formula_2 = 1 / (2*i + 1.0);
			calculo_sin_pow -= formula_2;
		}else if (i%2 == 0){
			formula_2 = 1 / (2*i + 1.0);
			calculo_sin_pow += formula_2;
			
		}
	}
	
	calculo *= DIVISOR_PI_APROXIMACION;
	calculo_sin_pow *= DIVISOR_PI_APROXIMACION;

	cout << calculo << endl;
	cout << calculo_sin_pow << endl;

	
}