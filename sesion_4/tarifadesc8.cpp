/*

	Problema de las tarifas usando condicionales y un descuento sobre el descuento

*/
#include <iostream> 

using namespace std;

const int TOPE = 300;
const double INCREMENTO = 0.1;
const int BASE = 150;
const double IND_DESC_4 = 1 - 4.0/100.0;
const double IND_DESC_2 = 1 - 2.0/100.0;
const double IND_DESC_3 = 1 - 3.0/100.0;

int main(){
	
	double final, final_2;
	int kilometros, num_puntos;
	int kilometros_de_mas;
	bool condicion_1, condicion_2;
	cout << "Introduzca el número de kilometros y los puntos que tiene: ";
	cin >> kilometros >> num_puntos;

	final = BASE;
	kilometros_de_mas = kilometros - TOPE;

	condicion_1 = kilometros > 700;
	condicion_2 = num_puntos > 100 && num_puntos < 200;
	final_2 = final;
	
	if (kilometros > TOPE){
		final = BASE + INCREMENTO*kilometros_de_mas;
		final_2 = final;
	}
	if (condicion_1){
		final_2 = final * IND_DESC_2;
	}
	if (condicion_2){
		final_2 = final * IND_DESC_3 - (final-final_2);	
	}
	if (num_puntos > 200){
		final_2 = final * IND_DESC_4 - (final-final_2);
	}
	cout << "El precio final con los incrementos de distancia es " << final_2 << endl;


	return 0;
// hay que separar el calculo de la tarifa en cada if y hacerlo al final una vez esten todos los descuentos calculados, se repite mucho codigo

}