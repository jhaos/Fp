/*

	En este programa se va a calcular el margen de error de los radares, tanto fijos como moviles.

*/

#include <iostream>
#include <string>

using namespace std;

const double IND_ERROR_INFERIOR = 1 - 5.0/100.0;
const double IND_ERROR_SUPERIOR = 1 - 7.0/100.0;
const int MARGEN_INFERIOR = 5;
const int MARGEN_SUPERIOR = 7;
const char FIJO = 'F'; 
const char MOVIL = 'M';
const int LIMITE_TIPO_MULTA = 100;

int main(){

	double velocidad;
	double velocidad_total = 0, velocidad_anterior = 0;
	char radar;
	string vehiculo, vehiculo_maxima_multa;

	cout << "Indica la matricula del coche, el tipo de radar, F para fijos y M para móviles, y la velocidad del conductor: ";
	cin >> vehiculo;

	while (vehiculo != "#"){

		 cin >> radar >> velocidad;
		if (radar == FIJO){
			if (velocidad <= LIMITE_TIPO_MULTA){
				velocidad_total = velocidad - MARGEN_INFERIOR;
			}else{
				velocidad_total = velocidad * IND_ERROR_INFERIOR;
			}
		}else if (radar == MOVIL){
			if (velocidad <= LIMITE_TIPO_MULTA){
				velocidad_total = velocidad - MARGEN_SUPERIOR;
			}else{
				velocidad_total = velocidad * IND_ERROR_SUPERIOR;
			}
		}
		if(velocidad > velocidad_anterior){
			vehiculo_maxima_multa = vehiculo;
			velocidad_anterior = velocidad_total;
		}

		cin >> vehiculo;

	}
	velocidad = velocidad_anterior;

	cout << "La velocidad total del coche: "<< vehiculo_maxima_multa << " es: " << velocidad << endl;
}