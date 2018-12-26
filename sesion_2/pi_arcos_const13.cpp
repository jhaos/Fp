/*

Vamos a calcular el valor del número real pi a partir del la fórmula pi / d = arco-sen(a)
Usando constantes

*/

#include <cmath>
#include <iostream>

using namespace std;

const double DENOMINADOR = 6;
const double ANGULO = 0.5; 
int main(){
	
	double resultado_pi;
	
	resultado_pi = DENOMINADOR * asin(ANGULO);
	
	cout << "El resultado de la operacion es: " << resultado_pi << endl;
	
	
	
	return 0;	
}
