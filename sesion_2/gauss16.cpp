/*

	Cálculo de la función de Gauss

*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 

const double PI=6*asin(0.5);
int main(){                    // Programa Principal

	double coeficiente_u;               // Declara variables para guardar
   double coeficiente_o;
	double variable_x;
	double gaussiana;
	               
   
	
   cout << "Introduzca el coeficiente real u ";
   cin >> coeficiente_u;
   cout << "Introduzca el coeficiente real o ";
   cin >> coeficiente_o;
   cout << "Introduzca el número de la variable x ";
   cin >> variable_x;
   
   gaussiana= (1/(coeficiente_o*(sqrt (2*PI))))*exp(-0.5*pow((variable_x-coeficiente_u)/coeficiente_o, 2)); //Formula de la función de Gauss
   
   
	        
		     
	cout << "El resultado de la funcion gaussiana con esos valores es " << gaussiana << endl;

   return 0;
}
