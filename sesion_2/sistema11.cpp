/*

	En este programa calcularemos la equivalencia entre las diferentes medidas de longitud

*/

#include <iostream>

using namespace std;

int main(){

	/* 
		Inicializacion de variables en metros
	*/
	
	double pulgada = 0.0254, total_pulgada;
	double pie = 0.3048, total_pie;
	double yarda = 0.9144, total_yarda;
	double milla = 1609.344, total_milla;
	double marina = 1852, total_marina;
	double n_metros;

	cout << "Diga una medida expresada en metros: ";
	cin >> n_metros;
	
	total_pulgada = n_metros / pulgada; 
	total_pie = n_metros / pie;
	total_yarda = n_metros / yarda;
	total_milla = n_metros / milla;
	total_marina = n_metros / marina;

	cout << "total pulgadas: " <<total_pulgada << endl;
	cout << "total pie: " <<total_pie << endl;
	cout << "total yarda: " <<total_yarda << endl;
	cout << "total milla: " <<total_milla << endl;
	cout << "total millas marinas: " <<total_marina << endl;

}