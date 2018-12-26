/*

	Problema de las distancias incluyendo altura

*/
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 6 * asin(0.5);
const double TO_RADIANES = PI / 180;
const double MITAD = 1.0/2.0;
const int DOBLE = 2;
const double R = 6372797.560856;

int main(){
	cout.precision(15);
	double grados_lon_1, grados_lat_1, alt_1;
	double grados_lon_2, grados_lat_2, alt_2;
	double rad_lon_1, rad_lat_1;
	double rad_lon_2, rad_lat_2;
	double inc_lon, inc_lat;
	double seno_cuadrado_lat, raiz_a;
	double seno_cuadrado_lon;
	double a, c, dp, dr, minimo, diferencia_alturas;
	
	cout << "Introduce latitud 1, longitud 1, altura 1, latitud 2, longitud 2, altura 2: ";
	cin >> grados_lat_1 >> grados_lon_1 >> alt_1 >> grados_lat_2 >> grados_lon_2 >> alt_2;

	rad_lon_1 = grados_lon_1 * TO_RADIANES;
	rad_lat_1 = grados_lat_1 * TO_RADIANES;
	rad_lon_2 = grados_lon_2 * TO_RADIANES;
	rad_lat_2 = grados_lat_2 * TO_RADIANES;

	inc_lon = rad_lon_2 - rad_lon_1;
	inc_lat = rad_lat_2 - rad_lat_1;

	seno_cuadrado_lat = pow(sin(MITAD*inc_lat),2);
	seno_cuadrado_lon = pow(sin(MITAD*inc_lon),2);

	a = seno_cuadrado_lat + cos(rad_lat_1)*cos(rad_lat_2) * seno_cuadrado_lon;
	minimo = 1;
	raiz_a = sqrt(a);

	if (raiz_a < minimo){
		minimo = raiz_a;
	}

	c = DOBLE * asin(minimo);
	dp = R * c;
	diferencia_alturas = alt_1 - alt_2;
	dr = sqrt(pow(dp,2) + pow(diferencia_alturas,2));


	cout << "El total dp es: " << dp << " y el dr es: " << dr << endl;

}