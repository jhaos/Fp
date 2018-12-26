#include <iostream>

using namespace std;

int leeMayorQue (int a_superar){
	int mayor_que;
	do{

		cin >> mayor_que;

	}while(mayor_que < a_superar);

	
	return mayor_que;
}

int leeIntRango(int max, int min){

	int intermedio = 0;

	do{
		cin >> intermedio;

	}while (intermedio > max || intermedio < min);

	return intermedio;
}

int main (){

	int numero_a_superar;
	int max, min;
	int intermedio;
	int suma = 0;

	cin >> min;


	max = leeMayorQue(min);
	
	for (int i = 0; i < 3; i++){
		intermedio = leeIntRango (max, min);
		suma += intermedio;
	}
	cout << suma;
}