/*

	Convertir letras mayúsculas a minúsculas o viceversa a no ser que sea un símbolo

*/
#include <iostream>

using namespace std;

const int DIFERENCIA_MAYUS_Y_MINUS = 'a' - 'A';
const int MAYUSCULA_PRINCIPIO = 'A';
const int MAYUSCULA_FINAL = 'Z';
const int MINUSCULA_PRINCIPIO = 'a';
const int MINUSCULA_FINAL = 'z';

enum TipoLetra{
	MAYUSCULA, MINUSCULA, CARACTER
};

int main(){


	char letra;
	bool condicion_letra_mayuscula;
	bool condicion_letra_minuscula;
	bool condicion_no_letra;
	char letra_convertida;
	TipoLetra tipo_letra;

	cout << "Diga la letra a convertir ";
	cin >> letra;

	letra_convertida = letra;
	condicion_letra_mayuscula = letra <= MAYUSCULA_FINAL && letra >= MAYUSCULA_PRINCIPIO;
	condicion_letra_minuscula = letra <= MINUSCULA_FINAL && letra >= MINUSCULA_PRINCIPIO;
	//condicion_no_letra = (letra > MAYUSCULA_FINAL && letra < MINUSCULA_PRINCIPIO) || (letra < MAYUSCULA_PRINCIPIO && letra > MINUSCULA_FINAL); PREGUNTAR

	if (condicion_letra_mayuscula){
		tipo_letra = MINUSCULA;
		letra_convertida = letra + DIFERENCIA_MAYUS_Y_MINUS;
	}else if (condicion_letra_minuscula){
		tipo_letra = MAYUSCULA;
		letra_convertida = letra - DIFERENCIA_MAYUS_Y_MINUS;
	}else{
		tipo_letra = CARACTER;
	}

	if (tipo_letra == MINUSCULA){
		cout << "La letra era una letra mayúscula una vez convertida es: " << letra_convertida << endl;
	}else if (tipo_letra == MAYUSCULA){
		cout << "La letra era una letra minúscula una vez convertida es: " << letra_convertida << endl;
	}else{
		cout << "El carácter no era una letra por lo que el caracter resultantes es: "<< letra_convertida << endl;	
	}


	
}