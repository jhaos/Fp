/*

	Cálculo de la función de Gauss con filtros y varios valores entre minimo y maximo con incremento

*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 

const double PI = 6*asin(0.5);
const double DOBLE_DE_PI = 2*PI;
int main(){                    // Programa Principal

	double coeficiente_esperanza_u;               // Declara variables para guardar
   double coeficiente_desvi_tipica_o;
	double variable_x;
	double gaussiana;
	double min, max, incremento;
	               
   
	
   cout << "Introduzca el coeficiente real u ";
   cin >> coeficiente_esperanza_u;
   cout << "Introduzca el coeficiente real o ";
   cin >> coeficiente_desvi_tipica_o;

   while (coeficiente_desvi_tipica_o <= 0){
   	cin >> coeficiente_desvi_tipica_o;
   }
   
   cout << "Introduzca un valor mínimo ";
   cin >> min;
   cout << "Introduzca un valor máximo ";
   cin >> max;

   while (max <= min){    /// UTILIZAR MEJOR UN DO WHILE
   	cin >> max;
   }

   cout << "Introduzca incremento ";
   cin >> incremento;         //// UTILIZAR MEJOR DO WHILE
	
	variable_x = min;

   do{ //////MEJOR USAR WHILE
   
   gaussiana= (1/(coeficiente_desvi_tipica_o*(sqrt (DOBLE_DE_PI))))*exp(-0.5*pow((variable_x-coeficiente_esperanza_u)/coeficiente_desvi_tipica_o, 2)); //Formula de la función de Gauss
   variable_x += incremento;
   
	cout << "El resultado de la funcion gaussiana con esos valores es " << gaussiana << endl;

	}while (variable_x <= max);     


		     

   return 0;
}
