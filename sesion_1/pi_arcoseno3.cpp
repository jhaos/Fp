/*

Vamos a calcular el valor del n�mero real pi a partir del la f�rmula pi / d = arco-sen(a)

*/

#include <cmath>
#include <iostream>

using namespace std;

int main(){
	
	double denominador = 6;
	double angulo = 0.5;
	double resultado_pi;
	
	resultado_pi = denominador * asin(angulo);
	
	cout << "El resultado de la operacion es: " << resultado_pi << endl;
	
	
	
	return 0;	
}
