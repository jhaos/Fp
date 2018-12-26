/*

	En el programa se introduce una letra mayuscula e imprimimos su correspondiente letra en minúscula

*/

#include <iostream>

using namespace std;

const int CAMBIO = 32;

int main(){

	char caracter;

	cout << "Introduzca la letra mayúscula: ";
	cin >> caracter;

	caracter = caracter + CAMBIO;

	cout << caracter << endl;
}