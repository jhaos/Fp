/*

	Problema de las tarifas usando condicionales y un descuento sobre el descuento teniendo control sobre la introduccion del valor de las variables

*/
#include <iostream> 

using namespace std;

const int INDICE_MINIMO_PARA_DESCUENTO = 300;
const double INCREMENTO = 0.1;
const int BASE = 150;
const double IND_DESC_MAXIMO = 1 - 4.0/100.0;
const double IND_DESC_MINIMO = 1 - 2.0/100.0;
const double IND_DESC_INTERMEDIO = 1 - 3.0/100.0;
const int LIMITE_SUPER_DESCUENTO = 700;
const int LIMITE_DESCUENTO_PUNTOS_PEQUENIO = 100;
const int LIMITE_DESCUENTO_PUNTOS_GRANDE = 200;
const int MIN_PUNTOS_INTRO = 0;
const int MAX_PUNTOS_INTRO = 400;
const int MIN_KILOMETROS = 0;

int main(){
	
	double intermedio, final_2, descuento = 0;
	int kilometros, num_puntos;
	int kilometros_de_mas;
	bool condicion_1, condicion_2;

	cout << "Introduzca el número de kilometros y los puntos que tiene: ";
	cin >> kilometros;

	while (kilometros <= MIN_KILOMETROS){			/////////////////////// MEJOR USAR DO WHILE PARA NO REPETIR EL CODIGO DE LAS ENTRADAS
		cin >> kilometros;
	}

	cin >> num_puntos;

	while (num_puntos < MIN_PUNTOS_INTRO || num_puntos > MAX_PUNTOS_INTRO){
		cin >> num_puntos;
	}


	intermedio = BASE;
	kilometros_de_mas = kilometros - INDICE_MINIMO_PARA_DESCUENTO;

	condicion_1 = kilometros > LIMITE_SUPER_DESCUENTO;
	condicion_2 = num_puntos > LIMITE_DESCUENTO_PUNTOS_PEQUENIO && num_puntos < LIMITE_DESCUENTO_PUNTOS_GRANDE;
	final_2 = intermedio;
	

	if (kilometros > INDICE_MINIMO_PARA_DESCUENTO){
		intermedio += INCREMENTO*kilometros_de_mas;
	}
	if (condicion_1){
		descuento = descuento + (intermedio - intermedio * IND_DESC_MINIMO);	
	}
	if (condicion_2){
		descuento = descuento + (intermedio - intermedio * IND_DESC_INTERMEDIO);	
	}
	if (num_puntos > LIMITE_DESCUENTO_PUNTOS_GRANDE){
		descuento = descuento + (intermedio - intermedio * IND_DESC_MAXIMO);
	}
	
	final_2 = intermedio - descuento;
	cout << "El precio final con los incrementos de distancia es " << final_2 << endl;


	return 0;
// hay que separar el calculo de la tarifa en cada if y hacerlo al final una vez esten todos los descuentos calculados, se repite mucho codigo

}