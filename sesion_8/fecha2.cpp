/*

	Programa que indica si un conjunto de fechas son correctas o no

*/



#include <iostream>

using namespace std;

int main(){
	int num_meses = 12;
	int num_dias_diferentes = 3;
	int vector_dias[num_meses];
	int vector_meses[num_meses];
	int vector_anio[num_meses];
	int dia, mes, anio;
	int i = 0;
	bool fecha_ok = false;
	bool dias_ok;
	cin >> dia;

	while(dia != -1){
		
		vector_dias[i] = dia;
		cin >> mes;
		vector_meses[i] = mes;
		cin >> anio;
		vector_anio[i] = anio;
		cin >> dia;
		i++;
	}

	
	
	for(int j = 0; j < i; j++){
		if (vector_meses[j] > 0 && vector_meses[j] < 13){

			dias_ok = vector_dias[j] > 0;
			bool bisiesto_ok = (vector_anio[j]%4 == 0 && vector_anio[j]%100 != 0) || vector_anio[j]%400 == 0;

			if (bisiesto_ok){
				if (vector_meses[j] == 2){
					if(dias_ok && vector_dias [j] <= 29){
						fecha_ok = true;
					}
				}
			}else{
				if (vector_meses[j]%2 == 0 && vector_meses[j] != 2 && vector_meses[j] != 8){
					if (dias_ok && vector_dias[j] < 31) {
						fecha_ok = true;
					}
				}else if (vector_meses[j]%2 == 1 || vector_meses[j] == 8){
					if (dias_ok && vector_dias[j] <= 31){
						fecha_ok = true;
					}
				}
			}
		}

		if (fecha_ok){
			cout << "Ok" << endl;
		}else{
			cout << "No" << endl;
		}

		fecha_ok = false;
	}
}
		
