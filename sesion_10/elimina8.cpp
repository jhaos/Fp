#include <iostream>
#include <string>
#include "string.h"
using namespace std;

const char TERMINADOR = '#';

void EliminaUltimos(string& cadena, char a_borrar){
	int contador;

	cadena.pop_back();

	contador = cadena.length();

	while (cadena[--contador] == a_borrar){
		cadena.pop_back();
	}

}
	

int main(){
	char caracter = ' ', a_borrar;
	string cadena;

	while (caracter != TERMINADOR){
		cin.get(caracter);
		cadena += caracter;
	
	}

	cin.get(a_borrar);

	EliminaUltimos(cadena, a_borrar);

	cout << cadena ;
}