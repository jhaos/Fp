/*

	Vamos a calcular la distancia euclídea entre dos puntos

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x_1, x_2;
	double y_1, y_2;
	double distancia_euclides;
	double cuadrado_x;
	double cuadrado_y;
	double total_distancia;

	cout << "Indique los puntos de la primera coordenada: ";
	cin >> x_1;
	cin >> y_1;
	cout << "Indique los puntos de la segunda coordenada: ";
	cin >> x_2	;
	cin >> y_2;

	cuadrado_x = (x_1 - x_2);
	cuadrado_x = cuadrado_x * cuadrado_x;
	cuadrado_y = (y_1 - y_2) * (y_1 - y_2);

	cout << cuadrado_x << endl;
	cout << cuadrado_y << endl;
	
	total_distancia = sqrt(cuadrado_x + cuadrado_y);


	cout << "La distancia total es: " << total_distancia << endl;





}