/*

	Vamos a calcular el valor de la variable 'a' a partir de dos coordenadas geométricas

*/

#include <iostream>
#include <cmath>

using namespace std;


const double PI = 6 * asin(0.5);
const double TO_RADIANES = PI / 180;
const double MITAD = 1.0/2.0;

int main(){

	double grados_lon_1, grados_lat_1;
	double grados_lon_2, grados_lat_2;
	double rad_lon_1, rad_lat_1;
	double rad_lon_2, rad_lat_2;
	double a;
	double seno_cuadrado_lat;
	double seno_cuadrado_lon;
	
	cout << "Introduce longitud 1, latitud 1, longitud 2 y latitud 2: ";
	cin >> grados_lat_1 >> grados_lon_1 >> grados_lat_2 >> grados_lon_2;

	rad_lon_1 = grados_lon_1 * TO_RADIANES;
	rad_lat_1 = grados_lat_1 * TO_RADIANES;
	rad_lon_2 = grados_lon_2 * TO_RADIANES;
	rad_lat_2 = grados_lat_2 * TO_RADIANES;
	
	seno_cuadrado_lat = pow(sin(MITAD*(rad_lat_2 - rad_lat_1)),2);
	seno_cuadrado_lon = pow(sin(MITAD*(rad_lon_2 - rad_lon_1)),2);

	a = seno_cuadrado_lat + cos(rad_lat_1)*cos(rad_lat_2) * seno_cuadrado_lon;

	cout << "El total es: " << a << endl;



}