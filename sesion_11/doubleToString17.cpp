#include <iostream>
#include <string>
#include <cmath>
#include "string.h"

using namespace std;


int potencia (double a_elevar, int num_potencia){
	double potencia = 1;
	double resultado;

	while (num_potencia > 0){
		potencia *= a_elevar;
		num_potencia--;
	}

	return potencia;
	}

	double redondear(double numero, int decimal){
		int elevar;
		double a_redondear;
		double redondeado;

		elevar = potencia (10, decimal);
		a_redondear = round(numero * elevar);
		redondeado = a_redondear / elevar;

		return redondeado;
	}

	void EliminaUltimos(string& cadena, char a_borrar){
		int contador;

		contador = cadena.length();

		while (cadena[--contador] == a_borrar){		
			cadena.pop_back();
		}

	}

class Convertidor{
	private:
		string del_izq;
		string del_der;
		string transformado;
		char separador;
		int decimal;
		double numero;

	public:

		Convertidor (int dec, double num){
			del_izq = "<<";
			del_der = ">>";
			separador = '.';
			decimal = dec;
			transformado = "";
			numero = num;
		}

		Convertidor (string izq, string der, char sep, int dec, string trans){
			del_izq = izq;
			del_der = der;
			separador = sep;
			decimal = dec;
			transformado = trans;
		}



		void doubleToString(){
			double redondeado;
			string cadena_double;
			const char a_borrar = '0';
	
			redondeado = redondear(numero, decimal);
			cadena_double = to_string(redondeado);
			EliminaUltimos(cadena_double, a_borrar);

			transformado = cadena_double;
		}

		string getIzq(){
			return del_izq;
		}


		string getDer(){
			return del_der;
		}


		string getTrans(){
			return transformado;
		}

		int getDecimal(){
			return decimal;
		}

		char getSeparador(){
			return separador;
		}

};

int main (){

	double numero;
	int decimal;
	double redondeado;
	string cadena_final;

	cout << "Indique el numero decimal a redondear: ";
	cin >> numero;
	cout << "Dime que decimal hay que redondear: ";
	cin >> decimal;

	Convertidor cambio (decimal, numero);

	cambio.doubleToString();

	cout << cambio.getIzq() << cambio.getTrans() << cambio.getDer() << endl;

	return 0;



}