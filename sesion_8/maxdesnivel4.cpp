/*

	Calcula el desnivel de un conjunto de números

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int num_datos;
	int dato;
	int maximo_desnivel = 0, desnivel;
	int acumulacion_positivos = 0;
	
	cin >> num_datos;

	int vector[num_datos];

	for (int i = 0; i < num_datos; i++){
		cin >> dato;

		vector[i] = dato;
	}

	for (int i = 1; i < num_datos; i++){
		desnivel = vector[i] - vector[i-1];

		if(desnivel > 0){
			acumulacion_positivos += desnivel;
		}

		desnivel = abs(desnivel);

		if(desnivel > maximo_desnivel){
			maximo_desnivel = desnivel;
		}
	}

	if(num_datos <= 1){
		cout << "No hay datos suficientes" << endl;
	}else{
		cout << "Desnivel: " << maximo_desnivel << " acumulacion: " << acumulacion_positivos << endl;
	}
}