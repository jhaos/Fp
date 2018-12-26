/*

	Problema de codificación usando condicionales simples

*/
#include <iostream>

using namespace std;

const int PRIMERA_LETRA = 'A';
const int ULTIMA_LETRA = 'Z';
const int UNIDAD = 1;

int main(){
	char letra;
	int clave;
	int diferencia;					//Para calcular el exceso al dar una vuelta con la clave
	char codificado;					//Se almacena la sumatoria de la letra y la clave
	char descodificado;							

	cout << "Introduzca una letra y una clave para codificarla: ";
	cin >> letra >> clave;

	codificado = letra + clave;
	descodificado = codificado - clave;

	if(codificado > ULTIMA_LETRA){
		diferencia = clave - (ULTIMA_LETRA-letra) - UNIDAD;
		codificado = PRIMERA_LETRA + diferencia;
	}
	if(descodificado < PRIMERA_LETRA){
		diferencia =  ULTIMA_LETRA - PRIMERA_LETRA - UNIDAD - clave;
		descodificado = PRIMERA_LETRA + diferencia;

	}


	cout << codificado << " " << descodificado << endl;
}