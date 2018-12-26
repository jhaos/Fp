/* 

	En este programa se realiza una aplicación de interés a un capital introducido


*/

#include <iostream>

using namespace std;


int main(){
	double total;
	double capital;
	double interes;

	cout << "Introduzca del capital: ";
	cin >> capital;
	cout << "Introduzca del interes: ";
	cin >> interes;

	total = capital + capital * interes/100;
	capital = capital + capital * interes/100;

	cout << "El capital que ha obtenido con el interes: " << interes << " es: " << total << endl;
	cout << "El capital con variable capital es: " << capital << endl;	

	/* 

		Como se puede ver en la ejecución se podría utilizar la misma variable 
		capital para almacenar el valor del total pero esto puede llevar a confusión 
		ya que se mezclan el valor total de la operación con el del capital usado 
		al principio por lo en un programa mas extenso el valor principal se pierde al
		realizar esta asignación

		*/


	return 0;
}