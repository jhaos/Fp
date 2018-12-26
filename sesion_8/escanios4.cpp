/*

	reparticion de escaños en españa

*/

#include <iostream>
#include <string.h>

using namespaces std;

int main(){
	int total_escanios;
	int num_partidos;
	int escanios_partido;
	int max_votos = 0;
	int indice_maximo;
	
	cin >> total_escanios;
	cin >> num_partidos;

	int vector_partidos[num_partidos];
	int vector_escanios[num_partidos] = {0};

	for (int i = 0; i < num_partidos; i++){
		cin >> escanios_partido;

		vector_partidos[i] = escanios_partido;
	}

	for (int i = 0; i < total_escanios; i++){
		for (int j = 0; j < num_partidos; j++){
			if (vector_partidos[j] > max_votos){
				max_votos = vector_partidos[j];
				indice_maximo = j;
			}
		}
	}





}