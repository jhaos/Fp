/*

	En este programa realizaremos el calculo de la diferencia entre dos tiempos distintos.

*/

#include <iostream>

using namespace std;


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

	total_tiempo1 = hora1*3600 + minuto1*60 + segundo1;
	total_tiempo2 = hora2*3600 + minuto2*60 + segundo2;
	tiempo_total = total_tiempo2 - total_tiempo1;

	cout << "El tiempo total es: " << tiempo_total << endl;


	return 0;
}