/*

	En este programa se implementa el tipo de cifrado usado en la época del Imperio Romano a partir de una letra mayúscula y una clave de cifrado.

*/

#include <iostream>

using namespace std;

const int ULTIMA_LETRA = 90;
const int PRIMERA_LETRA = 65;

main(){
	int minimo, maximo;
	int clave;
	char letra;
	char cifrado, cifrado_final;

	cout << "Introduzca una letra y una clave para cifrarla: ";
	cin >> letra;
	cin >> clave;

	maximo = ULTIMA_LETRA - PRIMERA_LETRA;
	minimo = letra - PRIMERA_LETRA ;

	cifrado = (clave + minimo);
	cifrado = cifrado % (maximo+1);
	cifrado_final = PRIMERA_LETRA + cifrado;

	cout << cifrado_final << " " << letra << endl;




}