/*

	En este programa realizaremos el calculo de la diferencia entre dos tiempos distintos.

*/

#include <iostream>

using namespace std;
const int MINUTOS = 60;
const int SEGUNDOS = MINUTOS * MINUTOS;

int calculoIntervalo (int tiempo_1, int tiempo_2){

	int diferencia = tiempo_2 - tiempo_1;

	return diferencia;
}

int tiempoTotal (int hora, int min, int seg){
	int tiempo_total;
	tiempo_total = hora*SEGUNDOS + min*MINUTOS + seg;

	return tiempo_total;
}

int main(){
	int hora1, minuto1, segundo1;
	int hora2, minuto2, segundo2;
	int tiempo_total;
	int total_tiempo1, total_tiempo2;

	cout << "Introduzca el primer momento del dia en horas(0-23), minutos(0-59) y segundos(0-59)";
	cin >> hora1;
	cin >> minuto1;
	cin >> segundo1;
	cout << "Introduzca el segundo momento del dia en horas(0-23), minutos(0-59) y segundos(0-59)";
	cin >> hora2;
	cin >> minuto2;
	cin >> segundo2;

	total_tiempo1 = tiempoTotal(hora1, minuto1, segundo1);
	total_tiempo2 = tiempoTotal(hora2, minuto2, segundo2);
	tiempo_total = calculoIntervalo(total_tiempo1, total_tiempo2);

	int tiempo_min = tiempo_total / MINUTOS;
	cout << "El tiempo total es: " << tiempo_total << " " << tiempo_min << endl;


	return 0;
}