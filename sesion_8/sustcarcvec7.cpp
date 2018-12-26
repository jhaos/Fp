
#include <iostream>

using namespace std;

int main(){

	char vector_inicial[20];
	char vector_nuevo[20];
	char vector_sustituto[60];
	char letra;
	int contador_relleno = 0, contador_relleno_nuevo = 0;
	int contador_inicial = 0, contador_nuevo = 0;
	cin >> letra;

	while (letra != '#'){
		vector_inicial[contador_inicial] = letra;
		cin >> letra;
		contador_inicial++;
	}

	cin >> letra;

	while (letra != '#'){
		vector_nuevo[contador_nuevo] = letra;
		cin >> letra;
		contador_nuevo++;
	}

	cin >> letra;

	for (int i = 0; i < 60; i++){
		vector_sustituto[contador_relleno] = vector_inicial[i];
		if(vector_inicial[i] == letra){
			while(contador_nuevo > 0){
				vector_sustituto[i] = vector_nuevo[contador_relleno_nuevo];
				contador_relleno_nuevo++;
			}
			contador_relleno += contador_nuevo;
			contador_relleno_nuevo = 0;
		}
	}
	for (int i = 0; i < 60; i++)
		cout << vector_sustituto[i];	
}
